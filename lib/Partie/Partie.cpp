#include <Partie.hpp>

Partie::Partie(){

    //extinction des boutons Led
    uint8_t digit[] = {D3, D4, D5, D6, D7, D8};
    for(int i = 0; i < 6; i++){
      pinMode(digit[i],OUTPUT);
      digitalWrite(digit[i], LOW);
    }

    delay(2000); //Temps de préparation de la matrice
    M.afficherMatrice();

}

void Partie::setCode(vector<uint8_t> c){
    code = c;
}

void Partie::afficherMatrice(){
    M.afficherMatrice();
}

void Partie::afficherForme(const uint8_t mat[64],  unsigned long time){ //time = 0 par defaut
  if(!time){
    for(int i = 0; i < 64; i++){
      M[i]->setColor(mat[i]);
    }
  }
  else{
    Matrice matriceAux;
    for(int i = 0; i < 64; i++){
      matriceAux[i]->setColor(mat[i]);
    }
    matriceAux.afficherMatrice();
    delay(time);
    matriceAux.~Matrice();
  }
  M.afficherMatrice();
}

void Partie::matriceOFF(){
  for(int i = 0; i < 64; i++){
    M[i]->setColor(255);
  }
  M.afficherMatrice();
}

void Partie::afficherReponse(){

  this->matriceOFF();

  for(int i = 26; i < 30; i++){
    M[i]->setColor(code[i-26]);
    M[i+8]->setColor(code[i-26]);
  }
  M.afficherMatrice();
}

void Partie::setMatrice(int index, uint8_t valeur){
    M[index]->setColor(valeur);
}

vector<uint8_t> tri(vector<uint8_t> vect){
  
  uint8_t aux;

  if(vect.size() == 0){
    return vect;
  }

  for(unsigned int i = 0; i < vect.size()-1; i++){
    for(unsigned int j = 0; j < vect.size()-i-1; j++){
      if(vect[j] > vect[j+1]){
        aux = vect[j+1];
        vect[j+1] = vect[j];
        vect[j] = aux;
      }
    }  
  }
  return vect;
}

int Partie::comparaison(vector<uint8_t> aComparer, int ligne){
  
  vector<uint8_t> correction;
  vector<uint8_t> codeSecret = code;
  
  int x = 0; //compteur de coups gagnants

  for(int n = 0; n < 4; n++){
    if(codeSecret[n] == aComparer[n]){
      Serial.println("PARFAIT -  TEST");
      correction.push_back(0);
      aComparer[n] = 0;
      codeSecret[n] = 0;
      x += 2;
    }
  }

  for(int n = 0; n < 4; n++){
    for(int i = 0; i < 4; i++){
      if((codeSecret[n] == aComparer[i]) && codeSecret[n]){
        Serial.println("BIEN -  TEST");
        correction.push_back(254);
        aComparer[i] = 0;
        codeSecret[n] = 0;
        x += 1;
      }
      else{
        Serial.println("MAUVAIS -  TEST");
      }
    }
  }

  correction = tri(correction);

  for(unsigned int i = 0; i < correction.size(); i++){
    setMatrice(ligne*8+7-i, correction[i]);
  }
  this->afficherMatrice();
  return x;
}
