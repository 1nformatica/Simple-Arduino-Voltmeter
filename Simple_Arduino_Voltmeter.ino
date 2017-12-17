#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> // Graphics Library
#include <Adafruit_SSD1306.h> //OLED Library
           

int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 1000000.0; // resistance of R1 (1M)
float R2 = 100000.0; // resistance of R2 (100K) 
int value = 0;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup(){
   Serial.begin(9600);
   pinMode(analogInput, INPUT);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
   display.clearDisplay();  // Clear the buffer.
   display.setTextSize(2);   // text display Voltmeter
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   display.print("Volt Meter");
   display.display();
   display.setTextSize(2);
   display.setTextColor(WHITE);
   display.print("Vin = ");
   display.display();
   Serial.print("got this far!"); 

}
void loop(){
   value = analogRead(analogInput); // read analog input
   vout = (value * 5.0) / 1024.0; // 
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;// make zero
   
} 
   display.setTextSize(2);   // text display Voltmeter
   display.setTextColor(WHITE,BLACK);
   display.setCursor(70,18);
   display.print(vin);
   display.setTextColor(WHITE);
   display.setCursor(70,18);
   display.print(vin);
   display.display();
   delay(500);
}
   
