cmake_minimum_required(VERSION 3.16)
project(Platformer VERSION 1.0.7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the build type." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message("${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")
message("${PROJECT_NAME} version: ${PROJECT_VERSION}")

# Copy the res directory to the build directory
# set(RESOURCES_OUTPUT_DIR "${CMAKE_BINARY_DIR}/res")
# add_custom_target(CopyResources ALL
#     COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res ${RESOURCES_OUTPUT_DIR}
#     COMMENT "Copying resources to the build directory."
# )

add_subdirectory(src)
