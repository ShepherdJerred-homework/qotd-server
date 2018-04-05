cmake_minimum_required(VERSION 3.9)
project(qotd_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(qotd_server main.cpp timestamp.cpp getipaddressinfo.cpp passivesock.cpp udp_recv.cpp udp_send.cpp wait.cpp)