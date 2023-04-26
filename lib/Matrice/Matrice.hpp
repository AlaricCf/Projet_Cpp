#ifndef DEF_MATRICE
#define DEF_MATRICE

#include <iostream>
#include <cstdint>
#include <vector>

#include <Arduino.h>
#include <Wire.h>
#include "../../include/grove_two_rgb_led_matrix.h"
#include "../Led/Led.hpp"

using namespace std;

class Matrice{

    public :

        Matrice();
        ~Matrice();

        GroveTwoRGBLedMatrixClass matrix;

        void avancer();
        void afficherMatrice();

        Led * operator[](int index);

    private :
        void inserer();
        void supprimer();

        Led * first;
        Led * last;
        Led * courant;
};

#endif