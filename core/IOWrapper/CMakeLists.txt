cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_PREFIX_PATH "/opt/ros/melodic" "/opt/ros/kinetic")

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(roscpp REQUIRED CONFIG)
find_package(cv_bridge REQUIRED CONFIG)

find_package(catkin REQUIRED COMPONENTS
        dynamic_reconfigure
        )
generate_dynamic_reconfigure_options(
        config/LSDParams.cfg
        config/LSDDebugParams.cfg
        config/LSDSLAMViewerParams.cfg
)

add_library(IOWrapper STATIC
        src/ImageDisplay_OpenCV.cpp
        src/ROSOutput3DWrapper.cpp
        src/ROSImageStreamThread.cpp
        src/Timestamp.cpp)

add_library(lsd_slam::core::IOWrapper ALIAS IOWrapper)

add_dependencies(IOWrapper lsd_slam_gencfg)


target_include_directories(IOWrapper
        PUBLIC
            include
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(IOWrapper
        ${roscpp_LIBRARIES}
        ${catkin_LIBRARIES}
        ${cv_bridge_LIBRARIES}
        opencv_core
        opencv_imgproc
        Boost::thread
        lsd_slam::core::util
        lsd_slam::messages
        )