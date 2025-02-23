#ifndef MY_ENCODER_H
#define MY_ENCODER_H

#include <Arduino.h>

class My_encoder {
  public:
    // Konstruktor třídy
    My_encoder(int pinA, int pinB);

    // Metody pro nastavení a získání hodnot
    void begin();
    int getPosition();
    void resetPosition();

  private:
    // Pin pro enkodér
    int _pinA;
    int _pinB;
    
    // Aktuální pozice enkodéru
    volatile int _position;
    
    // Poslední stav pinů
    volatile int _lastStateA;
    volatile int _lastStateB;
    
    // Metoda pro zpracování změny stavu enkodéru
    static void _isr();

    // Statická proměnná pro zajištění správné obsluhy přerušení
    static My_encoder* _instance;
};

#endif
