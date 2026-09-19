cmake_minimum_required(VERSION 3.8)

project(ros2_turtlesim)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(circle_publisher src/circle_publisher.cpp)
ament_target_dependencies(
  circle_publisher
  rclcpp
  geometry_msgs
)

install(
  TARGETS
    circle_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
