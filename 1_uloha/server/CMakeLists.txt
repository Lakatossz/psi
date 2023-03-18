cmake_minimum_required(VERSION 3.22)
project(server)

set(CMAKE_CXX_STANDARD 14)

add_executable(server main.cpp src/Server.cpp src/client/Server_Client.cpp src/other/Other.cpp)
target_link_libraries(server)
install(TARGETS server RUNTIME DESTINATION bin)
