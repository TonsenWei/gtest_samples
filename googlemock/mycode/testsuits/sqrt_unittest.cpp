#include "gtest/gtest.h"
#include "sqrt.h"

TEST(SQRTTest, Zero)
{
    EXPECT_EQ(0, sqrt(0));
}

TEST(SQRTTest, Positive)
{
    EXPECT_EQ(100, sqrt(10000));
    EXPECT_EQ(1000, sqrt(1000000));
    EXPECT_EQ(99, sqrt(9801));
}

TEST(SQRTTest, Negative)
{
    int i = -1;
    EXPECT_EQ(0, sqrt(i));
}

// cover x == 1
TEST(SQRTTest, One)
{
    EXPECT_EQ(1, sqrt(1));
}

