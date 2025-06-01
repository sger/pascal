#include <gtest/gtest.h>

// Simple test case
TEST(MathTest, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

// Another example
TEST(StringTest, Length) {
    std::string str = "pascal";
    EXPECT_EQ(str.size(), 6);
}
