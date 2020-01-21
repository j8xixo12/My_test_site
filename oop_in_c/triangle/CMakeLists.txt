add_library(triangle triangle.c)
target_compile_options(triangle PUBLIC "-g")
target_include_directories(triangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                           ${PROJECT_SOURCE_DIR}/shape)