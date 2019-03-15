cmake_minimum_required(VERSION 3.6)

add_library(Tracking STATIC
        src/Relocalizer.cpp
        src/SE3Tracker.cpp
        src/Sim3Tracker.cpp
        src/TrackingReference.cpp
        )

add_library(lsd_slam::core::Tracking ALIAS Tracking)

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
        lsd_slam::core::DataStructures
        lsd_slam::core::IOWrapper
        lsd_slam::core::GlobalMapping
        lsd_slam::core::DepthEstimation
        lsd_slam::core::util
        )