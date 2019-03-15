cmake_minimum_required(VERSION 3.6)

add_library(DataStructures STATIC
        src/Frame.cpp
        src/FrameMemory.cpp
        src/FramePoseStruct.cpp
        )

add_library(lsd_slam::core::DataStructures ALIAS DataStructures)

target_include_directories(DataStructures
        PUBLIC
            include
        )

target_link_libraries(DataStructures
        lsd_slam::core::util
        lsd_slam::core::Tracking
        )