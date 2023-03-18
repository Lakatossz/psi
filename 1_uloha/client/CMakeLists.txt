cmake_minimum_required(VERSION 3.22)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client main.cpp src/Client.cpp src/other/Other.cpp)
target_link_libraries(client)
install(TARGETS client RUNTIME DESTINATION bin)
