cmake_minimum_required(VERSION 3.6)


add_library(GlobalMapping
        src/FabMap.cpp
        src/g2oTypeSim3Sophus.cpp
        src/KeyFrameGraph.cpp
        src/TrackableKeyFrameSearch.cpp
        )

add_library(lsd_slam_core::GlobalMapping ALIAS GlobalMapping)

target_include_directories(GlobalMapping
        PUBLIC
            include
        )

target_link_libraries(GlobalMapping
        lsd_slam_core::util
        )