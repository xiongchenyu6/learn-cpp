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
#include "smart_pointer.h"
#include "static_binding.h"
#include "decode.hpp"

using namespace std;
using namespace DEBUG;
#define vi vector<int>
// theirs
auto main(int argc, char* args[]) -> int {
    char a[] = "asfdsfsdmfhsgnshejfgnihaofhsrnihao";
    Tree root = buildingTree();///建立Trie树

    process();
    
    return 0;
}

//     return ptr;
// }

// void emit_code_into_memory(unsigned char* m) {
//     unsigned char code[] = {
//         0x55,                  // push   %rbp
//         0x48, 0x89, 0xe5,      // mov    %rsp,%rbp
//         0x48, 0x89, 0x7d, 0xf8,// mov    %rdi,-0x8(%rbp)
//         0x48, 0x8b, 0x45, 0xf8,// mov    -0x8(%rbp),%rax
//         0x48, 0x83, 0xc0, 0x04,// add    $0x4,%rax
//         0x5d,                  // pop    %rbp
//         0xc3                   // retq
//     };
//     memcpy(m, code, sizeof(code));
// }

// const size_t SIZE = 1024;
// typedef long (*JittedFunc)(long);

// void run_from_rwx() {
//     void* m = alloc_executable_memory(SIZE);
//     emit_code_into_memory(reinterpret_cast<unsigned char*>(m));
//     JittedFunc func = reinterpret_cast<JittedFunc>(m);
//     int result = func(3);
//     printf("result = %d\n", result);
// }

// int main() {
//     run_from_rwx();
//     return 0;
// }
