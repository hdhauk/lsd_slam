cmake_minimum_required(VERSION 3.6)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)


add_library(util
        src/globalFuncs.cpp
        src/settings.cpp
        src/SophusUtil.cpp
        src/Undistorter.cpp
        )
add_library(lsd_slam_core::util ALIAS util)

target_include_directories(util
        PUBLIC
            include
        )

target_link_libraries(util
        opencv_core
        Boost::boost
        Eigen3::Eigen
        thirdparty::sophus
        lsd_slam_core::IOWrapper
        lsd_slam_core::DataStructures
        )

