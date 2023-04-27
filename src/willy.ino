#include <M5Atom.h>
#include "atom_willy.h"
#include <PS4Controller.h>

AtomWilly myServo(1, 400, 2500);
AtomWilly myMotor(3, 400, 2500);

#define RED          0xff0000 
#define GREEN          0x00ff00 
#define BLUE          0x0000ff 

void setup() {
  // hardware initialization
  M5.begin(true, false, true);
  M5.dis.drawpix(0, GREEN);
  PS4.begin("78:25:db:55:48:a8");  // "78:21:84:93:d8:48"
  myServo.attach(21);
  myMotor.attach(22);

  M5.dis.drawpix(0, RED);
}

void loop() {
  if(PS4.isConnected()) {
    M5.dis.drawpix(0, 0x000000);

    int8_t ly =  100 + ((PS4.LStickY() / 10) * -1);
    int8_t rx =  90 + ((PS4.RStickX() / 5) * -1);
    Serial.println(ly);
    Serial.println(rx);
    Serial.println();

    if (ly > 100) {
      myMotor.write(ly);
      M5.dis.drawpix(0, BLUE);
    } 
    if (ly < 100) {
      myMotor.write(ly);
      M5.dis.drawpix(0, RED);
    }
    if (PS4.Down()) {
      myMotor.write(97);
    }

    if (rx < 90) {
      myServo.write(rx);
      M5.dis.drawpix(0, RED);
    } else if (rx > 90) {
      myServo.write(rx);
      M5.dis.drawpix(0, BLUE);
    } else {
      myServo.write(90);
    }
  }

  delay(100);
}