# Specialized-Line-Following-Robot
<img width="1000" height="350" alt="Github (1000 x 350 px)" src="https://github.com/user-attachments/assets/2505a1d1-2fc6-411a-897a-ef4096586d04" />

This is a specialized line follower robot with a custom built 8 Sensor Array, using tcrt5000 IR sensors, for sensing the lines. In addition to basic line following, the robot has a specialized function for dispensing pellets into designated spots, at different heights, for which it uses a scissor lift along with a conveyor belt system, powered by high torque n20 motors. 

## About

<!-- This Project is powered by an 11.1v 3300 mah Li-po battery. It has 3 power rails; 11.1v, 5v, and <!- 3rd power line here ->, it uses two mini mp2307 to convert the voltages.-->
### 1. Robot function 
 <img width="380" height="262" alt="image" src="https://github.com/user-attachments/assets/e9745772-ab76-4bc8-9be9-fd66cdfe5376" />
 <img width="248" height="262" alt="image" src="https://github.com/user-attachments/assets/20356695-cae1-4f34-8d69-1ed962f46949" />
 <img width="350" height="262" alt="image" src="https://github.com/user-attachments/assets/8240cc0f-60f9-4f71-b6c4-30071f7a0a9e" />



The robot follows a 3cm wide black line on the arena floor, maneuvering intersections & Zig Zag patterns on the arena floor. At Storage rack 1 (S1), a box of 7x7 inches supports the storage rack, with one of four faces colored blue. the robot must go around the box to detect the blue colored face, where the slot openings are present in the form of a 2x2 grid, as seen in the image above. The robot must detect strips below the slots as either blue or red, placing the pellets into the slots marked blue, and skipping over the red ones. The robot then heads to Storage rack 2 (S2), repeating the same procedure. Then, the robot travels through the zig zag pattern and climbs a ramp to reach Storage rack 3 (S3), After sucessful dispensing into designated slots at S3, it parks itself beyond the red line. 

### 2. Body
The body consists of three layers. The Base, the Middle, and the top most layer. 
 #### 2.1 The Base
<img width="1000" height="267" alt="Roboto (3)" src="https://github.com/user-attachments/assets/7e2908aa-9076-4d96-b203-d836954d52ec" />
The base is made of a custom 3d printed Chasis, housing four GA25-370 Motors and a battery on top with the IR Sensor Array Mounted to the bottom, Alongside extruded platforms for inserts.

##### 2.1.1 IR Sensor Array
<img width="1000" height="267" alt="Roboto (3)" src="https://github.com/user-attachments/assets/69620467-f48e-4811-88d9-88ecb2af8762" />


<!-- add ss of 3d model from kicad & schematics-->
A custom built 8 channel analog IR sensor array bulit from tcrt5000 sensors. It uses 4.7k & 1k resistors. It also utilizes capacitors & an led that lights up when a sensor is returning a reading, serving as a checker to see if it works. 

#### 2.2 The Middle layer
<img width="1000" height="267" alt="Roboto (1)" src="https://github.com/user-attachments/assets/ca88185c-c398-4899-afee-2318a3a32fdc" />

<!-- add ss of middle layer from onshape, make a banner thing with lables in canva and put it here, layer has, acrylic base, spacers, pcb, hcsr04  -->
The Middle layer is supported by a laser cut acrylic sheet which is screwed on top of the 3d printed chasis using spacers. It consists of a custom built PCB & spacers along with the HC-SR04 ultrasonic sensor for distance measurement. 

##### 2.2.1 PCB
<img width="1000" height="267" alt="Roboto (5)" src="https://github.com/user-attachments/assets/a5bfc7b2-3818-4c51-b98a-3ff3a30cca0e" />
The pcb routes a 3300mah, 11.1v li-po battery pack through two mini MP2307 buck convertor, forming 3 power rails, 11.1v, 5v, and <!-- x volts --> which are used throughout the robot. The PCB houses the STM32F401 Microcontroller with two TB6612FNG motor driver breakout boards, one of which governs the motion of the GA25-370 motors and the other controls the N20 motors used for raising the scissor lift and moving the conveyor belt. It has headers for the IR sensors and the ultrasonic sensor.

#### 2.3 The Top layer
<img width="1000" height="267" alt="Roboto (8)" src="https://github.com/user-attachments/assets/ef8942d1-7bca-4ea0-8299-a159d0f4d139" />
The top layer is also supported by a laser cut acrylic sheet which is screwed on top of the first acrylic sheet, separated by ~1.2in vertically, using spacers and nuts. It is home to the whole Pellet dispensing mechanism, The scissor lift, the Color sensing system and the conveyor belt.

##### 2.3.1 Scissor lift
<!-- add ss of 3d model from onshape, make a banner thing with lables in canva and put it here -->
The scissor lift is made entriely of a 3d printed body. It's movement is controlled by a high torque N20 gear motor which sits on the acrylic sheet. The collapsed height of the lift is <!-- x inches --> and it can streatch upto <!-- y inches --> 

##### 2.3.2 Color sensing system
<!-- add ss of 3d model from onshape, make a banner thing with lables in canva and put it here -->
The color sensing system consists of a Sg90 servo with a TCS34725 color sensor mounted to a 3d printed arm, which is screwed onto Sg90. The arm is <!-- z inches --> in length. The system is fixed underneath the top plate of the scissor lift, so that it can climb with the lift, giving it the ability to detect the color of the strips at both heights vertically. The servo rotates the arm 180° which allows the color sensor to detect both heights laterally. By using this system, the color sensor can cover the strips below each slot in the 2x2 grid.

##### 2.3.3 Conveyor belt
<!-- add ss of 3d model from onshape with the pellets stored and dimensions, make a banner thing with lables in canva and put it here -->
The conveyor belt is made of a 3d printed body. It uses a high torque N20 motor and bearings to rotate the pulleys, which drive the belt. The pellets sit on top of the belt, preloaded before the robot starts. 


## Bill of Materials
| Component | Quantity | Est. Cost (USD) | Purchase Links | 
| :--- | :---: | :--- | :--- | 
| **STM32F401**| 1 | $03.55 |[Link](https://epro.pk/product/stm32f401-development-board/)| 
| **TB6612FNG Motor Driver**| 1 | $02.00 | [Link](https://epro.pk/product/tb6612-drv8833-dual-motor-driver-module-1a-h-bridge-for-arduino-robotics/) | 
| **JGA25-370 Motor kit** | 4 | $24.00 | [Link](https://colgroad.com/product/dc-gear-motor-with-encoder-280rpm-620rpm-ga25-370/) | 
| **QTR 8C IR Sensor Array** | 2 | $04.59 | [Link](https://epro.pk/product/qtr-8rc-line-following-reflectance-ir-sensor-8-channel-line-following-line-tracking-array-module/)| 
| **11.1v 3300mAh Lipo Battery** | 1 | $24.00 | [Link](https://colgroad.com/product/zop-power-3s-11-1v-3300mah-25c-lipo-battery/) | 
| **200 RPM N20 Motors** | 2 | $03.00 | [Link](https://colgroad.com/product/n20-mini-dc-gear-motor-200-600-800-1000-rpm-brand-new/) | 
| **TCS34725 Color Sensor** | 1 | $03.58 | [Link](https://digilog.pk/products/tcs34725-color-sensor-module-pakistan) | 
| **Hc-sr04 Ultrasonic Sensor** | 1 | $00.72 | [Link](https://epro.pk/product/ultrasonic-sensor-hc-sr04-in-pakistan/) | 
| **Bearings** | 1 | $4.30 | [Link](https://epro.pk/product/cnc-v-slot-bearing-open-builds-wheel-pom-mr105zz-625zz-bore-5mm-passive-round-gear/) | 
| **Acrylic sheet** | 2 | $03.23 | [Link](https://www.daraz.pk/products/acrylic-sheet-2mm-size-12x12-2mm-thick-i391245284.html)| 
| **Total Build Cost:** |  | **~$70.00** |
