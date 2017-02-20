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
    Reflector(std::string name,char listPermutation[2][13]);

    // Methodes
    void get_permutationTab();
    char activate(char charToPermute);

private :
    // Attriubuts
	std::string m_name;
    std::map<char,char> m_permutationReflector;

};


#endif
