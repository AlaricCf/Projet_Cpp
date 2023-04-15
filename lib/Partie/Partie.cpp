#include <Partie.hpp>

Partie::Partie(){
    Serial.println("Nouvelle partie");
    uint8_t digit[] = {D3, D4, D5, D6, D7, D8};
    for(int i=0; i<6; i++){pinMode(digit[i],OUTPUT);digitalWrite(digit[i], LOW);}

    delay(3000); //Temps de préparation de la matrice
    M.displayMatrice();

    /*cout << "Nouvelle partie" << endl;
    cout << "Il faut donc choisir une combinaison secrete" << endl;*/
}

void Partie::set_code(vector<uint8_t> v){
    code = v;
}

void Partie::displayMatrice(){
    M.displayMatrice();
}

void Partie::setMatrice(int index, uint8_t valeur){
    M.setMatrice(index, valeur);
}

bool Partie::comparaison(vector<uint8_t> aComparer, int ligne){
  Serial.println("Debut comparaison -  TEST");
  Serial.print("Ligne n ");
  Serial.println(ligne);
  int x = 0; //compteur de coups gagnants

  for(int n = 0; n < 4; n++){
    for(int i = 0; i < 4; i++){
      if((code[n] == aComparer[i]) && (n == i)){
        Serial.println("PARFAIT -  TEST");
        setMatrice(ligne*8+4+n,0);
        aComparer[i] = 0;
        x += 1;
        break;
      }
      else{
        if(code[n] == aComparer[i]){
          Serial.println("BIEN -  TEST");
          setMatrice(ligne*8+4+n,254);
          aComparer[i] = 0;
        }
        else{
          Serial.println("MAUVAIS -  TEST");
        }
      }
    }
  }
  if(x == 4){
    return true;
  }
  return false;
}