project(csv-anomaly-detector)
cmake_minimum_required(VERSION 2.8)

list( APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

