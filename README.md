# Specialized-Line-Following-Robot
<!-- Put zine image here -->
---
This is a specialized line follower robot with a custom built 8 Sensor Array, using tcrt5000 IR sensors, for sensing the lines. In addition to basic line following, the robot has a specialized function for dispensing pellets into designated spots, at different heights, for which it uses a scissor lift along with a conveyor belt system, powered by high torque n20 motors. 

## About

<!-- This Project is powered by an 11.1v 3300 mah Li-po battery. It has 3 power rails; 11.1v, 5v, and <!- 3rd power line here ->, it uses two mini mp2307 to convert the voltages.-->
### 1. Robot function 
 <img width="380" height="262" alt="image" src="https://github.com/user-attachments/assets/e9745772-ab76-4bc8-9be9-fd66cdfe5376" />
 <img width="248" height="262" alt="image" src="https://github.com/user-attachments/assets/20356695-cae1-4f34-8d69-1ed962f46949" />

The robot follows a 3cm wide black line on the arena floor, maneuvering intersections & Zig Zag patterns on the arena floor. At Storage rack 1 (S1), a box of 7x7 inches supports the storage rack, with one of four faces colored blue. the robot must go around the box to detect the blue colored face, where the slot openings are present in the form of a 2x2 grid, as seen in the image above. The robot must detect strips below the slots as either blue or red, placing the pellets into the slots marked blue, and skipping over the red ones. The robot then heads to Storage rack 2 (S2), repeating the same procedure. Then, the robot travels through the zig zag pattern and climbs a ramp to reach Storage rack 3 (S3), After sucessful dispensing into designated slots at S3, it parks itself beyond the red line. 

### 2. Body
<img width="1000" height="267" alt="Roboto (3)" src="https://github.com/user-attachments/assets/7e2908aa-9076-4d96-b203-d836954d52ec" />
The body is made of a custom 3d printed Chasis, housing four GA25-370 Motors and a battery on top with the IR Sensor Array Mounted to the bottom, Alongside extruded platforms for inserts.

### IR Sensor Array
<!-- but ss of 3d model from kicad -->
A custom built 8 channel analog IR sensor array bulit from tcrt5000 sensors. 

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
