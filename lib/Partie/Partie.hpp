#ifndef DEF_PARTIE
#define DEF_PARTIE

#include <Matrice.hpp>

using namespace std;

class Partie{
    public :

        Partie();

        void set_code(vector<uint8_t> v);

        void displayMatrice();

        void setMatrice(int index, uint8_t valeur);

        vector<uint8_t> get_code();

    private :

        vector<uint8_t> code;
        Matrice M;
};

#endif