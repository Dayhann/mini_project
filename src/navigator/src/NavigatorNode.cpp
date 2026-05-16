#include "NavigatorNode.hpp"

/**
 * Subscribes to "sensor_sim/sensor_data" and publishes on
 * "navigator/movement_command".
 */
NavigatorNode::NavigatorNode() : rclcpp::Node("navigator_node") {
    m_subscription = create_subscription<mini_project_msgs::msg::SensorData>(
        "sensor_sim/sensor_data", 10,
        [this](const mini_project_msgs::msg::SensorData& msg) { sensorCallback(msg); });

    m_commandPublisher = create_publisher<std_msgs::msg::String>(
        "navigator/movement_command", 10);

    RCLCPP_INFO(get_logger(), "NavigatorNode started — listening for sensor data");
}

/**
 * Subscription callback — delegates to the subsystem and publishes
 * the resulting command.
 */
void NavigatorNode::sensorCallback(const mini_project_msgs::msg::SensorData& msg) {
    auto command = m_subsystem.decideMovement(
        msg.front_distance, msg.left_distance, msg.right_distance,
        msg.back_distance);

    std::string commandStr = NavigatorSubsystem::commandToString(command);

    RCLCPP_INFO(get_logger(),
        "Received — Front: %.2f m, Left: %.2f m, Right: %.2f m, Back: %.2f m -> %s",
        msg.front_distance, msg.left_distance, msg.right_distance,
        msg.back_distance, commandStr.c_str());

    auto commandMsg = std_msgs::msg::String();
    commandMsg.data = commandStr;
    m_commandPublisher->publish(commandMsg);
}
