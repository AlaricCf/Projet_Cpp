#include <Partie.hpp>

Partie::Partie(){
    Serial.println("Nouvelle partie");
    uint8_t digit[] = {D3, D4, D5, D6, D7, D8};
    for(int i=0; i<6; i++){pinMode(digit[i],OUTPUT);digitalWrite(digit[i], LOW);}

    delay(3000); //Temps de préparation de la matrice
    M.afficherMatrice();

    /*cout << "Nouvelle partie" << endl;
    cout << "Il faut donc choisir une combinaison secrete" << endl;*/
}

void Partie::set_code(vector<uint8_t> c){
    code = c;
}

void Partie::displayMatrice(){
    M.afficherMatrice();
}

void Partie::displayShape(const uint8_t mat[64],  unsigned long time){
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

void Partie::displayOFF(){
  for(int i = 0; i < 64; i++){
    M[i]->setColor(255);
  }
  M.afficherMatrice();
}

void Partie::afficherReponse(){
  for(int i = 15; i < 47; i++){
    M[i]->setColor(255);
  }
  for(int i = 26; i < 30; i++){
    M[i]->setColor(code[i-26]);
    M[i+8]->setColor(code[i-26]);
  }
  M.afficherMatrice();
}

void Partie::setMatrice(int index, uint8_t valeur){
    M[index]->setColor(valeur);
}

vector<uint8_t> tri(vector<uint8_t> v){
  uint8_t x;
  if(v.size() == 0){return v;}
  for(unsigned int i = 0; i < v.size()-1; i++){
    for(unsigned int j = 0; j < v.size()-i-1; j++){
      if(v[j] > v[j+1]){
        x = v[j+1];
        v[j+1] = v[j];
        v[j] = x;
      }
    }  
  }
  return v;
}

int Partie::comparaison(vector<uint8_t> aComparer, int ligne){
  Serial.println("Debut comparaison -  TEST");
  Serial.print("Ligne n ");
  Serial.println(ligne);

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

  Serial.println("DEBUT TRI -  TEST");
  correction = tri(correction);
  Serial.println("FIN TRI -  TEST");
  for(unsigned int i = 0; i < correction.size(); i++){
    setMatrice(ligne*8+7-i, correction[i]);
  }

  return x;
}
