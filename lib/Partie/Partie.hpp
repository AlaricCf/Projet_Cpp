#ifndef DEF_PARTIE
#define DEF_PARTIE

#include "../Matrice/Matrice.hpp"
#include "../MatriceDisplays/MatriceDisplays.hpp"

using namespace std;

class Partie{
    public :

        Partie();

        void set_code(vector<uint8_t> c);

        void displayMatrice();

        void setMatrice(int index, uint8_t valeur);

        void displayShape(const uint8_t mat[64], unsigned long time = 0);

        void displayOFF();

        void afficherReponse();

        int comparaison(vector<uint8_t> aComparer, int ligne);

    private :

        vector<uint8_t> code;
        Matrice M;
};

#endif