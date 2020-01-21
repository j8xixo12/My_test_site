add_library(rectangle rectangle.c)
target_compile_options(rectangle PUBLIC "-g")
target_include_directories(rectangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                            ${PROJECT_SOURCE_DIR}/shape)