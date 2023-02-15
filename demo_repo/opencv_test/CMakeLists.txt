cmake_minimum_required(VERSION 3.0.2)
project(opencv_test)

find_package(catkin REQUIRED COMPONENTS
        cv_bridge
        image_transport
        roscpp
        sensor_msgs
        std_msgs
        )
find_package(OpenCV REQUIRED)

catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES opencv_test
        #  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
        #  DEPENDS system_lib
)

include_directories(
        # include
        ${catkin_INCLUDE_DIRS}
)

include_directories(include ${OpenCV_INCLUDE_DIRS})
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(opencv_test opencv_test_node.cpp)
target_link_libraries(opencv_test ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
#add_dependencies(opencv_test_node opencv_test_gencpp)
