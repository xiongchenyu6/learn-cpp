#include "implicit.h"

#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <gtest/gtest_pred_impl.h>

#include <string>

using std::string;

TEST(Implicit, ImplicitEqual) {
    SubA sub_a;
    Base base = sub_a;
    std::string x = base.test();
    EXPECT_PRED2([](auto s1, auto s2) { return s1 == s2; }, x, "from SubA");
}
