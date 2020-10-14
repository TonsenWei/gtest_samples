#include <cstdlib>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "MockFoo.h"

using namespace seamless;
using namespace std;
using ::testing::Return;

TEST(FooInterfaceSuit, foo_mock_test) {
    string value = "Hello World!";
    MockFoo mockFoo;
    EXPECT_CALL(mockFoo, getArbitraryString()).Times(1).
            WillOnce(Return(value));
    string returnValue = mockFoo.getArbitraryString();
    cout << "Returned Value: " << returnValue << endl;
}