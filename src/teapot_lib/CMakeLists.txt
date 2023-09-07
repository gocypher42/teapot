add_library(teapot_lib STATIC tea_pot.cpp 
                              templates.cpp 
                              tea_pot_args.cpp
                              tea_pot_args_parser.cpp)

target_include_directories(teapot_lib PRIVATE ../file_system)

target_link_libraries(teapot_lib fmt 
                                 argparse
                                 spdlog
                                 file_system)
