cmake_minimum_required(VERSION 3.15)
project(CAL-Proj)

set(CMAKE_CXX_STANDARD 14)

# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
#link_libraries(ws2_32 wsock32)

include_directories(src)
include_directories(Maps)

add_executable(CAL-Proj main.cpp src/Graph/Graph.h src/Graph/MutablePriorityQueue.h src/GraphViewer/connection.cpp src/GraphViewer/connection.h
        src/GraphViewer/edgetype.h src/GraphViewer/graphviewer.cpp src/GraphViewer/graphviewer.h src/Utils/Utils.cpp src/Utils/Utils.h src/Utils/Visualization.cpp
        src/Utils/Visualization.h src/driver.cpp src/driver.h src/passenger.cpp src/passenger.h src/Application.cpp src/Application.h src/gui.cpp src/gui.h)