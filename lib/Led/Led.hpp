#ifndef DEF_LED
#define DEF_LED

#include <iostream>

class Led{
    friend class Matrice;

    public :

        Led();

        ~Led();

        uint8_t getColor();

        void setColor(uint8_t c);

    private :
        Led * nextLed;
        uint8_t color;
};

#endif