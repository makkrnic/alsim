cmake_minimum_required(VERSION 2.6)
project(Alsim)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake/Modules")

include_directories("include")

find_package(Threads)

add_definitions(-DBOOST_ALL_DYN_LINK)
find_package(Boost 1.55.0 COMPONENTS
  log
  log_setup
  thread
  system
  REQUIRED
)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(LibNoise REQUIRED)

set(program_name alsim)

add_library(logger logger.cpp)
add_library(voxel voxel.cpp)
add_library(world world.cpp)
add_library(CLIWorldPrinter CLIWorldPrinter.cpp)

add_executable(${program_name} main.cpp)
target_link_libraries(${program_name}
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_LIBRARIES}
  ${LIBNOISE_LIBRARIES}
  logger
  world
  voxel
  CLIWorldPrinter
)
