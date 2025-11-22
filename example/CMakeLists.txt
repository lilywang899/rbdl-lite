cmake_minimum_required(VERSION 3.26)
project(rbdl_example)

set(CMAKE_CXX_STANDARD 11)

find_package(RBDL REQUIRED })
find_package(Eigen3 REQUIRED HINTS ${Eigen3_HINT})

include_directories (
        /usr/local/include/rdbl
        ${EIGEN3_INCLUDE_DIRS}
)

add_executable(rbdl_example main.cpp)
target_link_libraries(rbdl_example RBDL)

