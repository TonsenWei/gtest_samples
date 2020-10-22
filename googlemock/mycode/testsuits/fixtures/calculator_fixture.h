#ifndef CALCULATOR_FIXTURE_H
#define CALCULATOR_FIXTURE_H

#include "gtest/gtest.h"
#include "calculator.h"

class CalculatorFixture : public ::testing::TestWithParam<int> 
{
    public:
        virtual void SetUp() {
            // Do some setup
        }
        virtual void TearDown() {
            // Do some tear down
        }
};


INSTANTIATE_TEST_CASE_P(
    CalculatorFixtureName,
    CalculatorFixture,
    testing::Values(
        -1,
        0,
        1
    )
);

#endif