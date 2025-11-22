cmake_minimum_required(VERSION 3.1)
project(rbdl)
add_definitions(-std=c++11)

include(GNUInstallDirs) # Provides standard installation directories

find_package(Eigen3 REQUIRED HINTS ${Eigen3_HINT})
find_package(Boost REQUIRED COMPONENTS system thread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-local-typedefs -Wall -Wextra  -fPIC -g -O0")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -pthread  -Wno-unused-local-typedefs  -fPIC -g -O0")

FILE (GLOB SRC_URDF  urdf/*.cpp)
FILE (GLOB SRC_RBDL  rbdl/*.cc)
FILE (GLOB SRC_UTILS utils/*.cpp)
FILE (GLOB SRC_MODEL model/*.cpp)

FILE (GLOB INC_URDF  urdf/*.h)
FILE (GLOB INC_RBDL  rbdl/*.h)
FILE (GLOB INC_UTILS utils/*.hpp)
FILE (GLOB INC_MODEL model/*.hpp)

add_library(RBDL
            SHARED
            ${SRC_RBDL}
            ${SRC_URDF}
            ${SRC_UTILS}
            ${SRC_MODEL}
)

include_directories ( ${EIGEN3_INCLUDE_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )
include_directories ("${PROJECT_SOURCE_DIR}/")

# Install the shared library and its public header
install(TARGETS RBDL
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # Install the shared library to the standard library directory
)
install(FILES ${INC_URDF}
        DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/rdbl/urdf)

install(FILES ${INC_RBDL}
        DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/rdbl/rbdl)

install(FILES ${INC_UTILS}
        DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/rdbl/utils)

install(FILES ${INC_MODEL}
        DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/rdbl/model)

install(TARGETS
        RBDL
        EXPORT RBDLConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
export(TARGETS
        RBDL
        FILE "${CMAKE_CURRENT_BINARY_DIR}/RBDLConfig.cmake"
)
install(EXPORT
        RBDLConfig
        DESTINATION "${CMAKE_INSTALL_DATADIR}/rbdl/cmake"
)
add_subdirectory(example)
#target_compile_options(RBDL PRIVATE -Wall -Wextra -pedantic -Werror -Wno-unused-function)