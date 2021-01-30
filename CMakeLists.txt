cmake_minimum_required(VERSION 3.14)

project(gilded-rose LANGUAGES CXX)

enable_testing()

include(cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cpmaddpackage(
  NAME
  doctest
  GITHUB_REPOSITORY
  onqtam/doctest
  GIT_TAG
  2.4.1
  GIT_SHALLOW
  TRUE)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

add_compile_options(-Wall -Werror -Wextra -pedantic)

add_subdirectory(src)
