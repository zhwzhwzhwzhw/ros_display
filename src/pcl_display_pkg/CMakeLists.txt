cmake_minimum_required(VERSION 3.0.2)
project(pcl_display_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  pcl_ros
  pcl_conversions
  sensor_msgs
)

find_package(PCL REQUIRED COMPONENTS common visualization)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

link_directories(
  ${PCL_LIBRARY_DIRS}
)

add_definitions(
  ${PCL_DEFINITIONS}
)

catkin_package()

add_executable(pcl_display_node src/pcl_display_node.cpp)

target_link_libraries(pcl_display_node
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
)
