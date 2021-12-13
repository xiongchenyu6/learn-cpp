#include <gtest/gtest.h>// googletest header file
#include <quick_sort.h>

#include <string>
#include <vector>
using std::string;

const char *actualValTrue = "hello gtest";
const char *actualValFalse = "hello world";
const char *expectVal = "hello gtest";
std::vector<int> x = std::vector<int>{10, 5, 30, 99, 200, 1};

TEST(StrCompare, CStrEqual) {
    EXPECT_STREQ(expectVal, actualValTrue);
}

TEST(StrCompare, CStrNotEqual) {
    EXPECT_STRNE(expectVal, actualValFalse);
}

TEST(QuickSrot, Qs) {
    auto y = std::vector<int>{1, 5, 10, 30, 99, 200};
    quick_sort(x, 0, x.size() - 1);
    EXPECT_EQ(x, y);
}
