#include "permutation.h"

#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>// googletest header file

#include <string>
#include <vector>

using namespace std;
using namespace testing;

TEST(PERTEST, CORRESTNESS) {
    auto ret = permutation("adc");
    auto tmp = ElementsAre("adc", "dac", "dca", "acd", "cad", "cda");
    ASSERT_THAT(ret, tmp);
}
