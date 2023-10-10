add_library(teapot_lib STATIC teapot.cpp 
                              teapot_args.cpp
                              teapot_args_parser.cpp
                              templates.cpp)

target_include_directories(teapot_lib PRIVATE ../file_system)

target_link_libraries(teapot_lib fmt 
                                 argparse
                                 file_system)
