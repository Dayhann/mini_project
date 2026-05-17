# Mini Project — Autonomous Navigation Simulator

A ROS2 Humble workspace that simulates a basic autonomous navigation system for a rover.
One node generates simulated distance sensor data, and another node uses that data to
make obstacle avoidance decisions.

## Packages

### mini_project_msgs
Custom message definitions used across the project. Defines `SensorData.msg` with
front, left, right, and back distance readings.

### sensor_sim
Simulates four distance sensors (front, left, right, back) and publishes readings
at 2 Hz. The subsystem generates random distances between 0.1 m and 5.0 m to mimic
a rover encountering obstacles in the environment.

### navigator
Subscribes to sensor data and decides on movement commands (forward, backward,
turn left, turn right, stop) using an obstacle avoidance algorithm. The rover
prefers to move forward but will pick a better direction if significantly more space
is available in other directions. Publishes the chosen command on a separate topic.

## Building

```bash
source /opt/ros/humble/setup.bash
cd ~/mini_project
colcon build
```

The messages package must be built first since both `sensor_sim` and `navigator`
depend on it.

## Running

In separate terminals (each sourced):

```bash
source /opt/ros/humble/setup.bash
cd ~/mini_project
source install/setup.bash

# Terminal 1 — start the sensor simulator
ros2 run sensor_sim sensor_sim_node

# Terminal 2 — start the navigator
ros2 run navigator navigator_node
```

## Topics

| Topic                        | Type                               | Description                 |
|------------------------------|------------------------------------|-----------------------------|
| `sensor_sim/sensor_data`     | `mini_project_msgs/msg/SensorData` | Simulated distance readings |
| `navigator/movement_command` | `std_msgs/msg/String`              | Movement decisions          |
