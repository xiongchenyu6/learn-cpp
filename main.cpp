#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <experimental/coroutine>
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
#include "static_binding.h"

using namespace std;
using namespace DEBUG;

auto main(int argc, char* args[]) -> int {
    cout << R"***('start' program)***" << std::endl;
    this_thread::sleep_for(chrono::microseconds(1));

    char a[] = "sdmfhsgnshejfgnihaofhsrnihao";
    Tree root = buildingTree();///建立Trie树
    buildingFailPath(root);    ///添加失败转移
    cout << "待匹配字符串：" << a << endl;
    cout << "模式" << pattern[0] << " " << pattern[1] << " " << pattern[2] << ""
         << pattern[3] << " " << endl
         << endl;
    cout << "匹配结果如下：" << endl
         << "位置\t"
         << "编号\t"
         << "模式" << endl;
    searchAC(root, a, strlen(a));//搜索
    destory(root);               //释放动态申请内存
    //
    return 0;
}
