cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_PREFIX_PATH "/opt/ros/melodic" "/opt/ros/kinetic")

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(roscpp REQUIRED CONFIG)
find_package(cv_bridge REQUIRED CONFIG)

find_package(catkin REQUIRED COMPONENTS message_generation)
add_message_files(
        FILES
            keyframeGraphMsg.msg
            keyframeMsg.msg
)
generate_messages(DEPENDENCIES)


add_library(IOWrapper STATIC
        src/ImageDisplay_OpenCV.cpp
        src/ROSOutput3DWrapper.cpp
        src/ROSImageStreamThread.cpp
        src/Timestamp.cpp)

add_library(lsd_slam::core::IOWrapper ALIAS IOWrapper)

add_dependencies(IOWrapper lsd_slam_generate_messages_cpp)

target_include_directories(IOWrapper
        PUBLIC
            include
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(IOWrapper
        ${roscpp_LIBRARIES}
        ${cv_bridge_LIBRARIES}
        opencv_core
        opencv_imgproc
        Boost::thread
        lsd_slam::core::util
        )