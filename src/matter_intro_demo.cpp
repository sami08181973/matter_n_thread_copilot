#include <iostream>
#include <string>
#include <vector>

struct Device {
    std::string name;
    std::string transport;
    std::string role;
};

int main() {
    std::vector<Device> ecosystem = {
        {"Smart Light", "Thread", "Leaf device"},
        {"Smart Plug", "Wi-Fi", "Controller-connected"},
        {"Temperature Sensor", "BLE", "Sensor node"}
    };

    std::cout << "Matter ecosystem demo\n";
    for (const auto& device : ecosystem) {
        std::cout << device.name << " uses " << device.transport
                  << " as " << device.role << "\n";
    }

    return 0;
}
