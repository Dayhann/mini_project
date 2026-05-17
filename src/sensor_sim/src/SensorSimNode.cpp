#include "SensorSimNode.hpp"
#include <chrono>
/**
 * Publishes on "sensor_sim/sensor_data" with a 500ms wall timer.
 */
SensorSimNode::SensorSimNode() : rclcpp::Node("sensor_sim_node") {
    using namespace std::chrono_literals;
    m_publisher = create_publisher<mini_project_msgs::msg::SensorData>(
        "sensor_sim/sensor_data", 10);
        
    m_timer = create_wall_timer(500ms, [this] { timerCallback(); });
    RCLCPP_INFO(get_logger(), "SensorSimNode started — publishing sensor data");
}
/**
 * Timer callback — samples the subsystem and publishes the result.
 */
void SensorSimNode::timerCallback() {
    auto reading = m_subsystem.generateReading();

    auto message = mini_project_msgs::msg::SensorData();
    message.front_distance = reading.frontDistance_m;
    message.left_distance = reading.leftDistance_m;
    message.right_distance = reading.rightDistance_m;
    message.back_distance = reading.backDistance_m;

    RCLCPP_INFO(get_logger(),
        "Publishing — Front: %.2f m, Left: %.2f m, Right: %.2f m, Back: %.2f m",
        message.front_distance, message.left_distance, message.right_distance,
        message.back_distance);
    m_publisher->publish(message);
}
