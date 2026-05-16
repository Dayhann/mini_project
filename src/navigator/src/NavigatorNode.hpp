#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "mini_project_msgs/msg/sensor_data.hpp"
#include "NavigatorSubsystem.hpp"

#include <memory>

/**
 * ROS2 node that subscribes to sensor data and publishes movement commands.
 *
 * Receives SensorData messages from the sensor_sim node, passes the
 * readings through the NavigatorSubsystem to decide on a movement, and
 * publishes the resulting command as a String message.
 */
class NavigatorNode : public rclcpp::Node {
    public:
        NavigatorNode();

    private:
        void sensorCallback(const mini_project_msgs::msg::SensorData& msg);

        NavigatorSubsystem m_subsystem;
        rclcpp::Subscription<mini_project_msgs::msg::SensorData>::SharedPtr m_subscription;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_commandPublisher;
};
