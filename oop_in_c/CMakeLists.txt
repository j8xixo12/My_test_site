project(main)
set(CMAKE_C_COMPILER /usr/bin/gcc)

add_subdirectory(triangle)
list(APPEND EXTRA_LIBS triangle)

add_subdirectory(rectangle)
list(APPEND EXTRA_LIBS rectangle)

add_subdirectory(shape)
list(APPEND EXTRA_LIBS shape)

add_executable(main main.c)

target_compile_options(main PUBLIC "-g")
target_link_libraries(main ${EXTRA_LIBS})