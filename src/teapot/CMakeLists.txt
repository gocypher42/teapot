add_executable(teapot teapot_app.cpp
                      teapot.cpp 
                      teapot_args.cpp
                      teapot_args_parser.cpp
                      project_builder.cpp
                      project_dir.cpp
                      project_tree.cpp
                      project_file.cpp
                      templates.cpp)

target_link_libraries(teapot fmt 
                             argparse)