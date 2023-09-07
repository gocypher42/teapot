add_subdirectory(file_system)
add_subdirectory(teapot_lib)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE teapot_lib)
target_link_libraries(${PROJECT_NAME} teapot_lib)
