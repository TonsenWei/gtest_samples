#include "gtest/gtest.h"
#include "calculator.h"
#include "string"

using namespace std;
#include "calculator_fixture.h"

// Testing default constructors
TEST(CALCULATORtest, Constructor)
{
    Calculator cal;
    EXPECT_EQ(0, cal.value());
}

// Testing constructors with one parameter
TEST(CALCULATORtest, ConstructorWithOneParam)
{
    Calculator cal(10);
    EXPECT_EQ(10, cal.value());
}

// Testing calculator plus
TEST(CALCULATORtest, CalculatorPlus)
{
    // Negative
    Calculator cal1(-1);
    cal1.calculate(t_operation::plus, -1);
    EXPECT_EQ(-2, cal1.value());
    
    Calculator cal2(-1);
    cal2.calculate(t_operation::plus, 0);
    EXPECT_EQ(-1, cal2.value());

    Calculator cal3(-1);
    cal3.calculate(t_operation::plus, 1);
    EXPECT_EQ(0, cal3.value());


    // positive
    Calculator cal4(1);
    cal4.calculate(t_operation::plus, -1);
    EXPECT_EQ(0, cal4.value());

    Calculator cal5(1);
    cal5.calculate(t_operation::plus, 0);
    EXPECT_EQ(1, cal5.value());

    Calculator cal6(1);
    cal6.calculate(t_operation::plus, 1);
    EXPECT_EQ(2, cal6.value());

    // zero
    Calculator cal7(0);
    cal7.calculate(t_operation::plus, -1);
    EXPECT_EQ(-1, cal7.value());

    Calculator cal8(0);
    cal8.calculate(t_operation::plus, 0);
    EXPECT_EQ(0, cal8.value());

    Calculator cal9(0);
    cal9.calculate(t_operation::plus, 1);
    EXPECT_EQ(1, cal9.value());
}

TEST_P(CalculatorFixture, FixtureUseDemo)
{
    int n = GetParam();
    Calculator cal(-1);
    cal.calculate(t_operation::plus, n);
    EXPECT_EQ((-2)+(n), cal.value());

    Calculator cal1(0);
    cal1.calculate(t_operation::plus, n);
    EXPECT_EQ((0)+(n), cal1.value());

    Calculator cal2(1);
    cal2.calculate(t_operation::plus, n);
    EXPECT_EQ((1)+(n), cal2.value());    
}