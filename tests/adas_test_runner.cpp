#include "../src/adas/adas_component.h"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

struct TestCase {
    std::string name;
    adas::SensorInput input;
    adas::AlertLevel expectedAlert;
    bool expectedBrake;
    bool expectedSteer;
};

static bool runCase(const TestCase& testCase) {
    auto decision = adas::evaluateCollisionRisk(testCase.input);
    bool passed = decision.alertLevel == testCase.expectedAlert &&
                  decision.brakeAssistEnabled == testCase.expectedBrake &&
                  decision.steeringAssistEnabled == testCase.expectedSteer;

    std::cout << (passed ? "PASS" : "FAIL") << ": " << testCase.name << "\n";
    if (!passed) {
        std::cout << "  expected alert=" << static_cast<int>(testCase.expectedAlert)
                  << ", brake=" << testCase.expectedBrake
                  << ", steer=" << testCase.expectedSteer << "\n";
        std::cout << "  actual   alert=" << static_cast<int>(decision.alertLevel)
                  << ", brake=" << decision.brakeAssistEnabled
                  << ", steer=" << decision.steeringAssistEnabled << "\n";
    }
    return passed;
}

int main() {
    std::vector<TestCase> tests = {
        {"critical distance", {4.0, 2.0, true, true}, adas::AlertLevel::Critical, true, false},
        {"warning due to high speed", {12.0, 9.0, true, true}, adas::AlertLevel::Warning, true, false},
        {"lane assist", {20.0, 2.0, true, true}, adas::AlertLevel::Warning, false, true},
        {"safe clear", {50.0, 1.0, true, true}, adas::AlertLevel::None, false, false},
        {"camera unhealthy", {10.0, 1.0, true, false}, adas::AlertLevel::Warning, false, false},
        {"negative: critical but camera unhealthy", {4.0, 1.0, true, false}, adas::AlertLevel::Warning, false, false},
        {"negative: unsafe lane but no camera", {10.0, 1.0, false, false}, adas::AlertLevel::Warning, false, false},
        {"negative: no alert for far distance", {100.0, 0.5, true, true}, adas::AlertLevel::None, false, false}
    };

    int passed = 0;
    for (const auto& testCase : tests) {
        if (runCase(testCase)) {
            ++passed;
        }
    }

    std::cout << "Passed " << passed << " of " << tests.size() << " tests.\n";
    return passed == static_cast<int>(tests.size()) ? EXIT_SUCCESS : EXIT_FAILURE;
}
