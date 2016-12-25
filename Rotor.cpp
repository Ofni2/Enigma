#include "Rotor.hpp"


using namespace std;



/**
************************
* Constructeur par defaut
************************
**/
Rotor::Rotor()
{
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('a','a'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('b','b'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('c','c'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('d','d'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('e','e'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('f','f'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('g','g'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('h','h'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('i','i'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('j','j'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('k','k'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('l','l'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('m','m'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('n','n'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('o','o'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('p','p'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('q','q'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('r','r'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('s','s'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('t','t'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('u','u'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('v','v'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('w','w'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('x','x'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('y','y'));
    m_permutationRotor.insert(boost::bimap<char,char>::value_type('z','z'));
}
/**
************************
* Constructeur
************************
**/
Rotor::Rotor(const char listPermutation[2][26])
{

    for (int i(0); i<26; ++i)
    {
        m_permutationRotor.insert(boost::bimap<char,char>::value_type(listPermutation[0][i],listPermutation[1][i]));
    }
}

/**
*************************************************************************************
* Methode pour transformer un caratere à partir d'un table de correspondance
* la table peut etre lue de gauche à droite ou de droite à gauche en fonction
* de la variable "sens"
*
* @param[in]   sens          : indique dans quel sens lire la table de correspondance
* @param[in]   charToPermute : charactere à crypter
* @param[out]  charPermuted  : charactere crypté
*
*************************************************************************************
**/
char Rotor::activate(char charToPermute,int sens)
{
    char charPermuted(' ');

    switch (sens)
    {
        case 1:
            charPermuted=m_permutationRotor.left.at(charToPermute);
            break;

        case -1:
            charPermuted=m_permutationRotor.right.at(charToPermute);
            break;
    }

    return charPermuted;
}

/**
*************************************************************************************
* Methode pour afficher la table de correspondance
*
*************************************************************************************
**/
void Rotor::get_permutationTab()
{
    boost::bimap<char,char>::iterator p;
    boost::bimap<char,char>::iterator q;
    boost::bimap<char,char>::iterator end;

    cout<<endl<<"voici la table de permutation"<<endl;

    for( p = m_permutationRotor.begin(); p != m_permutationRotor.end(); ++p )
    {
        cout<<p->left<<"  <-->  "<<p->right<<endl;
    }
}



/**
*************************************************************************************
* Methode pour decaler d'un cran les elements de la table de correspondance
*
* @param[in] decalage : indique le sens de decalage de la table
*************************************************************************************
**/
void Rotor::rotate(int decalage)
{
    //boost::bimap<char,char>::left_iterator pl;
    //boost::bimap<char,char>::left_iterator plend;
    //boost::bimap<char,char>::left_iterator ql;
    boost::bimap<char,char>::right_iterator pr;
    boost::bimap<char,char>::right_iterator qr;


    typedef boost::bimap< char, char > bm_type;
bm_type bm;

typedef bm_type::left_map::const_iterator left_const_iterator;


    char tmp(' ');

    switch(decalage)
    {

        case -1:

            tmp=m_permutationRotor.right.at('z');

            for(pr = m_permutationRotor.right.begin(); pr!=m_permutationRotor.right.end(); pr++)
            {
                qr=pr;
                qr++;
                m_permutationRotor.right.modify_data( pr, boost::bimaps::_data = qr->first );
            }

            pr=m_permutationRotor.right.find('a');
            m_permutationRotor.right.modify_data( pr, boost::bimaps::_data = tmp );

            break;

        case 1:

            tmp=m_permutationRotor.left.at('a');


    //for( left_const_iterator left_iter = bm.left.begin(), iend = bm.left.end();
    // left_iter != iend; ++left_iter )


for( left_const_iterator left_iter = m_permutationRotor.left.begin(), iend = m_permutationRotor.left.end();
     left_iter != iend; ++left_iter )


            //for( pl = m_permutationRotor.left.begin(), plend=m_permutationRotor.left.end(); pl != plend; ++pl )
            {
                //ql=pl;
                //ql++;
                //left_iter->second=left_iter->second;
                //m_permutationRotor.left.modify_data( pl, boost::bimaps::_data = ql->second );
            }
            //pl=m_permutationRotor.left.find('z');
            //m_permutationRotor.left.modify_data( pl, boost::bimaps::_data = tmp );


            break;

        case 0:
            break;
    }
}
