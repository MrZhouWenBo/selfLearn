# 表示cmake的最低版本
cmake_minimum_required (VERSION 3.16)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
set(projrctName demo)

add_definitions("-DTIME_TRACE")
add_definitions("-DDEBUG")



# 表示目前编译的项目
project (${projrctName})


set(opencv_INCLUDES  ${CMAKE_CURRENT_LIST_DIR}/../tools/3rd/opencv/include)
set(opencv_LIB_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../tools/3rd/opencv/lib)
set(opencv_LIBS libopencv_world.so)



include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../tools
    ${CMAKE_CURRENT_LIST_DIR}/sessions
    ${opencv_INCLUDES}
)


FIND_PACKAGE( OpenMP REQUIRED)

# 上述代码片段是用于在CMake构建系统中启用OpenMP多线程并行化的功能。

# 首先，通过检查OPENMP_FOUND变量是否为真来确定是否找到了OpenMP库。

# 如果OPENMP_FOUND为真，那么会输出一条消息"OPENMP FOUND"。

# 然后，通过将OpenMP_C_FLAGS添加到CMAKE_C_FLAGS变量中，将OpenMP_CXX_FLAGS添加到CMAKE_CXX_FLAGS变量中，将OpenMP_EXE_LINKER_FLAGS添加到CMAKE_EXE_LINKER_FLAGS变量中，来设置编译器和链接器的标志，以启用OpenMP支持。

# 这样做的目的是在构建过程中将OpenMP的相关标志传递给编译器和链接器，以便正确地编译和链接OpenMP的多线程并行化代码。

if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

link_directories(${projrctName} ${opencv_LIB_DIRECTORY} )


add_executable(${projrctName} main.cpp)

target_link_libraries(${projrctName} 
    -pthread
    ${opencv_LIBS}
 )