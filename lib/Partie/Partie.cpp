#include <Partie.hpp>

Partie::Partie(){
    Serial.println("Nouvelle partie");
    uint8_t digit[] = {D3, D4, D5, D6, D7, D8};
    for(int i=0; i<6; i++){pinMode(digit[i],OUTPUT);digitalWrite(digit[i], LOW);}

    delay(1000); //Temps de préparation de la matrice
    M.displayMatrice();

    /*cout << "Nouvelle partie" << endl;
    cout << "Il faut donc choisir une combinaison secrete" << endl;*/
}

vector<uint8_t> Partie::get_code(){
    return code;
}

void Partie::addValueCode(uint8_t x){
    code.push_back(x);
}

void Partie::delValueCode(){
    code.pop_back();
}

void Partie::displayMatrice(){
    M.displayMatrice();
}

void Partie::setMatrice(int index, uint8_t valeur){
    M.setMatrice(index, valeur);
}

//int main(){cout<<"Partie.cpp"<<endl; return 0;}