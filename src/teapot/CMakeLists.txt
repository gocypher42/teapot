add_executable(teapot teapot_app.cpp
                      teapot.cpp 
                      teapot_args.cpp
                      teapot_args_parser.cpp)

target_include_directories(teapot PRIVATE ../project_builder ../file_templates)

target_link_libraries(teapot fmt argparse project_builder file_templates)
