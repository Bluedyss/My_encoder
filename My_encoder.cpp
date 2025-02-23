#include "My_encoder.h"

My_encoder* My_encoder::_instance = nullptr;

// Constructor
My_encoder::My_encoder(int pinA, int pinB, int pinButton) {
  _pinA = pinA;
  _pinB = pinB;
  _pinButton = pinButton;
  _position = 0;
  _lastStateA = 0;
  _lastStateB = 0;
  _lastButtonState = HIGH; // Assuming the button is normally open
  _buttonPressed = false;

  _instance = this;
}

// Initialization of pins and interrupts
void My_encoder::begin() {
  pinMode(_pinA, INPUT);
  pinMode(_pinB, INPUT);
  pinMode(_pinButton, INPUT_PULLUP); // The button uses the internal pull-up resistor
  
  // Attach interrupt to pinA for state change monitoring
  attachInterrupt(digitalPinToInterrupt(_pinA), _isr, CHANGE);
}

// Function to get the current position of the encoder
int My_encoder::getPosition() {
  return _position;
}

// Function to reset the encoder's position to zero
void My_encoder::resetPosition() {
  _position = 0;
}

// Function to check if the button was pressed
bool My_encoder::isButtonPressed() {
  bool currentButtonState = digitalRead(_pinButton);
  
  // Check for button press (transition)
  if (_lastButtonState == HIGH && currentButtonState == LOW) {
    _buttonPressed = true;
  } else {
    _buttonPressed = false;
  }

  _lastButtonState = currentButtonState;
  return _buttonPressed;
}

// ISR to handle encoder state change
void My_encoder::_isr() {
  int stateA = digitalRead(_instance->_pinA);
  int stateB = digitalRead(_instance->_pinB);

  // Determine the direction of rotation
  if (stateA != _instance->_lastStateA) {
    if (stateB != stateA) {
      _instance->_position++;
    } else {
      _instance->_position--;
    }
  }

  _instance->_lastStateA = stateA;
  _instance->_lastStateB = stateB;
}
