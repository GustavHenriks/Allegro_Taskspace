cmake_minimum_required (VERSION 2.6)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SDFAST "${CMAKE_CURRENT_SOURCE_DIR}/sdfast/")

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include/)

file(GLOB MODEL_SOURCES "${SDFAST}/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB STACK_SOURCES "example.cpp")

add_library (Model ${MODEL_SOURCES})
add_executable (example ${STACK_SOURCES})
TARGET_LINK_LIBRARIES(example Model)
