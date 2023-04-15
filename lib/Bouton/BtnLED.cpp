#include <BtnLED.hpp>

BtnLED::BtnLED(uint8_t i, uint8_t o, uint8_t c){
    in = i;
    out = o;
    couleur = c;
}

uint8_t BtnLED::btnON(){
    pinMode(in,INPUT);
    pinMode(out,OUTPUT);
    digitalWrite(out,HIGH);
    Serial.print("Btn LED ");
    Serial.print(couleur);
    Serial.println("-  TEST");
    if(!digitalRead(in)){
        delay(300);
        return couleur;
    }
    return 0;
}