# EnergyMeter
Uses an Arduino Nano, A generic OLED screen, and ACS712 current sensor to measure the power consumed by an appliance, and displays at a rate of 5Hz on the screen.

## The Need of this Project
We all must have surely doubted our power companies about their billing and measurments correctness. Also to calculate the idle power consumption of devices, I attempted to create my own energy meter, which works pretty fine.
***

## Equipments and their Interfacing
All general components like protoboard, wires, solder et cetra, are assumed to be considered basics and not mentioned henceforth.\

1. **Arduino Nano**:\
  THis will be MICROCONTROLLER for this project.\
  This basically reads input, manages calculations, and shows output.\
  The hardware is explained in a later section.
  
2. **ACS712**:\
  The Current sensor used in this project.\
  This is an analog sensor, and needs to be connected on an analog input port.\
  We connected the output of ACS712 to the A0 pin of Arduino. 

3. **OLED Display**:\
  Generic single color OLED Display is used for output.\
  Uses I2C Communication protocol. Thus standard connection is prettymuch the maximum we can do.\
  SDA : A4
  SCL : A5
  
4. **Supporting Libraries**:\
  a) **ACS712 - Rob Tillaart**: Is required for measuring the AC current. Found [here](https://github.com/RobTillaart/ACS712).\
  b) **OLED Libraries**: The standard libraries by Adafruit, to drive the OLED screen.
***

