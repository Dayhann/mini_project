#pragma once

#include <random>

/**
 * Simulates a basic set of distance sensors on a rover.
 *
 * Generate random distance readings for front, left, right, and
 * back sensors to mimic the rover to navigate through an environment
 * with obstacles. This class doesnt depend ROS2.
 */
class SensorSimSubsystem {
    public:
        /**
         * Represents a single set of distance readings from all sensors.
         */
        struct SensorReading {
            double frontDistance_m;
            double leftDistance_m;
            double rightDistance_m;
            double backDistance_m;
        };
        SensorSimSubsystem();
        SensorReading generateReading();
    private:
        double generateDistance();
        std::mt19937 m_randomEngine;
        std::uniform_real_distribution<double> m_distribution;
};
