#include <Matrice.hpp>

Matrice::Matrice(){
    /*creer feux d'artifice
    .... 
    displayMatrice()
    ....
    displayMatrices()*/

    for(int i = 0; i < 64; i++){
        M.push_back(255);
    }
    Serial.println("Dans l'attente d'une combinaison secrete...");
}
        
void Matrice::setMatrice(int index, uint8_t valeur){
    M[index] = valeur;
}

void Matrice::displayMatrice(){

    uint8_t matriceAux[64];

    for(int i = 0; i < 64; i++){
        matriceAux[i] = M[i];
    }

    matrix.displayFrames(matriceAux, 5000, true, 1);
    
}