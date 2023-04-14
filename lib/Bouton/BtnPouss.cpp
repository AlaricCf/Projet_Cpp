#include <BtnPouss.hpp>

BtnPouss::BtnPouss(uint8_t i){
    in = i;
    pinMode(in,INPUT);
}

int BtnPouss::btnON(){
    if(analogRead(in) > 500){
        delay(1000);
        if(analogRead(in) > 500){
            return 2;
        }
        return 1;
    }
    return 0;
}