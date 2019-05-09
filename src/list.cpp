#include "list.h"

void List::insert(int x) {
  auto node = new Node(x);
  node->_next = _head;
  _head = node;
};
