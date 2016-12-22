#ifndef DEF_ROTOR
#define DEF_ROTOR

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <boost/bimap.hpp>



class Rotor
{
public:
    // Constructeur
    Rotor();
    Rotor(const char listPermutation[2][26]);

    // Methodes
    void get_permutationTab();
    char activate(char charToPermute,int decalage=1,int sens=1);

private :
    // Attriubuts
    std::map<char,char> m_permutationRotor;
    boost::bimap<char,char> m_permutationRotor2;

};

#endif
