#include "NavigatorNode.hpp"

/**
 * Entry point for the navigator package.
 */
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NavigatorNode>());
    rclcpp::shutdown();
}

