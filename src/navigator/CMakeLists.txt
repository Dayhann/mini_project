cmake_minimum_required(VERSION 3.8)
project(navigator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(mini_project_msgs REQUIRED)

add_executable(navigator_node
  src/main.cpp
  src/NavigatorNode.cpp
  src/NavigatorSubsystem.cpp
)

ament_target_dependencies(navigator_node rclcpp std_msgs mini_project_msgs)

install(TARGETS navigator_node DESTINATION lib/${PROJECT_NAME})

ament_package()
