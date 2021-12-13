#ifndef __DEMO_H_
#define __DEMO_H_

#include <tmp.h>

#include <future>
#include <iostream>
#include <thread>
#include <vector>

#include "class_constructor.h"
#include "implicit.h"
#include "lib.h"
#include "rb_tree.h"
#include "static_binding.h"

using namespace std;

thread_local ClassConstructor class_constructor_global("global");

void demo_thread_local() {
    cout << "main thread is : " << std::this_thread::get_id() << endl;
    cout << R"***(test in local scope
)***";
    // memory leak will happen in local create thread local object

    thread_local ClassConstructor class_constructor_local("local");
    class_constructor_local.test();

    std::thread t_local([]() {
        std::cout << "Thread: " << std::this_thread::get_id() << " entered"
                  << std::endl;
        class_constructor_local.test();
    });
    t_local.join();

    std::thread t_local2([]() {
        std::cout << "Thread: " << std::this_thread::get_id() << " entered"
                  << std::endl;
        class_constructor_local.test();
    });
    t_local2.join();
    cout
        << R"***(======================================华丽的分界线================
====================
test in global scope
)***";

    class_constructor_global.test();

    std::thread t_global([]() {
        std::cout << "Thread: " << std::this_thread::get_id() << " entered"
                  << std::endl;
        class_constructor_global.test();
    });
    t_global.join();
}
#endif// __DEMO_H_
