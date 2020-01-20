cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)

add_subdirectory(node)
list(APPEND EXTRA_LIBS node)

add_subdirectory(pub)
list(APPEND EXTRA_LIBS publisher)

add_executable(main main.cpp)
target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${EXTRA_LIBS})

target_include_directories(main PUBLIC
                           "${PROJECT_SOURCE_DIR}/include"
                           "${PROJECT_SOURCE_DIR}/pub"
                           "${PROJECT_SOURCE_DIR}/sub"
                           )