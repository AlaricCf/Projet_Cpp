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

void affcihervect(vector<uint8_t> v){
  for(int i = 0; i<4;i++){
    Serial.print(v[i]);
    Serial.print(' ');
  }
  Serial.println(' ');
}

//Fonction attente de reception de la combinaison secrete...
vector<uint8_t> receptionCode(int ligne, bool codeSecret){

  vector<uint8_t> code;
  bool codeValide = false;
  uint8_t c = 0;

  //Tant que le code ne fait pas 4 couleurs
  while(!codeValide){
    if(code.size() < 4){
      //"Ecoute" des boutons de couleur
      if((c = btnRouge.btnON()) || (c = btnVert.btnON()) || (c = btnBleu.btnON()) || (c = btnJaune.btnON())){
        Serial.println(c);
        code.push_back(c);
        P.setMatrice(ligne*8-1+code.size(),c);
        c = 0;
      }
    }

    //Ecoute du bouton poussoir
    if((c = btnValidation.btnON())){

      //Presse et relache = validation
      if((c == 1)){
        if(code.size() == 4){
          codeValide = true;
          
          if(codeSecret){
            P.set_code(code);
            for(int i = 0; i < 4; i++){
              P.setMatrice(ligne*8 + i, 255);
              code[i] = 0;
            }
          }
          Serial.println(code[0]);
          Serial.println(code[1]);
          Serial.println(code[2]);
          Serial.println(code[3]);
        }
      }
        //Presse et maintenu = annuler la couleur precedente
      if(c == 2 && code.size() > 0){
        c = 0;
        Serial.println("Suppression - TEST");
        Serial.println(code.size());
        P.setMatrice(ligne*8 -1 + code.size(), 255);
        code.pop_back();
        Serial.println(code.size());
      }
    }
    P.displayMatrice();
  }
  return code;
}

bool debut = true; //debut = choix de la combinaison secrete
vector<uint8_t> tentative;
int n = 8; //nombre de tentatives
bool victoire = false;

void setup() {
  
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  Serial.println("Debut loop -  TEST");

  if(debut){
    Serial.println("Debut reception -  TEST");
    tentative = receptionCode(3,true); //non utilisation car code secret donc pas utile
    Serial.println("Fin reception -  TEST");
    debut = false;
  }
  else{
    Serial.println("Debut jeu -  TEST");
    while(n > 0 && !victoire){
      tentative = receptionCode(8-n,false);
      victoire = P.comparaison(tentative, 8-n);
      n -= 1;
    }
    if(victoire){
      Serial.println("BRAVO VOUS AVEZ GAGNE");
    }
    else{
      Serial.println("VOUS AVEZ PERDU :O");
    }
  }
  P.displayMatrice();
}