@[toc]
# 一、概述
最近在做白盒测试，没怎么接触C++和linux，现在要做C++的白盒测试，确定的方案是使用GTEST。
环境在linux上搭建，就学习了起来，边学边用，并记一下笔记备忘。

备注：当前linxu环境默认已配置好c++的一些编译环境，比如CMake、Make等。

# 二、源码获取
git仓库地址: [https://github.com/google/googletest](https://github.com/google/googletest)

有git账号的可以使用git直接clone,没有的可以下载zip，本人这边linux虚拟机下没有配置git，所以直接下载zip。
本人下载1.10.x版本编译不通过，另外下载了1.8.1版本才编译通过，试了1.8.0版本也可以编译通过，
建议下载1.8.1版本。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928193621586.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dkY3lmMTU=,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928193643664.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dkY3lmMTU=,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928193735674.png#pic_center)

# 三、源码编译
推送下载下来的源码到linxu下，解压
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928193848514.png#pic_center)
进入googletest-release-1.8.1目录,执行命令 cmake CMakeLists.txt，生成Makefile文件，
（在该目录下编译会生成mock程序和gtest程序，如果进入googletest-release-1.8.1/googletest目录编译，则只编译gtest程序）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928194649307.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dkY3lmMTU=,size_16,color_FFFFFF,t_70#pic_center)
再执行make命令，生成四个静态库：libgtest.a libgtest_main.a,libgmlck.a, libgmock_main.a
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928195027158.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dkY3lmMTU=,size_16,color_FFFFFF,t_70#pic_center)
通过命令

    find . -name "*.a"
可以查看如下文件是否生成：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928195210734.png#pic_center)
# 四、安装
安装gmock和gtest到系统：

    sudo make install
因为我们在googletest-release-1.8.1下编译和执行安装，所以默认会安装gmock和gtest,gmock后面打桩的时候会用到。
* 注意sudo权限。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928195436240.png#pic_center)
输入命令: 

    ls -l /usr/local/lib
    
查看是否安装成功，有如下四个文件，说明gtest安装成功，并安装了gmock模块
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928195808803.png#pic_center)

# 五、执行谷歌自带测试用例
我们还没有添加我们自己的源码，和针对源码的测试用例，但是谷歌已经写好了一些例子，放在如下路径

    googletest-release-1.8.1/googletest/samples  // 测试用例和待测源码所在目录
    googletest-release-1.8.1/googletest/src/gtest_main.cc // 测试主程序入口
  
 下面我执行samples下的sample1_unittest.cc这个测试集，里面共有6个用例，3个是阶乘的用例，三个是判断是否是质数的用例。

先使用cd命令切换到samples目录：

    cd googletests/samples
编译测试用例和测试主程序：

    g++ ../src/gtest_main.cc sample1.cc sample1_unittest.cc -o test -lgtest -lgmock -lpthread -std=c++11

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928201748481.png#pic_center)

测试结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200928201817583.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dkY3lmMTU=,size_16,color_FFFFFF,t_70#pic_center)

# 六、几点说明
* gtest_main.cc ：测试主程序入口，不是我们待测源码的主程序入口，所以整个工程其实可能有两个main函数，一个是测试的main,一个可能是待测源码的main，两个包含main的文件不能同时编译，因为一个执行程序只能有一个入口。
* sample1.cc：待测源码，就是测试对象，我们就是要对个源码进行白盒测试。
* sample1_unittest.cc：测试用例，里面就是我们针对源码写的测试用例脚本。
* 编译时要源码、测试主程序、测试用例一起编译（可以使用Makefile来管理工程的编译，就不用命令行输入那么长命令进行编译）
* 可以参考谷歌原生的例子，先学习学习谷歌的大神怎么写用例的。