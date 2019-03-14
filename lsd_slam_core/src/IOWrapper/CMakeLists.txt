cmake_minimum_required(VERSION 3.6)

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)

add_library(IOWrapper
        src/ImageDisplay_OpenCV.cpp
        src/ROSImageStreamThread.cpp
        src/Timestamp.cpp)

add_library(lsd_slam_core::IOWrapper ALIAS IOWrapper)

target_include_directories(IOWrapper
        PUBLIC
            include
        )

target_link_libraries(IOWrapper
        opencv_core
        opencv_imgproc
        Boost::thread
        )