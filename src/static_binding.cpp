#include "static_binding.h"
#include <iostream>

using namespace std;

void StaticBinding::do_sth() {
  cout << "A do sth"
       << "\n";
}

void StaticBinding::test() {
  cout << "A test"
       << "\n";
}

void StaticBinding::printA(StaticBinding* a) {
  cout << "a"
       << "\n";
}

void B::do_sth() {
  cout << "B do sth"
       << "\n";
}

void B::test() {
  cout << "B test"
       << "\n";
}

void B::run_test() {
  B* b = new B();
  StaticBinding* a = b;

  StaticBinding::printA(b);

  b->do_sth();
  b->test();

  a->do_sth();
  a->test();
}
