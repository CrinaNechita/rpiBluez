# Set up

This project is part of the Theft Alert System by Crina Nechita and Nestoras Karydas.
This project uses a Raspberry pi as a peripheral that accepts alerts and acts as an actuator.
Libraries used include bluez_inc by Weliem (https://github.com/weliem/bluez_inc/tree/main)
These instructions are meant to set up the project on a Raspberry pi zero 2 W. Set up on different microcontrollers may differ.

## Dependencies for the Raspberry Pi
Assuming you have a default installation, you will need to install CMake and GLib:
```
sudo apt install -y cmake
sudo apt install -y libglib2.0-dev
```

## Pinout
DO NOT forget the resistors

|        | GPIO | Physical pin |
|--------|------|--------------|
| LED 1  | 17   | 11           |
| LED 2  | 27   | 13           |
| LED 3  | 22   | 15           |
| LED 4  | 23   | 16           |
| Buzzer | 18   | 12           |

## Building and running the code

```
cd examples/peripheral
cmake .
cmake --build .
./peripheral
```
Make sure the advertising starts before scanning for the peripheral. Check the debug logs.
