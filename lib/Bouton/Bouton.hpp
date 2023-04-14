#ifndef DEF_BOUTON
#define DEF_BOUTON

#include <iostream>
#include <cstdint>
#include <vector>

#include <Arduino.h>
#include <Wire.h>
#include "../../include/grove_two_rgb_led_matrix.h"

using namespace std;

class Bouton{
    public :

        Bouton();

        //Bouton(uint8_t o);

    protected :
        uint8_t in;
};

#endif