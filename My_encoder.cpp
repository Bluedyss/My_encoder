#include "My_encoder.h"

My_encoder* My_encoder::_instance = nullptr;

// Konstruktor
My_encoder::My_encoder(int pinA, int pinB) {
  _pinA = pinA;
  _pinB = pinB;
  _position = 0;
  _lastStateA = 0;
  _lastStateB = 0;
  
  _instance = this;
}

// Inicializace pinů a přerušení
void My_encoder::begin() {
  pinMode(_pinA, INPUT);
  pinMode(_pinB, INPUT);
  
  // Připojení přerušení na pinA pro sledování změn
  attachInterrupt(digitalPinToInterrupt(_pinA), _isr, CHANGE);
}

// Funkce pro získání aktuální pozice enkodéru
int My_encoder::getPosition() {
  return _position;
}

// Funkce pro resetování pozice enkodéru na nulu
void My_encoder::resetPosition() {
  _position = 0;
}

// ISR pro zpracování změny stavu enkodéru
void My_encoder::_isr() {
  int stateA = digitalRead(_instance->_pinA);
  int stateB = digitalRead(_instance->_pinB);

  // Zjištění směru otáčení
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

