#include "Led.hpp"

Led::Led(){
    std::cout << "creation Led" << std::endl;
    color = 255;
    nextLed = nullptr;
}

Led::~Led(){}

uint8_t Led::getColor(){
    return color;
}

void Led::setColor(uint8_t c){
    color = c;
}