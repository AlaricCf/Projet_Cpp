#ifndef DEF_BTNLED
#define DEF_BTNLED

#include <Bouton.hpp>

class BtnLED: public Bouton {
  public: 
    
    BtnLED(uint8_t i, uint8_t o, uint8_t c);

    uint8_t btnON();

    private:
        uint8_t out;
        uint8_t couleur;

};

#endif