#ifndef MY_ENCODER_H
#define MY_ENCODER_H

#include <Arduino.h>

class My_encoder {
  public:
    // Constructor
    My_encoder(int pinA, int pinB, int pinButton);

    // Methods to initialize and get values
    void begin();
    int getPosition();
    void resetPosition();
    bool isButtonPressed();

  private:
    // Pins for the encoder and button
    int _pinA;
    int _pinB;
    int _pinButton;
    
    // Current position of the encoder
    volatile int _position;
    
    // Last state of the pins
    volatile int _lastStateA;
    volatile int _lastStateB;
    
    // Button state
    bool _lastButtonState;
    bool _buttonPressed;
    
    // Method to handle encoder state change
    static void _isr();

    // Static instance for proper interrupt handling
    static My_encoder* _instance;
};

#endif
