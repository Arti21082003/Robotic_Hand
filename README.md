Joystick-Controlled Servo Motor System

This project uses an Arduino to control four SG90 servo motors with two joysticks. Each joystick's X and Y axes control the angle of a corresponding servo motor (0 to 180 degrees). Pressing either joystick's switch resets all servos to their neutral position (90 degrees). The system is ideal for applications like robotic arms, pan-tilt mechanisms, or remote-controlled devices, with real-time angle feedback via the Serial Monitor.

Features
- Joystick Control: Two joysticks (each with X, Y axes, and a switch) control four servos.
- Servo Reset: Pressing either joystick switch resets all servos to 90 degrees.
- Real-Time Feedback: Servo angles are printed to the Serial Monitor for debugging.
- Smooth Operation: 15ms delay ensures stable servo movement and joystick readings.

Hardware Requirements
- Arduino Board: Arduino Uno or compatible microcontroller.
- Servo Motors: Four SG90 servo motors.
- Joysticks: Two analog joysticks (each with X, Y axes and a pushbutton switch).
- Power Supply: External 5V power source for servos (e.g., via a breadboard or servo power rail) to avoid overloading the Arduino.
- Miscellaneous: Jumper wires, breadboard, and a stable USB connection for the Arduino.

Software Requirements
- Arduino IDE: Version 1.8.x or later.
- Library:
  - 'Servo Library: Built into the Arduino IDE for servo control.

No additional library installation is required since 'Servo.h is included with the Arduino IDE.

Wiring
| Component         | Pin Connection                    |
|-------------------|-----------------------------------|
| Servo 1 Signal    | Pin 9 on Arduino                  |
| Servo 2 Signal    | Pin 10 on Arduino                 |
| Servo 3 Signal    | Pin 11 on Arduino                 |
| Servo 4 Signal    | Pin 12 on Arduino                 |
| Servo VCC         | External 5V power source          |
| Servo GND         | Common GND with Arduino           |
| Joystick 1 X-axis | A0 on Arduino                     |
| Joystick 1 Y-axis | A1 on Arduino                     |
| Joystick 1 Switch | Pin 2 on Arduino                  |
| Joystick 2 X-axis | A2 on Arduino                     |
| Joystick 2 Y-axis | A3 on Arduino                     |
| Joystick 2 Switch | Pin 3 on Arduino                  |
| Joystick VCC      | 5V on Arduino                     |
| Joystick GND      | GND on Arduino                    |

Note: Use an external 5V power supply for the servos to prevent Arduino brownouts. Ensure a common ground between the Arduino, servos, and joysticks.

Installation
1. Clone the Repository:
   bash
   git clone https://github.com/Arti21082003/joystick-servo-control.git
   
2. Open the Arduino Sketch:
   - Open 'Joystick_Servo_Control.ino' in the Arduino IDE.

3. Connect Hardware:
   - Wire the components as per the Wiring section.
   - Verify connections to avoid short circuits.

4. Upload the Code:
   - Connect the Arduino to your computer via USB.
   - In the Arduino IDE, select your board (e.g., 'Arduino Uno') and port under 'Tools'.
   - Click 'Upload' to flash the code to the Arduino.

Usage
1. Power On:
   - Connect the Arduino via USB for power and programming.
   - Power the servos with an external 5V supply (connected to a common ground).

2. Control the Servos:
   - Move Joystick 1:
     - X-axis (A0) controls Servo 1 (pin 9) angle.
     - Y-axis (A1) controls Servo 2 (pin 10) angle.
   - Move Joystick 2:
     - X-axis (A2) controls Servo 3 (pin 11) angle.
     - Y-axis (A3) controls Servo 4 (pin 12) angle.
   - Press either joystick switch (pins 2 or 3) to reset all servos to 90 degrees.

3. Debugging:
   - Open the Serial Monitor ('Tools' > 'Serial Monitor') in the Arduino IDE at 9600 baud.
   - View real-time servo angles and reset confirmations.

Customization
- Servo Angles: Adjust the 'map' function ranges in the code (e.g., 'map(joy1XVal, 0, 1023, 0, 180)') to limit servo movement (e.g., '0, 90' for a smaller range).
- Delay Timing: Modify the 'delay(15)' in 'loop()' to change responsiveness (smaller delays increase speed but may cause jitter).
- Pin Assignments: Change 'servoPin1', 'servoPin2', etc., or joystick pins ('joy1X', 'joy1Y', etc.) if using different Arduino pins.

Troubleshooting
- Servos Not Moving:
  - Check servo connections and ensure they’re powered by an external 5V source.
  - Verify servo pins (9, 10, 11, 12) are correctly wired.
- Joystick Not Responding:
  - Confirm joystick pins (A0-A3 for axes, 2-3 for switches) and test analog readings in the Serial Monitor.
  - Ensure 'INPUT_PULLUP' is working for switches; if not, add external pull-up resistors.
- Serial Monitor Issues:
  - Ensure the baud rate is set to 9600 in both the code and Serial Monitor.
- Jittery Servos:
  - Increase the 'delay(15)' value or add a small capacitor across the servo power lines to stabilize voltage.

Acknowledgments
- Arduino community for extensive tutorials and documentation.
- Servo library developers for robust servo control support.

