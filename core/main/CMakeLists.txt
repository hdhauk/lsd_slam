cmake_minimum_required(VERSION 3.6)

find_package(Boost COMPONENTS thread REQUIRED)
find_package(OpenCV REQUIRED CONFIG)
find_package(Eigen3 REQUIRED CONFIG)
find_package(X11 REQUIRED)
find_package(roscpp REQUIRED CONFIG)
find_package(g2o REQUIRED)
find_package(roslib REQUIRED CONFIG)


add_executable(live_odometry
        src/main_live_odometry.cpp
        src/LiveSLAMWrapper.cpp
        src/SlamSystem.cpp
        )
add_executable(lsd_slam::live_odometry ALIAS live_odometry)


target_include_directories(live_odometry
        PRIVATE
        src
        thirdparty/Sophus
        ${X11_INCLUDE_DIR}
        ${roscpp_INCLUDE_DIRS}
        )

target_link_libraries(live_odometry
        Boost::thread
        opencv_core
        opencv_imgcodecs
        ${X11_LIBRARIES}
        ${roscpp_LIBRARIES}
        ${roslib_LIBRARIES}
        thirdparty::sophus
        Eigen3::Eigen
        lsd_slam::core::util
        lsd_slam::core::IOWrapper
        lsd_slam::core::Tracking
        )


add_executable(on_images
        src/main_on_images.cpp
        src/LiveSLAMWrapper.cpp
        src/SlamSystem.cpp
        )
add_executable(lsd_slam::on_images ALIAS on_images)

target_include_directories(on_images
        PRIVATE
            src
        )
target_link_libraries(on_images
        ${roslib_LIBRARIES}
        lsd_slam::core::IOWrapper
        )