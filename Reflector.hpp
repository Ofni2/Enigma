#ifndef DEF_REFLECTER
#define DEF_REFLECTER

#include <vector>
#include <string>
#include <iostream>
#include <map>


class Reflector
{
public:
    // Constructeur
    Reflector();
    Reflector(char listPermutation[2][26]);

    // Methodes
    void get_permutationTab();
    char activate(char charToPermute);

private :
    // Attriubuts
    std::map<char,char> m_permutationReflector;

};


#endif
