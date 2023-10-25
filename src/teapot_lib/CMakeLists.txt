add_library(teapot_lib STATIC teapot.cpp 
                              teapot_args.cpp
                              teapot_args_parser.cpp
                              project_builder.cpp
                              project_dir.cpp
                              templates.cpp)

target_link_libraries(teapot_lib fmt 
                                 argparse)
