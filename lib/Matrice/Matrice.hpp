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

        /*class Indexation : std::exception{
            public :
                char * erreur() throw(){
                    return "Probleme d'indexation";
                }
        };*/

        Matrice();

        ~Matrice();

        GroveTwoRGBLedMatrixClass matrix;

        bool estVide();

        void avancer();

        //void afficher();

        Led * operator[](int index);
        
        void afficherMatrice();

    private :
        void inserer();
        void supprimer();

        Led * first;
        Led * last;
        Led * courant;
};

#endif