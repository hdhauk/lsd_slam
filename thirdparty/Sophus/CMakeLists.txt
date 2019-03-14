cmake_minimum_required(VERSION 3.6)


add_library(sophus INTERFACE)
add_library(thirdparty::sophus ALIAS sophus)
target_include_directories(sophus
        INTERFACE
            include
        )