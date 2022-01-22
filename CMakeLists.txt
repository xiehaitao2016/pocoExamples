cmake_minimum_required(VERSION 3.21)
project(PocoSamples)

set(CMAKE_CXX_STANDARD 14)
#find_package(Poco::Foundation)
add_subdirectory(thirdparty/poco)

add_subdirectory(samples/foundation)