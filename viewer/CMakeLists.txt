cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Eigen3 REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(QGLViewer REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(roscpp REQUIRED CONFIG)


add_executable(lsd_slam_viewer
        src/KeyFrameDisplay.cpp
        src/KeyFrameGraphDisplay.cpp
        src/main_viewer.cpp
        src/PointCloudViewer.cpp
        src/settings.cpp
        )

target_include_directories(lsd_slam_viewer
        PRIVATE
            include
        PUBLIC
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(lsd_slam_viewer
        ${OpenGL_LIBRARY}
        opencv_core
        thirdparty::sophus
        Boost::thread
        Eigen3::Eigen
        lsd_slam::messages
        )