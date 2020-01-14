add_library(publisher publisher.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(publisher
          PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
          "${PROJECT_SOURCE_DIR}/include"
          "${PROJECT_SOURCE_DIR}/pub"
          "${PROJECT_SOURCE_DIR}/sub"
          )