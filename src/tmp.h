#include <vector>
#ifndef FIB

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;
namespace DEBUG {

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& V) {
    os << "[ ";
    for (const auto& vv : V) os << vv << ", ";
    os << "]";
    return os;
}

template <typename T>
inline void _debug(const char* format, T t) {
    cerr << format << '=' << t << endl;
}

template <class First, class... Rest>
inline void _debug(const char* format, First first, Rest... rest) {
    while (*format != ',') cerr << *format++;
    cerr << '=' << first << ",";
    _debug(format + 1, rest...);
}

#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
}// namespace DEBUG

namespace fib {

// Calculate the value passed as T
template <int T>
struct Fibonacci {
    enum { value = (Fibonacci<T - 1>::value + Fibonacci<T - 2>::value) };
};

// In the template meta-programming, we do not have conditionals, so instead
// we use struct-overloading like mechanism to set constraints, we do this for
// numbers 0, 1 and 2, just like our algorithm in the function above.

template <>
struct Fibonacci<1> {
    enum { value = 1 };
};

template <>
struct Fibonacci<2> {
    enum { value = 1 };
};

//if constexpr version
template <int N>
constexpr int fibonacci() {
    if constexpr (N >= 2)
        return fibonacci<N - 1>() + fibonacci<N - 2>();
    else
        return N;
}

};// namespace fib

namespace fold {
template <typename... Args>
int sum(Args&&... args) {
    //    return (args + ... + 1 * 2); // Error: operator with precedence below cast
    return (args + ...);// OK
}

};// namespace fold

namespace sfinae {

//sizeof()返回的是函数返回值的大小
//U::*表示类成员函数指针. 比如std::string (*)() const 表明这是一个函数指针
//std::string (U::*)() const表示这是一个类的成员函数.
template <typename T>
class is_class {
    template <typename U>
    static char helper(int U::*);
    template <typename U>
    static int helper(...);

public:
    static const bool value = sizeof(helper<T>(0)) == 1;
};

template <typename T1, typename T2>
struct is_same {
    static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};

template <typename Base, typename Derived,
          bool = (is_class<Base>::value && is_class<Derived>::value)>
class is_base_of {
    template <typename T>
    static char helper(Derived, T);
    static int helper(Base, int);
    struct Conv {
        operator Derived();
        operator Base() const;
    };

public:
    static const bool value = sizeof(helper(Conv(), 0)) == 1;
};

template <typename Base, typename Derived>
class is_base_of<Base, Derived, false> {
public:
    static const bool value = is_same<Base, Derived>::value;
};

template <typename Base>
class is_base_of<Base, Base, true> {
public:
    static const bool value = true;
};

namespace detail {
template <class T, class U>
concept SameHelper = std::is_same_v<T, U>;

auto foo(auto t, auto u) -> int {
    return t.size() + u.size();
}

}// namespace detail

}// namespace sfinae

// namespace my_shared_ptr {
// template <class a, class b>
// {}
// }// namespace my_shared_ptr

#endif
