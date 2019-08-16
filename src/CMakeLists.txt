# CMakeList.txt : CMake project for SickzilSFMLUI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(SFML COMPONENTS system window graphics REQUIRED)


add_executable (SickzilSFMLUI "entry.cpp" WIN32 "windows/winmain.cpp")
target_link_libraries(SickzilSFMLUI PRIVATE sfml-system sfml-window sfml-graphics)



