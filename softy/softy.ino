#include <SoftwareSerial.h>

/*
 * Use two arduinos.  Connect as follows:
 * Arduino #1 pin 10 to Arduino #2 pin 11
 * Arduino #1 pin 11 to Arudino #2 pin 10
 */

SoftwareSerial mySerial(10, 11); // RX, TX

int i = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  
  // set the data rate for the SoftwareSerial portloop
  mySerial.begin(9600);
  Serial.println("Hello");
}

void loop() { // run over and over
  delay(500);
  mySerial.print("Report ");
  mySerial.println(i++);
  
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
