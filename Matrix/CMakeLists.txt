project(main)

add_subdirectory(matrix)
list(APPEND EXTRA_LIBS Matrix)

add_executable(main main.cpp)

target_link_libraries(main ${EXTRA_LIBS})