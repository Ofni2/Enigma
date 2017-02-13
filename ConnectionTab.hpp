#ifndef DEF_CONNECTIONTAB
#define DEF_CONNECTIONTAB

#include <string>
#include <iostream>
#include <map>


class ConnectionTab
{

public:

//constructeur
ConnectionTab();
ConnectionTab(char liste[2][6]);

//methode
void get_PermutationTab();
char activate(char charToPermute);


private:

std::map<char,char> m_permutation;


};

#endif
