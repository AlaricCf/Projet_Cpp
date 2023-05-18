#include "../lib/Partie/Partie.hpp"
#include "../lib/Bouton/BtnLED.hpp"
#include "../lib/Bouton/BtnPouss.hpp"

///////////////////////////////////////////////
//                     MAIN                 //
/////////////////////////////////////////////

//Lancement d'une partie, avec creation de matrice...
Partie P;

//Creation des boutons poussoirs
BtnPouss btnValidation(A0);
BtnLED btnRouge(D6, D5, 1);
BtnLED btnVert(D5, D3, 68);
BtnLED btnBleu(D7, D6, 170);
BtnLED btnJaune(D4, D8, 28);

bool debut = true; //debut = choix de la combinaison secrete
vector<uint8_t> tentative;
int nombreTentatives = 8; //nombre de tentatives restantes
int couleurTrouvee = 0;
bool victoire = false;



//Fonction attente de reception d'une combinaison...
vector<uint8_t> receptionCode(int ligne, bool codeSecret){

  vector<uint8_t> combinaison;
  bool codeValide = false;
  uint8_t c = 0;

  //Tant que le code ne fait pas 4 couleurs
  while(!codeValide){
    if(combinaison.size() < 4){
      //Ecoute des boutons de couleur
      if((c = btnRouge.btnON()) || (c = btnVert.btnON()) || (c = btnBleu.btnON()) || (c = btnJaune.btnON())){
        combinaison.push_back(c);
        if(codeSecret){
          P.setMatrice(ligne*8+1+combinaison.size(),c);
          P.setMatrice(ligne*8+9+combinaison.size(),c);
        }
        else{
          P.setMatrice(ligne*8-1+combinaison.size(),c);
        }
        c = 0;
      }
    }

    //Ecoute du bouton poussoir
    if((c = btnValidation.btnON())){

      //Presse et relache = validation
      if((c == 1)){
        if(combinaison.size() == 4){
          codeValide = true;
          
          if(codeSecret){
            P.setCode(combinaison);
            for(int i = 0; i < 4; i++){
              P.setMatrice(ligne*8 + 2 + i, 255);
              P.setMatrice(ligne*8 + 10 + i, 255);
              combinaison[i] = 0;
            }
          }
        }
      }
      
      //Presse et maintenu = annuler la couleur precedente
      if(c == 2 && combinaison.size() > 0){
        c = 0;
        if(codeSecret){
          P.setMatrice(ligne*8+1+combinaison.size(), 255);
          P.setMatrice(ligne*8+9+combinaison.size(), 255);
        }
        else{
          P.setMatrice(ligne*8-1+combinaison.size(), 255);
        }
        combinaison.pop_back();
      }
    }
    P.afficherMatrice();
  }
  return combinaison;
}

void restart(){
  delay(3000);
  P.matriceOFF();
  debut = true;
  victoire = false;
  nombreTentatives = 8;
}

//SETUP de l'Arduino suivi de la boucle LOOP qui exécute le programme
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
    //boucle tant que le joueur n'a pas gagne ou perdu
    while(nombreTentatives > 0 && !victoire){

      tentative = receptionCode(8-nombreTentatives,false);
      couleurTrouvee = P.comparaison(tentative, 8-nombreTentatives);

      if(couleurTrouvee == 0){
        P.afficherForme(MatriceDisplays::matriceCroix, 1000);
      }

      victoire = (couleurTrouvee == 8);
      nombreTentatives -= 1;
    }

    //gagne?
    if(victoire){
      delay(500);
      P.afficherForme(MatriceDisplays::matriceCoeur);
      restart();
    }

    //perdu?
    if((nombreTentatives == 0) && !victoire){
      P.afficherForme(MatriceDisplays::matriceEchec);
      delay(2000);
      P.afficherReponse();
      restart();
    }
  }
}
