add_executable(gilded_rose main.cpp GildedRoseTests.cpp)
target_link_libraries(gilded_rose PRIVATE doctest)

doctest_discover_tests(gilded_rose)
