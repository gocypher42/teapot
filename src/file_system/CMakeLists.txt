add_library(file_system STATIC directory.cpp
                               file.cpp
                               file_system_node.cpp)

target_link_libraries(file_system fmt spdlog)
