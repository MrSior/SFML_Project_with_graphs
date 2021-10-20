cmake_minimum_required(VERSION 3.19)
project(SFML_View)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFML_View main.cpp)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(SFML_View sfml-graphics sfml-audio)