cmake_minimum_required(VERSION 3.6)

add_subdirectory(src/DataStructures)
add_subdirectory(src/DepthEstimation)
add_subdirectory(src/GlobalMapping)
add_subdirectory(src/IOWrapper)
add_subdirectory(src/Tracking)
add_subdirectory(src/util)


find_package(Boost COMPONENTS thread REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)


add_executable(lsd_slam_core
        src/main_on_images.cpp
        )

target_include_directories(lsd_slam_core
        PRIVATE
                src
                thirdparty/Sophus
        )

target_link_libraries(
        lsd_slam_core
        Boost::thread
        opencv_core
        thirdparty::sophus
        Eigen3::Eigen
        lsd_slam_core::util
        lsd_slam_core::IOWrapper
        )

