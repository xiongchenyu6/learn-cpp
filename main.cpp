#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <future>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

#include "ac.h"
#include "class_constructor.h"
#include "demo.h"
#include "list.h"
#include "permutation.h"
#include "static_binding.h"
#include "utils.h"

using namespace std;

auto main(int argc, char* args[]) -> int {
    // demo_perm("hate");
    cout << args[1];

    auto a = vector<string>{"aa"};
    //demo_thread_local();
    // demo_implicit();
    // map<int, int> m;
    // m[0] = m.size();
    // cout << R"***("quoted string containing the usual''()))))(((( ""<>d{}\n\rterminator (")")***"
    //      << "\n"
    //      << sizeof(int) << "\n"
    //      << sizeof(char) << "\n"
    //      << m[0] << "\n"
    //      << endl;
    //
    int z = 12;
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
    std::vector<int> v = {7, 1, 4, 0, -1};

    std::ranges::sort(v);

    DEBUG::debug(z, v);
    std::string s1 = "Test";

    std::string& r1 = s1;// 错误：不能绑定到左值

    const std::string& r2 = s1;// 可行：到常值的左值引用延长生存期
    //  r2 += "Test";                    // 错误：不能通过到常值的引用修改

    std::string&& r3 = s1 + s1;// 可行：右值引用延长生存期
    r3 += "Test";// 可行：能通过到非常值的右值引用修改
    DEBUG::debug(s1, r2, r3);
    return 0;
}
