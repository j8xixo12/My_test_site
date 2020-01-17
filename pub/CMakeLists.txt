add_library(publisher publisher.cpp)

target_include_directories(publisher
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
          "${PROJECT_SOURCE_DIR}/include"
          "${PROJECT_SOURCE_DIR}/pub"
          "${PROJECT_SOURCE_DIR}/sub"
          )