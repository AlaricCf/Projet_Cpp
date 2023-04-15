#include <BtnPouss.hpp>

BtnPouss::BtnPouss(uint8_t i){
    in = i;
    pinMode(in,INPUT);
}

int BtnPouss::btnON(){
    if(analogRead(in) > 700){
        Serial.println("Btn Pouss -  TEST");
        delay(1000);
        if(analogRead(in) > 700){
            Serial.println("Btn Pouss Suppr -  TEST");
            return 2;
        }
        return 1;
    }
    return 0;
}