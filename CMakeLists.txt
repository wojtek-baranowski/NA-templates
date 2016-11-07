cmake_minimum_required(VERSION 3.5)

project(templates-examples CXX)

add_definitions(-DCATCH_CONFIG_MAIN)
add_definitions(-std=c++14 -Wall -Wextra -Wpedantic -Werror)
include_directories(vendor SYSTEM)

add_custom_target(run-all)

add_subdirectory(10-algos)
# add_subdirectory(20-type-template)

