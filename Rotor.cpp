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
        m_permutationRotor2.insert({listPermutation[0][i],listPermutation[1][i]});
    }

}

char Rotor::activate(char charToPermute,int decalage,int sens)
{

    boost::bimap<char,char>::iterator p;
    boost::bimap<char,char>::iterator q;

    //map<char,char>::reverse_iterator reverse_p(p);
    //map<char,char>::reverse_iterator reverse_q(q);

    boost::bimap<char,char>::iterator end;

    char tmp;
    char charPermuted(m_permutationRotor[charToPermute]);


    //
    if (sens==1)
    {
        charPermuted=m_permutationRotor2.left.at(charToPermute);

    switch(decalage)
    {
/*    case -1:

//        tmp=m_permutationRotor.['z'];
        tmp=m_permutationRotor2.left.at('z');

        for(p=m_permutationRotor.end(); p!=m_permutationRotor.begin(); p--)
        {
            q=p;
            q++;
            m_permutationRotor[p->first]=q->second;
        }

        m_permutationRotor['a']=tmp;

        return charPermuted;
        break;

    // si decalage=0 on ne decale rien */
    case 0:

        return charPermuted;
        break;


    case 1:

        tmp=m_permutationRotor2.left.at('a');

        for(p=m_permutationRotor2.begin(); p!=m_permutationRotor2.end(); p++)
        {
            q=p;
            q++;
            m_permutationRotor2.left.insert(p->left,q->right);
        }

        m_permutationRotor2.left.insert('z',tmp);

        return charPermuted;
        break;
    }

    }
    else if (sens==-1)
    {
        charPermuted=m_permutationRotor2.right.at(charToPermute);
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
