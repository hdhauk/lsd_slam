cmake_minimum_required(VERSION 3.6)

find_package(catkin REQUIRED COMPONENTS message_generation)
add_message_files(
        FILES
        keyframeGraphMsg.msg
        keyframeMsg.msg
)
generate_messages(DEPENDENCIES)


add_library(messages INTERFACE)
add_library(lsd_slam::messages ALIAS messages)

add_dependencies(messages lsd_slam_generate_messages_cpp)

target_include_directories(messages
        INTERFACE
            ${CATKIN_DEVEL_PREFIX}/include
        )