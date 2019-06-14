#ifndef __HLIST_H_
#define __HLIST_H_

#include <boost/any.hpp>
#include <boost/hana.hpp>
#include <iostream>

namespace hana = boost::hana;

struct Fish {
  std::string name;
};
struct Cat {
  std::string name;
};
struct Dog {
  std::string name;
};
auto animals = hana::make_tuple(Fish{"Nemo"}, Cat{"Garfield"}, Dog{"Snoopy"});
using namespace hana::literals;
// Access tuple elements with operator[] instead of std::get.
Cat garfield = animals[1_c];
// Perform high level algorithms on tuples (this is like std::transform)
auto names = hana::transform(animals, [](auto a) { return a.name; });

auto animal_types = hana::make_tuple(hana::type_c<Fish*>, hana::type_c<Cat&>, hana::type_c<Dog>);
auto no_pointers =
    hana::remove_if(animal_types, [](auto a) { return hana::traits::is_pointer(a); });

auto has_name = hana::is_valid([](auto&& x) -> decltype((void)x.name) {});

struct Person {
  BOOST_HANA_DEFINE_STRUCT(Person, (std::string, name), (int, age));
};

auto serialize = [](std::ostream& os, auto const& object) {
  hana::for_each(hana::members(object),
                 [&](auto member) { os << member << "   " << typeid(member).name() << std::endl; });
};

//! [cases]
template <typename T>
auto case_ = [](auto f) { return hana::make_pair(hana::type_c<T>, f); };
struct default_t;
auto default_ = case_<default_t>;
//! [cases]

//! [switch_]
template <typename Any>
auto switch_(Any& a) {
  return [&a](auto... cases_) {
    auto cases = hana::make_tuple(cases_...);
    auto default_ = hana::find_if(
        cases, [](auto const& c) { return hana::first(c) == hana::type_c<default_t>; });
    static_assert(default_ != hana::nothing, "switch is missing a default_ case");
    auto rest = hana::filter(
        cases, [](auto const& c) { return hana::first(c) != hana::type_c<default_t>; });
    return hana::unpack(rest, [&](auto&... rest) {
      return process(a, a.type(), hana::second(*default_), rest...);
    });
  };
}
//! [switch_]

//! [process]
template <typename Any, typename Default>
auto process(Any&, std::type_index const&, Default& default_) {
  return default_();
}
template <typename Any, typename Default, typename Case, typename... Rest>
auto process(Any& a, std::type_index const& t, Default& default_, Case& case_, Rest&... rest) {
  using T = typename decltype(+hana::first(case_))::type;
  return t == typeid(T) ? hana::second(case_)(*boost::unsafe_any_cast<T>(&a))
                        : process(a, t, default_, rest...);
}
//! [process]

boost::any a = 'x';
std::string r = switch_(a)(case_<int>([](auto i) { return "int: " + std::to_string(i); }),
                           case_<char>([](auto c) { return "char: " + std::string{c}; }),
                           default_([] { return "unknown"; }));

#endif  // __HLIST_H_
