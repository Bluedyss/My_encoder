#ifndef MY_ENCODER_H
#define MY_ENCODER_H

#include <Arduino.h>

class My_encoder {
  public:
    // Konstruktor třídy
    My_encoder(int pinA, int pinB, int pinButton);

    // Metody pro nastavení a získání hodnot
    void begin();
    int getPosition();
    void resetPosition();
    bool isButtonPressed();

  private:
    // Pin pro enkodér a tlačítko
    int _pinA;
    int _pinB;
    int _pinButton;
    
    // Aktuální pozice enkodéru
    volatile int _position;
    
    // Poslední stav pinů
    volatile int _lastStateA;
    volatile int _lastStateB;
    
    // Stav tlačítka
    bool _lastButtonState;
    bool _buttonPressed;
    
    // Metoda pro zpracování změny stavu enkodéru
    static void _isr();

    // Statická proměnná pro zajištění správné obsluhy přerušení
    static My_encoder* _instance;
};

#endif
