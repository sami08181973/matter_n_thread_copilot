#include "adas_component.h"

#include <algorithm>
#include <cmath>

namespace adas {

namespace {

bool isCriticalDistance(double distanceMeters) {
    return distanceMeters <= 5.0;
}

bool isWarningDistance(double distanceMeters) {
    return distanceMeters <= 15.0;
}

bool shouldBrake(double distanceMeters, double relativeSpeedMps) {
    return isCriticalDistance(distanceMeters) || (distanceMeters <= 20.0 && relativeSpeedMps > 8.0);
}

bool shouldSteerAssist(const SensorInput& input) {
    return input.isLaneClear && input.isCameraHealthy && input.distanceMeters <= 30.0;
}

}  // namespace

AdasDecision evaluateCollisionRisk(const SensorInput& input) {
    AdasDecision decision{AlertLevel::None, false, false};

    if (!input.isCameraHealthy) {
        decision.alertLevel = AlertLevel::Warning;
        decision.brakeAssistEnabled = false;
        decision.steeringAssistEnabled = false;
        return decision;
    }

    if (isCriticalDistance(input.distanceMeters)) {
        decision.alertLevel = AlertLevel::Critical;
        decision.brakeAssistEnabled = true;
        decision.steeringAssistEnabled = false;
        return decision;
    }

    if (shouldBrake(input.distanceMeters, input.relativeSpeedMps)) {
        decision.alertLevel = AlertLevel::Warning;
        decision.brakeAssistEnabled = true;
        decision.steeringAssistEnabled = false;
        return decision;
    }

    if (shouldSteerAssist(input)) {
        decision.alertLevel = AlertLevel::Warning;
        decision.brakeAssistEnabled = false;
        decision.steeringAssistEnabled = true;
        return decision;
    }

    decision.alertLevel = AlertLevel::None;
    decision.brakeAssistEnabled = false;
    decision.steeringAssistEnabled = false;
    return decision;
}

}  // namespace adas
