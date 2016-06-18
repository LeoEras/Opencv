cmake_minimum_required(VERSION 2.8)
project( AppleDetector )
find_package( OpenCV )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( AppleDetector apples.cpp )
target_link_libraries( AppleDetector ${OpenCV_LIBS} )


