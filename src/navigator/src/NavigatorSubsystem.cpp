#include "NavigatorSubsystem.hpp"

#include <algorithm>

/**
 * Sets m_safeDistance to 1.0 metre.
 */
NavigatorSubsystem::NavigatorSubsystem()
    : m_safeDistance(1.0) {
}

/**
 * Determines the best movement command given four distance readings.
 *
 * Logic:
 *   - If front is clear and no other direction has more than 2x the
 *     space, move forward. Otherwise, fall through to pick the best
 *     direction.
 *   - If front is blocked, pick the direction with the most space
 *     among left, right, and back (must still clear the safe threshold).
 *   - If no direction clears the threshold, stop.
 *
 * @param frontDistance Obstacle distance ahead (metres).
 * @param leftDistance  Obstacle distance to the left (metres).
 * @param rightDistance Obstacle distance to the right (metres).
 * @param backDistance  Obstacle distance behind (metres).
 *
 * @return The chosen Command.
 */
NavigatorSubsystem::Command NavigatorSubsystem::decideMovement(
        double frontDistance, double leftDistance, double rightDistance,
        double backDistance) {

    bool frontClear = frontDistance >= m_safeDistance;

    if (frontClear) {
        // NOTE: Prefer forward, but if another direction has more than
        // 2x the space, fall through to the comparison logic below.
        double bestAlternative = std::max({leftDistance, rightDistance, backDistance});
        if (bestAlternative <= 2.0 * frontDistance) {
            return Command::MoveForward;
        }
    }

    double bestDistance = std::max({leftDistance, rightDistance, backDistance});

    if (bestDistance >= m_safeDistance) {
        if (bestDistance == backDistance) {
            return Command::MoveBackward;
        }
        if (leftDistance >= rightDistance) {
            return Command::TurnLeft;
        }
        return Command::TurnRight;
    }

    return Command::Stop;
}

/**
 * Maps a Command value to its string representation.
 */
std::string NavigatorSubsystem::commandToString(Command command) {
    switch (command) {
        case Command::MoveForward:  return "MOVE_FORWARD";
        case Command::MoveBackward: return "MOVE_BACKWARD";
        case Command::TurnLeft:     return "TURN_LEFT";
        case Command::TurnRight:    return "TURN_RIGHT";
        case Command::Stop:         return "STOP";
        default:                   return "UNKNOWN";
    }
}
