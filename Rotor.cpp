#include "Rotor.hpp"



using namespace std;



/**
*************************************************************************************
*
* Constructeur par defaut
*
*************************************************************************************
**/
Rotor::Rotor()
{
	m_name = "noName";

	m_ringSetting = 1;
	m_startPosition = 1;
	m_position = 0;

	m_steppingPosition1 = 'Z';
	m_steppingPosition2 = ' ';
	
	for (int i(0); i < 26; ++i)
	{
		m_internalWiringTab[0][i] = 64+i;
		m_internalWiringTab[1][i] = 64+i;
	}
}



/**
*************************************************************************************
*
* Constructeur
*
*************************************************************************************
**/
Rotor::Rotor(string internalWiring, const int &ringSetting, const int &startPosition, const char &stepping1, const char &stepping2, const string &name)
{
		m_name = name;

		m_ringSetting = ringSetting;
		m_startPosition = startPosition;
		m_position = 0;


		// Les caracteres sont converti en majuscules. Si le caractere n'est pas une lettre on lance une erreure 

		if ((stepping1 >= 'a' && stepping1 <= 'z'))	    { m_steppingPosition1 = stepping1 - 32;}
		else if ((stepping1 >= 'A' && stepping1 <= 'Z')){ m_steppingPosition1 = stepping1;     }
		else {	/* Throw exception*/ }

		if ((stepping2 >= 'a' && stepping2 <= 'z'))		{ m_steppingPosition2 = stepping2 - 32;}
		else if ((stepping2 >= 'A' && stepping2 <= 'Z')){ m_steppingPosition2 = stepping2;	   }
		else {	/* Throw exception*/ }

		for (int i(0); i < 26; ++i)
		{
			m_internalWiringTab[0][i] = i+65;
			
			if ((internalWiring[i] >= 'a' && internalWiring[i] <= 'z'))	     { m_internalWiringTab[1][i] = internalWiring[i] - 32; }
			else if ((internalWiring[i] >= 'A' && internalWiring[i] <= 'Z')) { m_internalWiringTab[1][i] = internalWiring[i];	   }
			else { /*Throw exception: init rotor initialisation pb */}
		}
}



/**
*************************************************************************************
*
* Methode pour transformer un caratere à partir d'un table de correspondance
* la table peut etre lue de gauche à droite ou de droite à gauche en fonction
* de la variable "sens"
*
* @param[in]   sens          : indique dans quel sens lire la table de correspondance
* @param[in]   charToPermute : charactere à chiffrer
* @param[out]  charPermuted  : charactere chiffrer
*
*************************************************************************************
**/
char Rotor::activate(char charToPermute,int sens)
{
    char charPermuted(' ');
	int offset,index(0);
	
	//transform input char into an integer between 1 and 26 (a=1, ... ,Z=26)
	// if the char is not a lettre throw an error
	if ((charToPermute >= 'a' && charToPermute <= 'z')) { charToPermute = charToPermute - 96; }
	else if ((charToPermute >= 'A' && charToPermute <= 'Z')) { charToPermute = charToPermute - 64; }
	else { /*throw exception*/}
		
    switch (sens)
    {
        case 1:


			offset = (m_startPosition+m_position) - m_ringSetting + (charToPermute) - 1 ;
			if (offset < 0) { offset = 26 - ((-offset) % 26); }
			charPermuted = offset % 26 + 1;
			for (int i(0); i < 26; i++) {if ((m_internalWiringTab[0][i]) == (charPermuted+64)) { index = i; break; }}

			charPermuted = m_internalWiringTab[1][index]-64;
			offset = -(m_startPosition+m_position) + m_ringSetting + charPermuted - 1;
			if (offset < 0) { offset = 26 - ((-offset) % 26); }
			charPermuted = offset % 26 + 1 + 64;

            break;

        case -1:

			offset = (m_startPosition + m_position) - m_ringSetting  + (charToPermute) - 1 ;
			if (offset < 0) { offset = 26 - ((-offset) % 26); }
			charPermuted = offset % 26 + 1;

			for (int i(0); i < 26; i++) { if (m_internalWiringTab[1][i] == (charPermuted + 64)) { index = i; break; } }

			charPermuted = m_internalWiringTab[0][index]-64;//-64
			offset = -(m_startPosition+ m_position) + m_ringSetting  + charPermuted - 1;
			if (offset < 0) { offset = 26 - ((-offset)%26); }
			charPermuted = offset % 26 + 1 + 64;

            break;
    }

    return charPermuted;
}



/**
*************************************************************************************
*
* Methode pour afficher la table de correspondance
*
*************************************************************************************
**/
void Rotor::DisplayPermutationTab()
{
    cout<<endl<<"voici la table de permutation"<<endl;

    for (int i(0);i<26;i++)
    {
        cout<<m_internalWiringTab[0][i]<<"  <-->  "<<m_internalWiringTab[1][0]<<endl;
    }
}


/**
*************************************************************************************
*
* Methode pour faire tourner d'un cran le rotor (décalage du cablage par rapport aux
* connecteurs d'entré
*
* @param[in] decalage : indique le sens de decalage de la table
*
*************************************************************************************
**/
void Rotor::rotate(int decalage)
{
	switch (decalage)
	{

	case -1:
		m_position++;
		break;

	case 1:
		m_position--;
		break;

	case 0:
		break;
	}
}


/**
*************************************************************************************
*
* Methode pour obtenir le reglage du rotor
*
* @param[out] return : indique le reglage du rotor (int)
*
*************************************************************************************
**/
int Rotor::get_ringSetting()
{
	return m_ringSetting;
}


/**
*************************************************************************************
*
* Methode pour obtenir la position du rotor
*
* @param[out] return : indique la position du rotor. ( Entier compris entre 1(=a) et 26(=z) ) 
*
*************************************************************************************
**/
int Rotor::get_rotorPosition()
{		
	return ((m_startPosition+m_position) - 1) % 26 + 1;;
}


/**
*************************************************************************************
*
* Methode pour définir la position de départ du rotor
*
* @param[int] int : définit la position du rotor ( ?? < i < ?? )
*
*************************************************************************************
**/
void Rotor::set_rotorPosition(int i)
{
	m_startPosition = i;
}


/**
*************************************************************************************
*
* Methode pour définir le reglage du rotor
*
* @param[int] int : définit la position du rotor ( ?? < i < ?? )
*
*************************************************************************************
**/
void Rotor::set_ringSetting(int i)
{
	m_ringSetting = i;
}


/**
*************************************************************************************
*
* Methode pour définir le nom du rotor
*
* @param[in] string : nom du rotor
*
*************************************************************************************
**/
void Rotor::set_name(std::string name)
{
	m_name = name;
}


/**
*************************************************************************************
*
* Methode pour obtenir le nom du rotor
*
* @param[out] return : donne le nom du rotor  (string)
*
*************************************************************************************
**/
string Rotor::get_name()
{
	return m_name;
}


/**
*************************************************************************************
*
* Methode qui donne le premier caractere impliquant un decallage du rotor suivant  (stepping)
*
* @param[out] return : donne le caractere de "stepping" (char)
*
*************************************************************************************
**/
char Rotor::get_stepping1()
{
	return m_steppingPosition1;
}


/**
*************************************************************************************
*
* Methode qui donne le deuxieme caractere impliquant un decallage du rotor suivant  (stepping)
*
* @param[out] return : donne le caractere de "stepping" (char)
*
*************************************************************************************
**/
char Rotor::get_stepping2()
{
	return m_steppingPosition2;
}


/**
*************************************************************************************
*
* Methode pour réinitialiser un rotor
*
*************************************************************************************
**/
void Rotor::reset()
{

}
