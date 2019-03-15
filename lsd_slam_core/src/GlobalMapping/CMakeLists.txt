cmake_minimum_required(VERSION 3.6)

find_package(g2o REQUIRED)

add_library(GlobalMapping STATIC
        src/FabMap.cpp
        src/g2oTypeSim3Sophus.cpp
        src/KeyFrameGraph.cpp
        src/TrackableKeyFrameSearch.cpp
        )

add_library(lsd_slam_core::GlobalMapping ALIAS GlobalMapping)

target_include_directories(GlobalMapping
        PUBLIC
            include
        PRIVATE
            /usr/local/include/g2o/EXTERNAL/csparse/
        )

foreach(x ${g2o_LIBRARIES})
    message("   ${x}")
endforeach()

target_link_libraries(GlobalMapping
        lsd_slam_core::util
        g2o::core
        g2o::solver_pcg
        g2o::solver_csparse
        g2o::types_sba
        )