#include <algorithm>
#include <chrono>
#include <filesystem>
#include <future>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include "ac.h"
#include "class_constructor.h"
#include "demo.h"
#include "list.h"
#include "static_binding.h"
#include "utils.h"

using namespace std;

int main() {
    //    demo_thread_local();
    demo_implicit();
    // map<int, int> m;
    // m[0] = m.size();
    // cout << R"***("quoted string containing the usual''()))))(((( ""<>d{}\n\rterminator (")")***"
    //      << "\n"
    //      << sizeof(int) << "\n"
    //      << sizeof(char) << "\n"
    //      << m[0] << "\n"
    //      << endl;
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
    return 0;
}
