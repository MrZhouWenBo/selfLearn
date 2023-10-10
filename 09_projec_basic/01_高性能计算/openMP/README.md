# 本文件夹下存放学习openMP相关代码和注释总结

openMP学习文档 https://www.hz-bin.cn/OpenMP
# 1 如何在cmake构建系统中启用openMP多线程并行化的功能
## 1.1 cmakeList.txt中启用OpenMP多线程并行化的功能
查看CMakeList.txt文件中有以下命令，目的是在构建过程中将OpenMP的相关标志传递给编译器和链接器，以便正确地编译和链接OpenMP的多线程并行化代码

1 cmakeLists中是如何实现的 
```
FIND_PACKAGE( OpenMP REQUIRED)

if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
```
2 在使用find查找某个依赖库时的内部实现步骤
```
FIND_PACKAGE(OpenMP REQUIRED) 是在CMake中用于查找OpenMP库的模块。它会根据一系列预定义的规则和路径来查找OpenMP库的相关信息。

具体来说，CMake会按照以下顺序查找OpenMP库的信息：

1. 首先，CMake会检查是否已经定义了OpenMP的相关变量，如`OpenMP_C_FLAGS`、`OpenMP_CXX_FLAGS`和`OpenMP_EXE_LINKER_FLAGS`。如果这些变量已经定义，CMake会将它们视为OpenMP库的相关信息。

2. 如果上述变量未定义，CMake会尝试查找系统的OpenMP库。它会搜索系统默认的库路径，如`/usr/lib`和`/usr/local/lib`，以及其他可能的路径。

3. 如果在系统默认路径中找不到OpenMP库，CMake会尝试使用用户指定的路径来查找OpenMP库。用户可以通过设置`OpenMP_ROOT_DIR`变量来指定OpenMP库的根目录。

4. 如果以上步骤都失败，CMake会报告错误，表示无法找到OpenMP库。

总之，`FIND_PACKAGE(OpenMP REQUIRED)`会在CMake中根据一系列预定义的规则和路径来查找OpenMP库的相关信息，并将其保存在相应的变量中供后续使用。
```

# 2 基础知识点

openMP由三个组件组成
- 编译器指令
- 运行时库函数
- 环境变量

## 2.1 编译器指令
1 session1.h中编写了一些编译指令的使用 
- 开启并行
- critical 指令锁定独享线程运行的指令  如master..使用时再查文档  
- for循环并行