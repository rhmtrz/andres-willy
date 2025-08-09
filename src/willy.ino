// Include necessary libraries for M5Stack Atom and PS4 controller
#include <M5Atom.h>
#include "atom_willy.h"
#include <PS4Controller.h>

// Initialize servo and motor objects with specific parameters
AtomWilly myServo(1, 400, 2500);
AtomWilly myMotor(3, 400, 2500);

// Define color codes for the LED display
#define RED          0xff0000 
#define GREEN        0x00ff00 
#define BLUE         0x0000ff 

void setup() {
  // Initialize M5Stack Atom hardware and set up the LED display
  M5.begin(true, false, true);
  M5.dis.drawpix(0, GREEN); // Indicate initialization with green color

  // Initialize PS4 controller with the specified MAC address
  PS4.begin("78:25:db:55:48:a8");

  // Attach servo and motor to specific pins
  myServo.attach(21);
  myMotor.attach(22);

  // Indicate setup completion with red color
  M5.dis.drawpix(0, RED);
}

void loop() {
  // Check if the PS4 controller is connected
  if(PS4.isConnected()) {
    M5.dis.drawpix(0, 0x000000); // Turn off the LED display

    // Read the state of L1 and R1 buttons to determine gear
    int8_t gear1 = PS4.L1();
    int8_t gear2 = PS4.R1();

    // Calculate speed based on gear state
    int8_t speed = gear1 ? gear2 ? 6 : 8 : 10;

    // Calculate motor and servo positions based on joystick input
    int8_t ly =  97 + ((PS4.LStickY() / speed) * -1);
    int8_t rx =  90 + ((PS4.RStickX() / 5) * -1);

    // Write calculated positions to motor and servo
    myMotor.write(ly);
    myServo.write(rx);
  }

  // Add a delay to avoid rapid updates
  delay(50);
}