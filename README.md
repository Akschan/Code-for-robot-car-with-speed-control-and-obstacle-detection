# Code for robot car with speed control and obstacle detection
## Tested using Proteus 8:
### Circuit designed:
![Circuit](https://github.com/Akschan/Programme-pour-une-voiture-aver-detection-d-obstacle/blob/main/images/Circuit_design.png)

# LCD:
lcd is in 4 bit mode as follows:
- **Register Selector pin** = PA2.
- **Read/Write** to Ground = Always Write.
- **Enable pin** = PA4.
- **Data Pins** = PA5,PA6,PA7,PA8.

# Motor Driver:
- each 2 motors has 1 pair of direction Pins so when an obstacle is detected I can turn the Robot in a Direction away from it.
- All the motors are diver by the same PID output to have the same speed output.
- I used only one motor with Encoder to calculate the speed ***ALL MOTORS ARE IDENTICAL***.
- I used a TIMER in encoder mode to capture the speed on the motor and feed it to the PID Controller.

# Sensor:
- unfortunatly I couldn't Simulate a sensor so I had to make a pin (**PD2**) as an input simulating when an obstacle is detected.
# Video Test:


https://user-images.githubusercontent.com/63216504/168444690-4ff9d672-a21d-4146-9671-b1ced20520d5.mp4

