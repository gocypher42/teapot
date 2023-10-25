add_library(project_builder project_builder.cpp
                            project_dir.cpp
                            project_tree.cpp
                            project_file.cpp)

target_link_libraries(project_builder fmt)
