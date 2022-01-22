cmake_minimum_required(VERSION 3.21)
project(PocoSamples)

set(CMAKE_CXX_STANDARD 14)
#find_package(Poco::Foundation)
add_executable(NotificationQueue main.cpp)
target_link_libraries(NotificationQueue PUBLIC Poco::Foundation)
