#ifndef MOCKFOO_H_
#define MOCKFOO_H_

#include <gmock/gmock.h>
#include <string>
#include "../source/inc/FooInterface.h"

namespace seamless {

class MockFoo: public FooInterface {
public:
    MOCK_METHOD0(getArbitraryString, std::string());
};

}  // namespace seamless

#endif // MOCKFOO_H_