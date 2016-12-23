#ifndef DEF_ROTOR
#define DEF_ROTOR

#include <vector>
#include <string>
#include <iostream>

#include <boost/config.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/support/lambda.hpp>


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
    // Attriubuts
    typedef boost::bimap< char, char > bm_type;
    bm_type bm;

    boost::bimap<char,char> m_permutationRotor;





};

#endif
