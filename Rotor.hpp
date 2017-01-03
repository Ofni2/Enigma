#ifndef DEF_ROTOR
#define DEF_ROTOR

#include <vector>
#include <string>
#include <iostream>


class Rotor
{
public:
    // Constructeur
    Rotor();
    Rotor(const char listPermutation[2][26]);

    // Methodes
    void get_permutationTab();
    char activate(char charToPermute,int sens=1);
    void rotate(int decalage=0);


private :
    // Attributs
    char rotor_tab[26][2];

    //Methodes
    int seek(char x, char S);

};

#endif
