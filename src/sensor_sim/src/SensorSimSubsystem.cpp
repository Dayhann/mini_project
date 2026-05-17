#include "SensorSimSubsystem.hpp"

/**
 * Seeds the Mersenne Twister engine via std::random_device and sets
 * the uniform distribution range to [0.1, 5.0] metres.
 */
SensorSimSubsystem::SensorSimSubsystem()
    : m_randomEngine(std::random_device{}()),
      m_distribution(0.1, 5.0) {
}

/**
 * @return A SensorReading with four independently sampled distance values.
 */
SensorSimSubsystem::SensorReading SensorSimSubsystem::generateReading() {
    SensorReading reading;
    reading.frontDistance_m = generateDistance();
    reading.leftDistance_m = generateDistance();
    reading.rightDistance_m = generateDistance();
    reading.backDistance_m = generateDistance();
    return reading;
}

/**
 * @return A single sample from m_distribution.
 */
double SensorSimSubsystem::generateDistance() {
    return m_distribution(m_randomEngine);
}
