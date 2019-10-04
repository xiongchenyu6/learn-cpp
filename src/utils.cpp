#include "utils.h"
#include "list.h"

void thFun(List &list) {
    for (int i = 0; i < 100; ++i) list.insert(i);
}
