#ifndef ADAS_COMPONENT_H
#define ADAS_COMPONENT_H

namespace adas {

enum class AlertLevel {
    None = 0,
    Warning = 1,
    Critical = 2
};

enum class ObstacleStatus {
    Clear = 0,
    Detected = 1
};

struct SensorInput {
    double distanceMeters;
    double relativeSpeedMps;
    bool isLaneClear;
    bool isCameraHealthy;
};

struct AdasDecision {
    AlertLevel alertLevel;
    bool brakeAssistEnabled;
    bool steeringAssistEnabled;
};

AdasDecision evaluateCollisionRisk(const SensorInput& input);

}  // namespace adas

#endif
