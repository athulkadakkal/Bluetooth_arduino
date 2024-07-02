# Bluetooth_arduino
hc-05

- **SoftwareSerial Library**: This library allows you to create additional serial ports on digital pins of your choice. This is useful when the hardware serial port (pins 0 and 1) is needed for other purposes, such as debugging or uploading code.

- **BTSerial(10, 11)**: This defines a `SoftwareSerial` object named `BTSerial` with pin 10 as the RX (receive) pin and pin 11 as the TX (transmit) pin.

### Connections

1. **HC-05 TX to Arduino Pin 10**:
   - This connects the transmit (TX) pin of the HC-05 Bluetooth module to pin 10 on the Arduino.
   - Pin 10 is configured as the RX pin in the software serial port (`BTSerial`), meaning it will receive data from the HC-05 module.

2. **HC-05 RX to Arduino Pin 11**:
   - This connects the receive (RX) pin of the HC-05 Bluetooth module to pin 11 on the Arduino.
   - Pin 11 is configured as the TX pin in the software serial port (`BTSerial`), meaning it will send data to the HC-05 module.

3. **HC-05 VCC to Arduino 5V**:
   - This supplies power to the HC-05 module. The HC-05 typically operates at 5V.

4. **HC-05 GND to Arduino GND**:
   - This completes the circuit by connecting the ground (GND) of the HC-05 module to the ground (GND) of the Arduino.

### Summary of Connections
- **HC-05 TX** -> **Arduino Pin 10 (SoftwareSerial RX)**
- **HC-05 RX** -> **Arduino Pin 11 (SoftwareSerial TX)**
- **HC-05 VCC** -> **Arduino 5V**
- **HC-05 GND** -> **Arduino GND**

### Important Note
When using the hardware serial port (pins 0 and 1) for serial communication with the PC (via USB), it’s crucial to use different pins for the HC-05 communication to avoid conflicts. The `SoftwareSerial` library enables this flexibility by allowing you to define alternative pins for serial communication.

With this setup, you can upload code to the Arduino using the hardware serial port and simultaneously communicate with the HC-05 module using the software serial port on pins 10 and 11.
