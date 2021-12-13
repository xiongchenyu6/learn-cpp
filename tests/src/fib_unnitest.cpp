#include <gtest/gtest.h>
#include <gtest/gtest_pred_impl.h>

#include <list>

#include "tmp.h"

TEST(Fib, Fib) {
    EXPECT_EQ(fib::fibonacci<5>(), 5);
}

TEST(FOLD, FOLD) {
    EXPECT_EQ(fold::sum(1, 2, 3, 4), 10);
}

TEST(LIST_ADVANCE, LIST_ADVANCE) {
    std::list<int> y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    auto it = y.begin();
    std::advance(it, 3);

    std::swap(*it, *y.end());
    EXPECT_EQ(y.front(), 1);// opposite back
    EXPECT_EQ(*y.end(), 4); // opposite begin
}
