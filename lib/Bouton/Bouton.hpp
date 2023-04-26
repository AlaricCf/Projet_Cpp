#ifndef DEF_BOUTON
#define DEF_BOUTON

#include <iostream>

#include <Arduino.h>
#include <Wire.h>
#include "../../include/grove_two_rgb_led_matrix.h"

using namespace std;

class Bouton{
    public :

        Bouton();

    protected :
        uint8_t in;
};

#endif