cmake_minimum_required(VERSION 3.6)

project(lsd_slam)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_PREFIX_PATH "/opt/ros/melodic" "/opt/ros/kinetic")

add_subdirectory(messages)
add_subdirectory(core)
add_subdirectory(viewer)
add_subdirectory(thirdparty/Sophus)

