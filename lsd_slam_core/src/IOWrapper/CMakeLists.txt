cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_PREFIX_PATH "/opt/ros/melodic" "/opt/ros/kinetic")

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(roscpp REQUIRED CONFIG)

add_library(IOWrapper
        src/ImageDisplay_OpenCV.cpp
        src/ROSImageStreamThread.cpp
        src/Timestamp.cpp)

add_library(lsd_slam_core::IOWrapper ALIAS IOWrapper)

target_include_directories(IOWrapper
        PUBLIC
            include
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(IOWrapper
        roscpp
        opencv_core
        opencv_imgproc
        Boost::thread
        )