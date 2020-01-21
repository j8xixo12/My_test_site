add_library(shape shape.c)
target_compile_options(shape PUBLIC "-g")
target_include_directories(shape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})