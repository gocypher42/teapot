add_library(project_builder project_builder.cpp
                            directory.cpp
                            project_tree.cpp
                            node.cpp
                            file.cpp)

target_link_libraries(project_builder fmt)
