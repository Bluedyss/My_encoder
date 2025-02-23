# My_encoder Library

This is a simple Arduino library for interfacing with a rotary encoder and a button. It allows you to track the position of the rotary encoder and detect button presses.

## Features
- Tracks the position of a rotary encoder.
- Detects button presses (with an internal pull-up resistor).
- Provides methods to:
  - Get the current position of the encoder.
  - Reset the position to zero.
  - Check if the button has been pressed.

## Installation

1. Download the library files (`My_encoder.h` and `My_encoder.cpp`).
2. Place the files in a folder called `My_encoder` inside your Arduino `libraries` directory.
   - For example: `Arduino/libraries/My_encoder/`.
3. Restart the Arduino IDE to see the library available for use.

## Example Usage

### Hardware Setup

- **Rotary Encoder:**
  - Connect pin A to any digital pin (e.g., pin 2).
  - Connect pin B to any digital pin (e.g., pin 3).
  
- **Button:**
  - Connect the button to a digital pin (e.g., pin 4). The button uses the internal pull-up resistor.

### Code Example

```cpp
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
