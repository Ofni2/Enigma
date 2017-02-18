#include "PlugBoard.hpp"
#include <map>

using namespace std;

// Constructeur

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation par defaut
* (la table de connection est nulle par defaut)
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
PlugBoard::PlugBoard()
{
    m_permutation['a']='a';
    m_permutation['b']='b';
    m_permutation['c']='c';
    m_permutation['d']='d';
    m_permutation['e']='e';
    m_permutation['f']='f';
    m_permutation['g']='g';
    m_permutation['h']='h';
    m_permutation['i']='i';
    m_permutation['j']='j';
    m_permutation['k']='k';
    m_permutation['l']='l';
    m_permutation['m']='m';
    m_permutation['n']='n';
    m_permutation['o']='o';
    m_permutation['p']='p';
    m_permutation['q']='q';
    m_permutation['r']='r';
    m_permutation['s']='s';
    m_permutation['t']='t';
    m_permutation['u']='u';
    m_permutation['v']='v';
    m_permutation['w']='w';
    m_permutation['x']='x';
    m_permutation['y']='y';
    m_permutation['z']='z';
}

//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* initialisation la table de connection en fonction du tableau listeInut
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
PlugBoard::PlugBoard(char listeInput[2][6])
{
    m_permutation['a']='a';
    m_permutation['b']='b';
    m_permutation['c']='c';
    m_permutation['d']='d';
    m_permutation['e']='e';
    m_permutation['f']='f';
    m_permutation['g']='g';
    m_permutation['h']='h';
    m_permutation['i']='i';
    m_permutation['j']='j';
    m_permutation['k']='k';
    m_permutation['l']='l';
    m_permutation['m']='m';
    m_permutation['n']='n';
    m_permutation['o']='o';
    m_permutation['p']='p';
    m_permutation['q']='q';
    m_permutation['r']='r';
    m_permutation['s']='s';
    m_permutation['t']='t';
    m_permutation['u']='u';
    m_permutation['v']='v';
    m_permutation['w']='w';
    m_permutation['x']='x';
    m_permutation['y']='y';
    m_permutation['z']='z';

    for (int i(0); i<6; ++i)
    {
        m_permutation[listeInput[0][i]]=listeInput[1][i];
        m_permutation[listeInput[1][i]]=listeInput[0][i];
    }
}




// Methode


//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode qui transforme un caracter en focntion d'une table de connection
*
* @param[in]    charactere à permuter
* @param[out]   charater permuté à partir de la table
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
char PlugBoard::activate(char charToPermute)
{
    return m_permutation[charToPermute];
}






//--------------------------------------------------------------
//--------------------------------------------------------------
/**
*
* Methode qui affiche permet d'afficher la table de connection
*
**/
//--------------------------------------------------------------
//--------------------------------------------------------------
void PlugBoard::get_PermutationTab()
{
    map<char,char>::iterator p;

    cout<<"voici la table de connection"<<endl;

    for(p=m_permutation.begin(); p!=m_permutation.end(); p++)
    {
        cout<<p->first<<"  devient :   "<<p->second<<endl;
    }
    cout<<endl;
}
