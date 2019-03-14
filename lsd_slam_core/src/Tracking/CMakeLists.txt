cmake_minimum_required(VERSION 3.6)

add_library(Tracking
        src/Relocalizer.cpp
        src/SE3Tracker.cpp
        src/Sim3Tracker.cpp
        src/TrackingReference.cpp
        )

add_library(lsd_slam_core::Tracking ALIAS Tracking)

target_include_directories(Tracking
        PUBLIC
            include
        )

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)

target_link_libraries(Tracking
        Eigen3::Eigen
        opencv_core
        opencv_highgui
        Boost::thread
        lsd_slam_core::DataStructures
        lsd_slam_core::IOWrapper
        lsd_slam_core::GlobalMapping
        lsd_slam_core::DepthEstimation
        lsd_slam_core::util
        )