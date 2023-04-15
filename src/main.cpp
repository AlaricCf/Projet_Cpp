#include <Partie.hpp>
#include <BtnLED.hpp>
#include <BtnPouss.hpp>
#include <matrixDisplays.hpp>

//Lancement d'une partie, avec creation de matrice...
Partie P;

//Creation des boutons poussoirs
BtnPouss btnValidation(A0);
BtnLED btnRouge(D6, D5, 1);
BtnLED btnVert(D5, D3, 68);
BtnLED btnBleu(D7, D6, 170);
BtnLED btnJaune(D4, D8, 28);

//Fonction attente de reception de la combinaison secrete...
void receptionCode(){

  vector<uint8_t> combinaisonSecrete;
  bool codeValide = false;
  uint8_t c = 0;

  //Tant que le code ne fait pas 4 couleurs
  while(!codeValide){
    if(combinaisonSecrete.size() < 4){
      //"Ecoute" des boutons de couleur
      if((c = btnRouge.btnON()) || (c = btnVert.btnON()) || (c = btnBleu.btnON()) || (c = btnJaune.btnON())){
        Serial.println(c);
        combinaisonSecrete.push_back(c);
        P.setMatrice(23+combinaisonSecrete.size(),c);
        c = 0;
      }
    }

    //Ecoute du bouton poussoir
    if((c = btnValidation.btnON())){

      //Presse et relache = validation
      if(c == 1){
        if(combinaisonSecrete.size() == 4){
          codeValide = true;
          for(int i = 0; i < 4; i++){P.setMatrice(24 + i, 255);}
          Serial.println(combinaisonSecrete[0]);
          Serial.println(combinaisonSecrete[1]);
          Serial.println(combinaisonSecrete[2]);
          Serial.println(combinaisonSecrete[3]);
        }
      }
        //Presse et maintenu = annuler la couleur precedente
      if(c == 2 && combinaisonSecrete.size() > 0){
        c = 0;
        Serial.println("Suppression - TEST");
        Serial.println(combinaisonSecrete.size());
        P.setMatrice(23 + combinaisonSecrete.size(), 255);
        combinaisonSecrete.pop_back();
        Serial.println(combinaisonSecrete.size());
      }
    }
    P.displayMatrice();
  }
}

bool debut = true; //debut = choix de la combinaison secrete

void setup() {
  
  Wire.begin();
  Serial.begin(9600);
  delay(3000);

}

void loop() {
  Serial.println("Debut loop -  TEST");

  if(debut){
      Serial.println("Debut reception -  TEST");
      receptionCode();
      Serial.println("Fin reception -  TEST");
      debut = false;
  }
  else{
    delay(1000); //mettre code pour jeu
  }
  
  P.displayMatrice();
}