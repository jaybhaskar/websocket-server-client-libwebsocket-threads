cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -fpermissive")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBWEBSOCKETS REQUIRED libwebsockets)


include_directories(${LIBWEBSOCKETS_INCLUDE_DIRS})
link_directories(${LIBWEBSOCKETS_LIBRARY_DIRS})

project(websocket-server-client)
add_executable(${PROJECT_NAME} "main.cpp" "websocketserver.cpp" "websocketserver.h" "serverinterface.h"
    "tvpluswebsocketclient.cpp" "tvpluswebsocketclient.h" "websocket.cpp" "websocket.h" "websocketimpl.cpp"
    "websocketimpl.h")
target_link_libraries(${PROJECT_NAME} ${LIBWEBSOCKETS_LIBRARIES} -pthread)
