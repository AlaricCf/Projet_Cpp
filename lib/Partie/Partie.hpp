#ifndef DEF_PARTIE
#define DEF_PARTIE

#include "../Matrice/Matrice.hpp"

using namespace std;

class Partie{
    public :

        Partie();

        void set_code(vector<uint8_t> v);

        void displayMatrice();

        void setMatrice(int index, uint8_t valeur);

        void displayCoeur();

        void displayOFF();

        void displayFail();

        bool comparaison(vector<uint8_t> aComparer, int ligne);

    private :

        vector<uint8_t> code;
        Matrice M;
};

#endif