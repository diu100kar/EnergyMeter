// Include Wire Library for I2C
#include <Wire.h>

#include <math.h>
 
// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Reset pin not used but needed for library
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include "Arduino.h"

#include "ACS712.h"

ACS712  ACS(A0, 5.0, 1023, 100);
 
void setup() {  
  // Establishing the Serial Connection.
  Serial.begin(9600);
  
  // Start Wire library for I2C protocol.
  Wire.begin();
  
  // Initialize OLED with I2C address 0x3C.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear display, Just in case.
  display.clearDisplay();
  
  //Set the parameters.
  display.setTextColor(WHITE);

  // The Intro sequence.
  intro_device();
  delay(2000);
  intro_support();
  delay(2000);
  intro_info();
  delay(2000);

}


  
void loop() {
  float ienergy,    //Watt
        energy = 0, //Watt 
        ipower,     //Kilo-Watt-hour
        power=0,    //Kilo-Watt-hour
        current,    //Mili-Amperes
        amount;
        
  display.setTextSize(1);
  
  for(;;){
    display.clearDisplay();
    display.setCursor(0,0);

    
    current = abs(ACS.mA_AC());
    //Current value is read from the sensor. Unit is Mili-Amperes.
    
    if(current<1000){
      display.print("Current (mA): ");
      display.println(current);
    }else{
      display.print("Current  (A): ");
      display.println(current/1000);
    }
    

    ienergy = abs(current*0.22);
    // Instantaneous energy in the 20ms window. Watt.
    
    energy = (energy + ienergy)/2;
    // Average of the energy. Fast enough such that this appears as moving average. Watt.
    
    if(energy>1000){
      display.print("Energy  (kW): ");
      display.println(energy/1000);
    }else{
      display.print("Energy   (W): ");
      display.println(energy);
    }
    
    
    ipower = energy/18000000;
    power = power+ipower;

    if(power<1){
      display.print("Power   (Wh): ");
      display.println(abs(power*1000));
    }else{
      display.print("Power  (kWh): ");
      display.println(abs(power));
    }
    
    
    if(power < 100){
      amount = power * 3.46;
    }else if(power < 300){
      amount = power * 7.43;
    }else if(power < 500){
      amount = power * 10.32;
    }else{
      amount = power * 11.71;
    }

    if(amount < 1){
      display.print("Paise  (INR): ");
      display.println(abs(amount*100));
    }else{
      display.print("Rupaye  (INR):");
      display.println(abs(amount));
    }
    
    
    display.display();

  }
      
}

void intro_device(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(28,0);
  display.println("Energy");
  display.setCursor(35,17);
  display.println("Meter");
  display.display();  
}

void intro_support(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("  For Support, Call:\n\nDivyanshu Shambharkar\n    +91-9309946876");
  display.display();  
}

void intro_info(){
  display.clearDisplay();

}
