#include "rb_tree.h"

#include <iostream>
#include <ostream>
#include <utility>

using namespace std;
void TTT::add(int v) {
    if (!root) {
        auto x = new NodeMulti(v);
        root = x;
    }
}

// void TTT::del(int v) {}

// NodeMulti* TTT::find(int v) {
//     NodeMulti* b = new NodeMulti();

//     return b;
// }
