#include <iostream>
#include <string>

struct ThreadRole {
    std::string name;
    std::string description;
};

int main() {
    ThreadRole leader{"Leader", "Coordinates network state"};
    ThreadRole router{"Router", "Forwards traffic and extends coverage"};
    ThreadRole endDevice{"End Device", "Low-power node with minimal routing"};

    std::cout << "Thread roles\n";
    std::cout << leader.name << ": " << leader.description << "\n";
    std::cout << router.name << ": " << router.description << "\n";
    std::cout << endDevice.name << ": " << endDevice.description << "\n";
    return 0;
}
