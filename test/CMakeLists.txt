if(BUILD_TESTING)
    add_executable(teapot_test project_file_test.cpp)
    target_include_directories(teapot_test PUBLIC ../src/project_builder/)
    target_link_libraries(teapot_test PRIVATE project_builder)

    target_link_libraries(teapot_test PRIVATE GTest::gtest_main)

    include (GoogleTest)
    gtest_discover_tests(teapot_test)
endif()
