#include <array>
#include <iostream>
#include <vector>

// class Node {
// public:
//     Node(int v, int c) : val(v), black(c){};
//     int val;
//     bool black;
//     Node* left;
//     Node* right;
// };

// class RBT {
// public:
//     Node* root;
//     void add(int v);
//     void del(int v);
//     Node* find(int v);
// };

using namespace std;
class NodeMulti {
public:
    NodeMulti() { vals = new array<int, 3>{}; };
    NodeMulti(int x) : size(1) {
        if (vals == nullptr) { vals = new array<int, 3>{}; }
        (*vals)[0] = x;
    };
    NodeMulti(int x, int y) : size(2) {
        if (vals == nullptr) { vals = new array<int, 3>{}; }
        (*vals)[0] = x;
        (*vals)[1] = y;
    };
    NodeMulti(int x, int y, int z) : size(3) {
        if (vals == nullptr) { vals = new array<int, 3>{}; }
        (*vals)[0] = x;
        (*vals)[1] = y;
        (*vals)[2] = z;
    };
    int size;
    std::array<int, 3>* vals{0};
};

class TTT {
public:
    void add(int v);
    NodeMulti* root;
    // void del(int v);
    // NodeMulti* find(int v);
};
