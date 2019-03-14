cmake_minimum_required(VERSION 3.6)

project(lsd_slam)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lsd_slam_core)
add_subdirectory(lsd_slam_viewer)
add_subdirectory(thirdparty/Sophus)

