
cmake_minimum_required(VERSION 2.8.3)
project(review)
find_package(catkin REQUIRED COMPONENTS  roscpp )
catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES hello
        #  CATKIN_DEPENDS roscpp rospy std_msgs
        #  DEPENDS system_lib
)

include_directories(
        #include

        ${catkin_INCLUDE_DIRS})
add_executable(hello hello.cpp)
target_link_libraries(hello ${catkin_LIBRARIES} )



