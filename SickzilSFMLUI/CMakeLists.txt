# CMakeList.txt : CMake project for SickzilSFMLUI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(SFML COMPONENTS system window graphics REQUIRED)

file(GLOB PROJ_SOURCES 
		  includes/*.hpp
		  includes/sub_window.hpp
		  *.cpp
		  common/*.cpp)

message(${PROJ_SOURCES})
add_executable (SickzilSFMLUI WIN32 ${PROJ_SOURCES})

target_link_libraries(SickzilSFMLUI PRIVATE sfml-system sfml-window sfml-graphics)

