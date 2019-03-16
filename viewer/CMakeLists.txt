cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Eigen3 REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(QGLViewer REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(roscpp REQUIRED CONFIG)
find_package(roslib REQUIRED)
find_package(rosbag REQUIRED)
find_package(Qt4)


message("${QGLVIEWER_LIBRARY}")


add_executable(lsd_slam_viewer
        src/KeyFrameDisplay.cpp
        src/KeyFrameGraphDisplay.cpp
        src/main_viewer.cpp
        src/PointCloudViewer.cpp
        src/settings.cpp
        )
add_dependencies(lsd_slam_viewer lsd_slam_gencfg)

target_include_directories(lsd_slam_viewer
        PRIVATE
            include
        PUBLIC
            ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(lsd_slam_viewer
        ${QGLVIEWER_LIBRARY}
        Qt4::QtCore
        Qt4::QtOpenGL
        ${roslib_LIBRARIES}
        ${roscpp_LIBRARIES}
        ${rosbag_LIBRARIES}
        ${OpenGL_LIBRARY}
        opencv_core
        thirdparty::sophus
        Boost::thread
        Eigen3::Eigen
        lsd_slam::messages
        lsd_slam::core::IOWrapper
        )