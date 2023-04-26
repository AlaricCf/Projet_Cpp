#include <Matrice.hpp>

Matrice::Matrice(){
    first = nullptr;
    last = nullptr;
    
    for(int i = 0; i < 64; i++){
        inserer();
    }
    
    courant = first;
}
        
Matrice::~Matrice(){
    while (first != nullptr){
        supprimer();
    }
}

void Matrice::avancer(){
    if(courant->nextLed != nullptr){
        courant = courant->nextLed;
    }
}

void Matrice::afficherMatrice(){

    uint8_t matriceAux[64];

    for(int i = 0; i < 64; i++){
        matriceAux[i] = this->operator[](i)->getColor();
    }

    matrix.displayFrames(matriceAux, 5000, true, 1);
    
}

Led * Matrice::operator[](int index){
    if(index < 64){
        courant = first;

        for(int i = 0; i < index; i++){
            avancer();
        }

        return courant;
    }
    else{
        return nullptr;
    }
}

void Matrice::inserer(){

    Led * l = new Led();

    if(first == nullptr){
        first = l;
        last = l;
    }
    else{
        last->nextLed = l;
        last = l;
    }
}

void Matrice::supprimer(){

    if(first != nullptr){
        Led * copie = first->nextLed;
        delete first;
        first = copie;
    }
}