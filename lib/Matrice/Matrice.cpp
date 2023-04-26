#include <Matrice.hpp>

Matrice::Matrice(){
    first = nullptr;
    last = nullptr;

    std::cout<<"creation matrice"<<std::endl;
    
    for(int i = 0; i < 64; i++){
        inserer();
    }
    
    std::cout<<"matrice créée"<<std::endl;
    courant = first;
}
        
Matrice::~Matrice(){
    while (first != nullptr){
        supprimer();
    }
}

bool Matrice::estVide(){
    return first == nullptr;
}

void Matrice::avancer(){
    if(courant->nextLed != nullptr){
        courant = courant->nextLed;
    }
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
    } //exception ???
}

/*void Matrice::afficher(){
    courant = first;
    for(int i = 0; i < 64; i++){
        std::cout << "Couleur " << i << " : " << (int)courant->getColor() << std::endl;
        avancer();
    }
}*/

void Matrice::inserer(){

    Led * l = new Led();

    if(estVide()){
        first = l;
        last = l;
    }
    else{
        last->nextLed = l;
        last = l;
    }
}

void Matrice::supprimer(){
    if(!estVide()){
        
        Led * copie = first->nextLed;
        delete first;
        first = copie;
    }
}

void Matrice::afficherMatrice(){

    uint8_t matriceAux[64];

    for(int i = 0; i < 64; i++){
        matriceAux[i] = this->operator[](i)->getColor();
    }

    matrix.displayFrames(matriceAux, 5000, true, 1);
    
}

/*
int main(){
    Matrice M;
    M.afficher();
    
    std::cout << (int)M[3]->getColor() << std::endl;

    return 0;
}*/