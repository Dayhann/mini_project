#pragma once

#include <string>

/**
 * Decides movement commands based on distance sensor readings.
 *
 * Implements an obstacle avoidance algorithm using four sensors. The
 * rover prefers forward motion but yields if another direction has
 * significantly more space. When forward is blocked, it picks the
 * best alternative among left, right, and back. This class has no
 * dependency on ROS2.
 */
class NavigatorSubsystem {
    public:
        NavigatorSubsystem();

        /**
         * The possible movement commands the navigator can issue.
         */
        enum class Command {
            MoveForward,
            MoveBackward,
            TurnLeft,
            TurnRight,
            Stop
        };

        Command decideMovement(double frontDistance, double leftDistance,
                               double rightDistance, double backDistance);

        static std::string commandToString(Command command);

    private:
        double m_safeDistance;
};
