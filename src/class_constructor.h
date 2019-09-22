#ifndef __CLASS_CONSTRUCTOR_H_
#define __CLASS_CONSTRUCTOR_H_

#include <iostream>
using namespace std;

struct ClassConstructor {
  ClassConstructor() { cout << "Default constructor" << '\n'; }
  ClassConstructor(ClassConstructor const&) { std::cout << "Copy constructor" << '\n'; }
  ClassConstructor& operator=(ClassConstructor const&) {
    std::cout << "Copy assignment operator" << '\n';
    return *this;
  }
  ClassConstructor& operator=(ClassConstructor&&) {
    std::cout << "Move assignment operator" << '\n';
    return *this;
  }
  void run_demo() {
    ClassConstructor a;      // Default constructor
    ClassConstructor b = a;  // Copy constructor
    ClassConstructor c;      // Default constructor
    c = b;                   // Copy assignment operator
    b = std::move(c);        // Move assignment operator
    ClassConstructor* m = new ClassConstructor();
    cout << m << endl;
  }
};

#endif  // __CLASS_CONSTRUCTOR_H_
