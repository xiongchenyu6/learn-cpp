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
#include "list.h"
#include "permutation.h"
#include "rb_tree.h"
#include "static_binding.h"

using namespace std;

thread_local ClassConstructor class_constructor_global;

void demo_thread_local() {
    cout << "test in local scope"
         << "\n";
    thread_local ClassConstructor class_constructor_local;
    class_constructor_local.test();

    std::thread t_local([]() {
        std::cout << "Thread: " << std::this_thread::get_id() << " entered"
                  << std::endl;
        class_constructor_local.test();
    });
    t_local.join();

    cout << "======================================华丽的分界线================"
            "===================="
         << "\n"
         << "test in global scope"
         << "\n";

    class_constructor_global.test();

    std::thread t_global([]() {
        std::cout << "Thread: " << std::this_thread::get_id() << " entered"
                  << std::endl;
        class_constructor_global.test();
    });
    t_global.join();
}

void demo_future_traverse() {
    cout << "main thread id is :" << this_thread::get_id() << endl;
    vector<future<void>> futures;
    for (int i = 0; i < 10; ++i) {
        futures.emplace_back(async([]() {
            this_thread::sleep_for(chrono::seconds(2));
            cout << this_thread::get_id() << " \n";
        }));
    }
    for_each(futures.begin(), futures.end(),
             [=](future<void> &fut) { fut.wait(); });
}

void demo_recap() {
    //  Enter your code here.Read input from STDIN.Print output to STDOUT

    // vector<int> x;
    // x.resize(3);  //  x.reserve(3); reserve on affec the memory not the size
    // cin >> x[0] >> x[1] >> x[2];
    // int sum = std::accumulate(x.begin(), x.end(), (int)0);
    vector<int> v{0, 1, 2, 3, 4, 5, 6};

    for (auto it = v.begin(), e = v.end(); it != e; ++it) {
        const int x = *it;
        cout << x << "," << v.capacity() << endl;
        v.push_back(x);
    }
}

int lcs(string &X, string &Y, int m, int n) {
    // 动态规划表，大小(m+1)*(n+1)
    vector<vector<int>> table(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            // 第一行和第一列置0
            if (i == 0 || j == 0)
                table[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;

            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    return table[m][n];
}
#endif// __DEMO_H_
