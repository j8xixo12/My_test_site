add_library(node node.cpp)

target_include_directories(node
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
          "${PROJECT_SOURCE_DIR}/include"
          "${PROJECT_SOURCE_DIR}/pub"
          "${PROJECT_SOURCE_DIR}/sub"
          )