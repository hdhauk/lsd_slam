cmake_minimum_required(VERSION 3.6)

add_subdirectory(src/DataStructures)
add_subdirectory(src/DepthEstimation)
add_subdirectory(src/GlobalMapping)
add_subdirectory(src/IOWrapper)
add_subdirectory(src/Tracking)
add_subdirectory(src/util)


find_package(Boost COMPONENTS thread REQUIRED)
find_package(OpenCV REQUIRED CONFIG)
find_package(Eigen3 REQUIRED CONFIG)
find_package(X11 REQUIRED)
find_package(roscpp REQUIRED CONFIG)
find_package(g2o REQUIRED)
find_package(roslib REQUIRED CONFIG)


add_executable(lsd_slam_core
        src/main_live_odometry.cpp
        src/LiveSLAMWrapper.cpp
        src/SlamSystem.cpp
        )

target_include_directories(lsd_slam_core
        PRIVATE
            src
            thirdparty/Sophus
            ${X11_INCLUDE_DIR}
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(lsd_slam_core
        Boost::thread
        opencv_core
        opencv_imgcodecs
        ${X11_LIBRARIES}
        ${roscpp_LIBRARIES}
        ${roslib_LIBRARIES}
        thirdparty::sophus
        Eigen3::Eigen
        lsd_slam_core::util
        lsd_slam_core::IOWrapper
        lsd_slam_core::Tracking
        )

