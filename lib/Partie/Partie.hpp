#ifndef DEF_PARTIE
#define DEF_PARTIE

#include <Matrice.hpp>

using namespace std;

class Partie{
    public :

        Partie();

        vector<uint8_t> get_code();

        void addValueCode(uint8_t x);

        void delValueCode();

        void displayMatrice();

        void setMatrice(int index, uint8_t valeur);

    private :
        vector<uint8_t> code;
        Matrice M;
};

#endif