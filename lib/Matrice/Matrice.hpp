#ifndef DEF_MATRICE
#define DEF_MATRICE

#include <iostream>
#include <cstdint>
#include <vector>

#include <Arduino.h>
#include <Wire.h>
#include "../../include/grove_two_rgb_led_matrix.h"

using namespace std;

class Matrice{
    public :

        Matrice();

        GroveTwoRGBLedMatrixClass matrix;
        
        void setMatrice(int index, uint8_t valeur);
        
        void displayMatrice();

    private :
        vector <uint8_t> M;
};

#endif