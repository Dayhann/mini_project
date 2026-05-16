#include "SensorSimNode.hpp"

/**
 * Entry point for the sensor_sim package.
 */
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SensorSimNode>());
    rclcpp::shutdown();
}
