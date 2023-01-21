add_executable(Test main.cpp)
target_link_libraries(Test SimpleUuid::uuid GTest::gtest GTest::gtest_main)
add_test(NAME Test COMMAND Test)