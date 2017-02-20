#ifndef DEF_PlugBoard
#define DEF_PlugBoard

#include <string>
#include <iostream>
#include <map>


class PlugBoard
{

public:

//constructeur
PlugBoard();
PlugBoard(char list[2][6]);

//methode
void get_PermutationTab();
char activate(char charToPermute);


private:

std::map<char,char> m_permutation;


};

#endif
