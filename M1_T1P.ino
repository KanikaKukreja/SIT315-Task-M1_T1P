// C++ code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

//defining pins
const int trigger_pin = 9;
const int echo_pin = 10;
//
long duration;
int distance_in_cm, distance_in_inch;
void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.init();
  lcd.backlight();
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);//delay for 2 microseconds
  
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);// delay for 10 microseconds 
  
  digitalWrite(trigger_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  
  distance_in_cm = duration * 0.034 / 2;
  distance_in_inch = duration * 0.0133 / 2;
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distance_in_cm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance_in_inch);
  lcd.print(" inch");
  delay(10);
}
