#include "Rotor.hpp"
#include <map>

using namespace std;

//Constructeur
Rotor::Rotor()
{
    m_permutationRotor['a']='a';
    m_permutationRotor['b']='b';
    m_permutationRotor['c']='c';
    m_permutationRotor['d']='d';
    m_permutationRotor['e']='e';
    m_permutationRotor['f']='f';
    m_permutationRotor['g']='g';
    m_permutationRotor['h']='h';
    m_permutationRotor['i']='i';
    m_permutationRotor['j']='j';
    m_permutationRotor['k']='k';
    m_permutationRotor['l']='l';
    m_permutationRotor['m']='m';
    m_permutationRotor['n']='n';
    m_permutationRotor['o']='o';
    m_permutationRotor['p']='p';
    m_permutationRotor['q']='q';
    m_permutationRotor['r']='r';
    m_permutationRotor['s']='s';
    m_permutationRotor['t']='t';
    m_permutationRotor['u']='u';
    m_permutationRotor['v']='v';
    m_permutationRotor['w']='w';
    m_permutationRotor['x']='x';
    m_permutationRotor['y']='y';
    m_permutationRotor['z']='z';
}

Rotor::Rotor(const char listPermutation[2][26])
{
    m_permutationRotor['a']='a';
    m_permutationRotor['b']='b';
    m_permutationRotor['c']='c';
    m_permutationRotor['d']='d';
    m_permutationRotor['e']='e';
    m_permutationRotor['f']='f';
    m_permutationRotor['g']='g';
    m_permutationRotor['h']='h';
    m_permutationRotor['i']='i';
    m_permutationRotor['j']='j';
    m_permutationRotor['k']='k';
    m_permutationRotor['l']='l';
    m_permutationRotor['m']='m';
    m_permutationRotor['n']='n';
    m_permutationRotor['o']='o';
    m_permutationRotor['p']='p';
    m_permutationRotor['q']='q';
    m_permutationRotor['r']='r';
    m_permutationRotor['s']='s';
    m_permutationRotor['t']='t';
    m_permutationRotor['u']='u';
    m_permutationRotor['v']='v';
    m_permutationRotor['w']='w';
    m_permutationRotor['x']='x';
    m_permutationRotor['y']='y';
    m_permutationRotor['z']='z';

    for (int i(0); i<26; ++i)
    {
        m_permutationRotor[listPermutation[0][i]]=listPermutation[1][i];
    }

}

char Rotor::activate(char charToPermute,int decalage)
{

    char charPermuted(m_permutationRotor[charToPermute]);

    map<char,char>::iterator p;
    map<char,char>::iterator q;

    map<char,char>::reverse_iterator reverse_p(p);
    map<char,char>::reverse_iterator reverse_q(q);

    map<char,char>::iterator end;

    char tmp;


    switch(decalage)
    {



    case -1:

        tmp=m_permutationRotor['z'];

        for(reverse_p=m_permutationRotor.rbegin(); reverse_p!=m_permutationRotor.rend(); reverse_p++)
        {
            reverse_q=reverse_p;
            reverse_q++;
            m_permutationRotor[reverse_p->first]=reverse_q->second;
        }

        m_permutationRotor['a']=tmp;

        return charPermuted;
        break;

    // si decalage=0 on ne decale rien
    case 0:

        return charPermuted;
        break;


    case 1:

        tmp=m_permutationRotor['a'];

        for(p=m_permutationRotor.begin(); p!=m_permutationRotor.end(); p++)
        {
            q=p;
            q++;
            m_permutationRotor[p->first]=q->second;
        }

        m_permutationRotor['z']=tmp;

        return charPermuted;
        break;
    }

    return ' ';
}


void Rotor::get_permutationTab()
{
    map<char,char>::iterator p;
    cout<<endl<<"voici la table de permutation"<<endl;
    for(p=m_permutationRotor.begin(); p!=m_permutationRotor.end(); p++)
    {
        cout<<p->first<<"  devient :   "<<p->second<<endl;

    }
    cout<<endl;
}
