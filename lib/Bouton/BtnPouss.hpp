#ifndef DEF_BTNPOUSS
#define DEF_BTNPOUSS

#include <Bouton.hpp>

class BtnPouss: public Bouton {
  public: 
    
    BtnPouss(uint8_t i);

    int btnON();

};

#endif