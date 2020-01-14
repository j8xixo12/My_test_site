cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(My_test_site)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Threads REQUIRED)
find_package(boost REQUIRED)

add_subdirectory(pub)
list(APPEND EXTRA_LIBS publisher)

add_executable(My_test_site main.cpp)
target_link_libraries (My_test_site ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${EXTRA_LIBS})

target_include_directories(My_test_site PUBLIC
                           "${PROJECT_SOURCE_DIR}/include"
                           "${PROJECT_SOURCE_DIR}/pub"
                           "${PROJECT_SOURCE_DIR}/sub"
                           )