# Matter over Thread Training Kit

This workspace contains a module-based documentation set for learning Matter and Thread for smart-home IoT systems.

## Contents
- HTML pages for 8 training modules
- Runnable C++ examples in the src folder
- Hardware and tool recommendations for ESP32, nRF, Raspberry Pi, CHIP Tool, and Wireshark

## Build and run examples
On Windows, use a C++ compiler such as g++ from MinGW or MSYS2:

```bash
g++ src/matter_intro_demo.cpp -o matter_intro_demo
matter_intro_demo.exe
```

```bash
g++ src/thread_role_demo.cpp -o thread_role_demo
thread_role_demo.exe
```

## Hardware and purchase links
- ESP32: https://www.espressif.com/en/products/socs/esp32
- nRF52840 DK: https://www.nordicsemi.com/Products/Development-hardware/nRF52840-DK
- Raspberry Pi: https://www.raspberrypi.com/products/
- OpenThread: https://openthread.io/
- Matter SDK / Connected Home IP: https://github.com/project-chip/connectedhomeip
