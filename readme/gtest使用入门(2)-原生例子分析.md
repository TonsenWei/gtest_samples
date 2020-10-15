
@[TOC](目录)
## 一、原生例子路径
上篇我们已经介绍原生的例子在如下路径：

    googletest-release-1.8.1/googletest/samples  // 测试用例和待测源码所在目录
    googletest-release-1.8.1/googletest/src/gtest_main.cc // 测试主程序入口

在此简单分析一下例子。

## 二、待测代码
首先我们先分析待测代码，路径：googletest-release-1.8.1/googletest/samples

包括头文件（sample1.h）和原文件(sample1.cc)。
该源码是两个函数，功能分别是计算给定数值的阶乘，和判断给定的值是否是质数。源码的具体实现我们就不分析了，重点主要放在测试上。

头文件如下：
```c
#ifndef GTEST_SAMPLES_SAMPLE1_H_
#define GTEST_SAMPLES_SAMPLE1_H_

// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
// 返回n的阶乘。负数的阶乘结果定义为1.
int Factorial(int n);

// Returns true iff n is a prime number.
// 如果n是质数，则返回true
bool IsPrime(int n);

#endif  // GTEST_SAMPLES_SAMPLE1_H_
```

原文件如下：
```c
#include "sample1.h"

// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

// Returns true iff n is a prime number.
bool IsPrime(int n) {
  // Trivial case 1: small numbers
  if (n <= 1) return false;

  // Trivial case 2: even numbers
  if (n % 2 == 0) return n == 2;

  // Now, we have that n is odd and n >= 3.

  // Try to divide n by every odd number i, starting from 3
  for (int i = 3; ; i += 2) {
    // We only have to try i up to the square root of n
    if (i > n/i) break;

    // Now, we have i <= n/i < n.
    // If n is divisible by i, n is not prime.
    if (n % i == 0) return false;
  }

  // n has no integer factor in the range (1, n), and thus is prime.
  return true;
}
```


## 三、主程序入口

然后是测试主程序入口，路径：googletest-release-1.8.1/googletest/src/gtest_main.cc，我添加了一些注释，英文好的可以看看原文件里面的注释，是很详细的：

```c
#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__); //打印入口函数文件名称
  testing::InitGoogleTest(&argc, argv);			//初始化GTEST
  //执行所有测试，执行与主程序一起编译的所有测试用例
  return RUN_ALL_TESTS();						
}
```

## 四、测试用例代码

最后是我们最关注的测试用例源码：

googletest-release-1.8.1/googletest/samples/sample1_unittest.cc

用例有6个，前三个是用于测试阶乘函数的用例，后三个是用于测试判断质数的函数的用例。

这里主要接触到的是测试宏的使用，删除了原来的注释，增加了一些注释。

```c
#include <limits.h>
#include "sample1.h"
#include "gtest/gtest.h"  //包含头文件
namespace {

// Tests Factorial().

// 测试负数的阶乘.
TEST(FactorialTest, Negative) {
  // FactorialTest是testcase名，Negative为具体的test
  // 一般我们称FactorialTest是Testsuit, Negative是testcase,称呼不一样而已
  // EXPECT_XX是非致命断言，如果EXPECT结果失败，会继续执行下一句代码
  EXPECT_EQ(1, Factorial(-5)); //EXPECT_EQ测试宏，预期值等于1
  EXPECT_EQ(1, Factorial(-1)); //EXPECT_EQ测试宏，预期值等于1
  EXPECT_GT(Factorial(-10), 0);//EXPECT_GT试宏，预期值大于0
}

// Tests factorial of 0.
TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FactorialTest, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}


// Tests IsPrime()

// Tests negative input.
TEST(IsPrimeTest, Negative) {
  // This test belongs to the IsPrimeTest test case.

  EXPECT_FALSE(IsPrime(-1));  //EXPECT_FALSE测试宏，预期值为FALSE
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));  //EXPECT_FALSE测试宏，预期值为TRUE
  EXPECT_TRUE(IsPrime(3));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}
}  // namespace
```

## 五、总结
该例子可以看出使用GTEST基本的“套路”：
1、包含头文件（gtest.h、待测试原文件的头文件）
2、编写测试用例（TEST开头），调用函数并断言结果。


该例子使用了如下测试宏
1. TEST         //定义测试用例
2. EXPECT_EQ    //非致命断言等于
3. EXPECT_GT    //非致命断言大于
4. EXPECT_TRUE  //非致命断言为true
5. EXPECT_FALSE //非致命断言为false

更复杂的例子会使用到更多的断言，以及测试固件等功能，可以先看官方的源码学习一下。
