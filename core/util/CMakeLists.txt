cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_PREFIX_PATH "/opt/ros/melodic")

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(g2o REQUIRED)


add_library(util STATIC
        src/globalFuncs.cpp
        src/settings.cpp
        src/SophusUtil.cpp
        src/Undistorter.cpp
        )
add_library(lsd_slam::core::util ALIAS util)

target_include_directories(util
        PUBLIC
            include
        )

target_link_libraries(util
        opencv_core
        opencv_calib3d
        Boost::boost
        Eigen3::Eigen
        thirdparty::sophus
        lsd_slam::core::IOWrapper
        lsd_slam::core::DataStructures
        )

