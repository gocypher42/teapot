add_executable(${PROJECT_NAME} main.cpp 
                               directory.cpp
                               file.cpp
                               file_system_node.cpp
                               tea_pot.cpp 
                               templates.cpp 
                               tea_pot_args.cpp
                               tea_pot_args_parser.cpp)

target_link_libraries(${PROJECT_NAME} fmt 
                                      argparse
                                      spdlog)
