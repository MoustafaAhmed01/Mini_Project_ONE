# Mini_Project_ONE
Vehicle Control System
**Vehicle Control System**

**Specifications:**

1. Prompt user to:
   a. Turn on vehicle engine
   b. Turn off vehicle engine
   c. Quit the system

2. If choosing "Quit the system," exit program.

3. If choosing "Turn off the vehicle engine," return to Requirement 1.

4. Print system state after making a choice.

5. If selecting "Turn on the vehicle engine," display "Sensors set menu" for simulating vehicle sensors readings:
   a. Turn off the engine
   b. Set traffic light color
   c. Set room temperature (Temperature Sensor)
   d. Set engine temperature (Engine Temperature Sensor)

6. While the engine is ON, the "Sensors set menu" is displayed, awaiting an answer.

7. Based on answer from Requirement 6:
   a. If traffic light is 'G', set vehicle speed to 100 km/hr.
   b. If traffic light is 'O', set vehicle speed to 30 km/hr.
   c. If traffic light is 'R', set vehicle speed to 0 km/hr.
   d. If room temperature < 10, turn on AC and set temperature to 20.
   e. If room temperature > 30, turn on AC and set temperature to 20.
   f. If room temperature otherwise, turn off AC.
   g. If engine temperature < 100, turn on "Engine Temperature Controller" and set temperature to 125.
   h. If engine temperature > 150, turn on "Engine Temperature Controller" and set temperature to 125.
   i. If engine temperature otherwise, turn off "Engine Temperature Controller".
   j. If vehicle speed is 30 km/hr:
      i. Turn on AC if it was OFF and set room temperature to: current temperature * (5/4) + 1.
      ii. Turn on "Engine Temperature Controller" if it was OFF and set engine temperature to: current temperature * (5/4) + 1.

8. Display current vehicle state after applying steps 7.a to 7.j:
   a. Engine state: ON/OFF.
   b. AC: ON/OFF.
   c. Vehicle speed.
   d. Room temperature.
   e. Engine Temperature Controller State.
   f. Engine temperature.

9. If selecting "Turn off the engine" in the menu from Requirement 5, return to menu of Requirement 1.
