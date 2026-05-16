#pragma once

#include "rclcpp/rclcpp.hpp"
#include "mini_project_msgs/msg/sensor_data.hpp"
#include "SensorSimSubsystem.hpp"

#include <memory>

/**
 * ROS2 node that publishes simulated sensor data.
 *
 * Uses the SensorSimSubsystem to generate distance readings and
 * publishes them as SensorData messages on the sensor_sim/sensor_data
 * topic at a fixed interval.
 */
class SensorSimNode : public rclcpp::Node {
    public:
        SensorSimNode();

    private:
        void timerCallback();

        SensorSimSubsystem m_subsystem;
        rclcpp::Publisher<mini_project_msgs::msg::SensorData>::SharedPtr m_publisher;
        rclcpp::TimerBase::SharedPtr m_timer;
};
