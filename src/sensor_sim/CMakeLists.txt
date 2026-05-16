cmake_minimum_required(VERSION 3.8)
project(sensor_sim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(mini_project_msgs REQUIRED)

add_executable(sensor_sim_node
  src/main.cpp
  src/SensorSimNode.cpp
  src/SensorSimSubsystem.cpp
)

ament_target_dependencies(sensor_sim_node rclcpp mini_project_msgs)

install(TARGETS sensor_sim_node DESTINATION lib/${PROJECT_NAME})

ament_package()
