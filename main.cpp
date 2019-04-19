#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include "fib.h"

using namespace std;
int main(int argc, const char *argv[]) {
  int f = fib::Fibonacci<5>::value;
  // vector<int> x;
  // x.resize(3);  //  x.reserve(3); reserve on affec the memory not the size
  // cin >> x[0] >> x[1] >> x[2];
  // int sum = std::accumulate(x.begin(), x.end(), (int)0);
  cout << f << endl;
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
