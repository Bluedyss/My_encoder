#include "My_encoder.h"

// Declare the encoder, connecting it to pins 2 and 3 for the encoder, and pin 4 for the button
My_encoder encoder(2, 3, 4);

void setup() {
  Serial.begin(9600);
  encoder.begin();
}

void loop() {
  // Get the encoder position and print it to the serial monitor
  Serial.print("Position: ");
  Serial.println(encoder.getPosition());
  
  // Check if the button was pressed
  if (encoder.isButtonPressed()) {
    Serial.println("Button pressed!");
  }
  
  delay(100);
}
