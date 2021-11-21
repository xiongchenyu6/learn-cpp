#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <filesystem>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <ostream>
#include <queue>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "ac.h"
#include "demo.h"
#include "quick_sort.h"
#include "utils.h"

using namespace std;

auto main(int argc, char* args[]) -> int {
    // demo_perm("hate");

    // demo_thread_local();
    // demo_implicit();
    // map<int, int> m;
    // m[0] = m.size();
    // cout

    //     << R"***("quoted string containing the usual''()))))(((( ""<>d{}\n\rterminator (")")***"
    //     << "\n"
    //     << sizeof(int) << "\n"
    //     << sizeof(char) << "\n"
    //     << m[0] << "\n"
    //     << endl;

    // string X = "ABCBDAB";
    // string Y = "BDCABA";
    // cout << lcs(X, Y, 4, 4) << "\n";

    // char a[] = "sdmfhsgnshejfgnihaofhsrnihao";
    // Tree root = buildingTree();///建立Trie树
    // buildingFailPath(root);    ///添加失败转移
    // cout << "待匹配字符串：" << a << endl;
    // cout << "模式" << pattern[0] << " " << pattern[1] << " " << pattern[2] << "" << pattern[3]
    //      << " " << endl
    //      << endl;
    // cout << "匹配结果如下：" << endl
    //      << "位置\t"
    //      << "编号\t"
    //      << "模式" << endl;
    // searchAC(root, a, strlen(a));//搜索
    // destory(root);               //释放动态申请内存
    //                              // this_thread::sleep_for(chrono::seconds(10));
    //
    // std::vector<int> v = {7, 1, 4, 0, -1};

    // std::ranges::sort(v);

    // DEBUG::debug(v);
    // std::string s1 = "Test";

    // std::string& r1 = s1;// 错误：不能绑定到左值

    // const std::string& r2 = s1;// 可行：到常值的左值引用延长生存期
    // //  r2 += "Test";                    // 错误：不能通过到常值的引用修改

    // std::string&& r3 = s1 + s1;// 可行：右值引用延长生存期
    // r3 += "Test";// 可行：能通过到非常值的右值引用修改
    // //
    // const char* eee = "fsdaf";

    // cerr << eee << endl;

    // while (*eee != '\0') {
    //     cout << *eee << endl;
    //     ++eee;
    // }
    // cout << "test" << endl;
    // auto n = make_tuple(1, 'c', "fsadf");
    // int z = 12;
    // string s = to_string(z);
    // int m = stoi(s);
    // auto ll = get<2>(n);

    // cout << get<0>(n);
    // cout << get<1>(n);
    // cout << get<2>(n) << endl;
    // Node* a = new Node{1};
    // Node* b = new Node{2};
    // Node* c = new Node{3};
    // a->next = b;
    // b->next = c;

    // auto pre = a;
    // auto cur = a->next;
    // Node* tmp;
    // while (cur != nullptr) {
    //     tmp = cur->next;
    //     cur->next = pre;
    //     pre = cur;
    //     cur = tmp;
    // }
    // a->next = nullptr;
    // while (c != nullptr) {
    //     cout << c->val << endl;
    //     c = c->next;
    // }

    // TN* aa = new TN{1};
    // TN* bb = new TN{2};
    // TN* cc = new TN{3};
    // aa->l = bb;
    // aa->r = cc;

    // TN::preorder(aa);
    // priority_queue<int, vector<int>, greater<int>> a;
    // a.push(1);
    // a.push(2);
    // a.push(3);
    // cout << a.top() << endl;
    // unordered_map<int, int> hash_map;
    // hash_map.emplace(1, 23);

    // cout << hash_map[1] << endl;

    // map<int, int> m;
    // m.emplace(1, 23);
    // int myints[] = {10, 20, 30, 40, 50};//   myints:  10  20  30  40  50
    // atomic_int e = 0;

    // auto ff = [&](string x, int i) {
    //     while (e < 20) {
    //         if (e % 2 == i) {
    //             cout << x << " : " << e << endl;
    //             e.fetch_add(1);
    //         }
    //     }
    // };

    // thread dd(ff, "d", 0);
    // thread ee(ff, "e", 1);

    // dd.join();
    // ee.join();

    vector<int> myvector{5, 4,  6, 7, 9,
                         3, 10, 9, 5, 6};// myvector:  99  99  99  99
    // std::mutex mu;
    // std::condition_variable cv;

    // auto f = [&](string x) {
    //     while (1) {
    //         unique_lock<mutex> um(mu);
    //         if (myvector.size() != 0) {
    //             cout << x << " : " << myvector.front() << endl;
    //             myvector.erase(myvector.begin());
    //             cv.notify_one();
    //             cv.wait(um);
    //         } else {
    //             cv.notify_one();
    //             break;
    //         }
    //     }
    // };

    //     thread a(f, "a");
    // thread b(f, "b");

    // cv.notify_one();
    // a.join();
    // b.join();
    // int size = myvector.size();
    // vector<promise<int>> pl(size);

    // auto a1 = [&](string x) { p.set_value(1); };
    // iter_swap(myints + 3, myvector.begin() + 2);
    // partial_sort(myints, myints + 3, myints + 5, less<int>());
    auto x = new array<int, 3>{};
    demo_ttt();
    std::list<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    auto it = y.begin();
    std::advance(it, 2);

    std::swap(*it, *y.end());
    DEBUG::debug(y.front());
    DEBUG::debug(*y.end());

    // demo_perm("abc");
    // demo_implicit();

    return 0;
}
