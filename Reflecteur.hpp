#ifndef DEF_REFELCTEUR
#define DEF_REFLECTUER

#include <vector>
#include <string>
#include <iostream>
#include <map>


class Reflecteur
{
public:
    // Constructeur
    Reflecteur();
    Reflecteur(char listPermutation[2][26]);

    // Methodes
    void get_permutationTab();
    char activate(char charToPermute);

private :
    // Attriubuts
    std::map<char,char> m_permutationReflecteur;

};


#endif
