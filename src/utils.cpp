#include "utils.h"

#include "list.h"

auto thFun(List &list) -> void {
    for (int i = 0; i < 100; ++i) list.insert(i);
}
