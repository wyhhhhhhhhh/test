cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE "Release")
# 添加c++ 11标准支持
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Eigen
include_directories("/usr/include/eigen3")

# 寻找OpenCV库
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS
   "${CMAKE_CXX_FLAGS} -Wall -std=c++0x"
)

# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(stereo src/main.cpp )
target_link_libraries(stereo ${OpenCV_LIBS})
target_link_libraries(stereo pthread)     #主线程pthread依赖
target_link_libraries(stereo Threads::Threads)   #串口boost线程依赖
