#ifndef __LIST_H_
#define __LIST_H_

class List {
  struct Node {
    int _x;
    Node* _next;
    Node(int y) : _x(y), _next(nullptr) {}
  };

  Node* _head;

 public:
  List() : _head(nullptr) {}
  void insert(int x);
};

#endif  // __LIST_H_
