#ifndef __CLASS_CONSTRUCTOR_H_
#define __CLASS_CONSTRUCTOR_H_

#include <iostream>
#include <thread>

using namespace std;

struct ClassConstructor {
    string name;
    ClassConstructor(string name) : name(name) {
        cout << "Default constructor in thread : " << std::this_thread::get_id()
             << " name is " << name << " " << __FUNCTION__ << "(" << (void*)this
             << ")" << std::endl;
    }
    ClassConstructor() {
        cout << "Default constructor in thread : " << std::this_thread::get_id()
             << " " << __FUNCTION__ << "(" << (void*)this << ")" << std::endl;
    }

    ~ClassConstructor() {
        cout << "Default destructor in thread : " << std::this_thread::get_id()
             << " name: " << name << " " << __FUNCTION__ << "(" << (void*)this
             << ")" << std::endl;
    }

    ClassConstructor(ClassConstructor const&) {
        std::cout << "Copy constructor" << '\n';
    }

    ClassConstructor& operator=(ClassConstructor const&) {
        std::cout << "Copy assignment operator" << '\n';
        return *this;
    }

    ClassConstructor& operator=(ClassConstructor&&) {
        std::cout << "Move assignment operator" << '\n';
        return *this;
    }

    void run_demo() {
        ClassConstructor a;    // Default constructor
        ClassConstructor b = a;// Copy constructor
        ClassConstructor c;    // Default constructor
        c = b;                 // Copy assignment operator
        b = std::move(c);      // Move assignment operator
        ClassConstructor* m = new ClassConstructor();
        cout << m << endl;
    }
    void test() const {
        cout << "Test in thread : " << std::this_thread::get_id() << " "
             << "name : " << name << " " << __FUNCTION__ << "(" << (void*)this
             << ")" << std::endl;
    }
};

#endif// __CLASS_CONSTRUCTOR_H_
