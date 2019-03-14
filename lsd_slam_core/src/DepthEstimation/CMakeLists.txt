cmake_minimum_required(VERSION 3.6)

find_package(OpenCV REQUIRED)

add_library(DepthEstimation
        src/DepthMap.cpp
        src/DepthMapPixelHypothesis.cpp
        )
add_library(lsd_slam_core::DepthEstimation ALIAS DepthEstimation)

target_include_directories(DepthEstimation
        PUBLIC
            include
        )

target_link_libraries(DepthEstimation
        opencv_core
        opencv_imgproc
        lsd_slam_core::util
        lsd_slam_core::GlobalMapping
        )