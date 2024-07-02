/*
    HC-05 TX -> Arduino Pin 10 (SoftwareSerial RX)
    HC-05 RX -> Arduino Pin 11 (SoftwareSerial TX)
    HC-05 VCC -> Arduino 5V
    HC-05 GND -> Arduino GND
*/


#include <SoftwareSerial.h>

// Create a software serial object called BTSerial (Bluetooth Serial)
SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() {
  // Start hardware serial communication for debugging
  Serial.begin(9600);
  
  // Start Bluetooth serial communication
  BTSerial.begin(9600);

  // Print a message to the serial monitor
  Serial.println("Arduino with HC-05 Bluetooth Module");
  Serial.println("Waiting for Bluetooth connection...");
}

void loop() {
  // Check if data is available to read from BTSerial
  if (BTSerial.available()) {
    // Read a byte from Bluetooth and print it to the serial monitor
    char c = BTSerial.read();
    Serial.write(c);
    Serial.println();
  }

  // Check if data is available to read from the serial monitor
  if (Serial.available()) {
    // Read a byte from the serial monitor and send it to Bluetooth
    char c = Serial.read();
    BTSerial.write(c);
    Serial.println();
    
  }

  
}
