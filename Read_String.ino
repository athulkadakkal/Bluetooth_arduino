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
    // Read a string from Bluetooth
    String receivedString = readStringFromBluetooth();
    Serial.println("Received from Bluetooth: " + receivedString);
  }

  // Check if data is available to read from the serial monitor
  if (Serial.available()) {
    // Read a string from the serial monitor
    String inputString = readStringFromSerial();
    Serial.println("Sending to Bluetooth: " + inputString);
    BTSerial.println(inputString); // Send the string to Bluetooth
  }
}

String readStringFromBluetooth() {
  String content = "";
  char character;
  while (BTSerial.available()) {
    character = BTSerial.read();
    content += character;
    delay(10); // Give some time for other characters to arrive
  }
  return content;
}

String readStringFromSerial() {
  String content = "";
  char character;
  while (Serial.available()) {
    character = Serial.read();
    content += character;
    delay(10); // Give some time for other characters to arrive
  }
  return content;
}
