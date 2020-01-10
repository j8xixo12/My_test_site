cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(My_test_site)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Threads REQUIRED)

add_executable(My_test_site main.cpp)
target_link_libraries (My_test_site ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(My_test_site PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           )