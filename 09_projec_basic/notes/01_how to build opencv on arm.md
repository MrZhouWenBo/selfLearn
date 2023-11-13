# 关键词：交叉编译 cmake
[参考博文](https://blog.csdn.net/wjpwjpwjp0831/article/details/128269371)

# 交叉编译toolchain.cmake
```
1 ***toolchain.cmake的设置

    # set cross-compiled system type, it's better not use the type which cmake cannot recognized.
    SET ( CMAKE_SYSTEM_NAME Linux )
    SET ( CMAKE_SYSTEM_PROCESSOR aarch64 )

    SET ( CMAKE_C_COMPILER aarch64-none-linux-gnu-gcc )
    SET ( CMAKE_CXX_COMPILER aarch64-none-linux-gnu-g++)

    # set searching rules for cross-compiler
    SET ( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER )
    SET ( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY )
    SET ( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY )

    # set ${CMAKE_C_FLAGS} and ${CMAKE_CXX_FLAGS}flag for cross-compiled process
    SET ( CMAKE_CXX_FLAGS "-std=c++11 -lpthread -fPIC ${CMAKE_CXX_FLAGS}" )
    SET ( PLATFORM RK3588)


2 cmake时指定交叉编译器

    # RK3558  eg

    TOOLCHAIN_ROOT=**/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu
    # export LD_LIBRARY_PATH=${TOOLCHAIN_ROOT}/lib:$LD_LIBRARY_PATH
    export PATH=${TOOLCHAIN_ROOT}/bin:$PATH
    TOOLCHAIN_FILE=$ROOT_DIR/toolchains/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu.toolchain.cmake
    ...
    ...
    cmake -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE


```
