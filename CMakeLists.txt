cmake_minimum_required(VERSION 3.5)
project(Matrix-Multiplication-Project CXX)
add_executable(mmp src/main.cpp)
install(TARGETS mmp DESTINATION bin)