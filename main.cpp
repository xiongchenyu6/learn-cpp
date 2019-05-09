#include <algorithm>
#include <chrono>
#include <filesystem>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include "fib.h"
#include "list.h"
#include "utils.h"

using namespace std;
struct foo {
  foo() { std::cout << "Default constructor" << '\n'; }
  foo(foo const&) { std::cout << "Copy constructor" << '\n'; }
  foo& operator=(foo const&) {
    std::cout << "Copy assignment operator" << '\n';
    return *this;
  }
  foo& operator=(foo&&) {
    std::cout << "Move assignment operator" << '\n';
    return *this;
  }
};

int main(int argc, const char* argv[]) {
  foo a;             // Default constructor
  foo b = a;         // Copy constructor
  foo c;             // Default constructor
  c = b;             // Copy assignment operator
  b = std::move(c);  // Move assignment operator
  foo* m = new foo();

  int f = fold::sum(1, 2, 3, 4);
  cout << f << endl;
  cout << &a << endl;
  cout << &b << endl;
  cout << m << endl;
  // vector<int> x;
  // x.resize(3);  //  x.reserve(3); reserve on affec the memory not the size
  // cin >> x[0] >> x[1] >> x[2];
  // int sum = std::accumulate(x.begin(), x.end(), (int)0);
  // int f = fib::Fibonacci<5>::value;
  // auto list = new List();
  // list->insert(12);
  // cout << f << endl;
  // cout << list << endl;

  // cout << "main thread id is :" << this_thread::get_id() << endl;
  // vector<future<void>> futures;
  // for (int i = 0; i < 10; ++i) {
  //   futures.emplace_back(async([]() {
  //     this_thread::sleep_for(chrono::seconds(2));
  //     cout << this_thread::get_id() << " \n";
  //   }));
  // }

  // for_each(futures.begin(), futures.end(), [=](future<void> &fut) { fut.wait(); });

  // cout << endl;

  // this_thread::sleep_for(chrono::seconds(10));
  //

  return 0;
}

// int main() {
//
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
// vector<int> v{0, 1, 2, 3, 4};
// v.reserve(10);

// for (auto it = v.begin(), e = v.end(); it != e; ++it) {
//   const int x = *it;
//   cout << x << "," << v.capacity() << endl;
//   v.push_back(x);
// }
// return 0;
//  char a[] = "sdmfhsgnshejfgnihaofhsrnihao";
//  Tree root = buildingTree(); ///建立Trie树
//  buildingFailPath(root);     ///添加失败转移
//  cout << "待匹配字符串：" << a << endl;
//  cout << "模式" << pattern[0] << " " << pattern[1] << " " << pattern[2] << "
//  "
//       << pattern[3] << " " << endl
//       << endl;
//  cout << "匹配结果如下：" << endl
//       << "位置\t"
//       << "编号\t"
//       << "模式" << endl;
//  searchAC(root, a, strlen(a)); ///搜索
//  destory(root);                ///释放动态申请内存
//  return 0;
//}
