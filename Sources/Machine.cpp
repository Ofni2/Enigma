#include "Machine.hpp"

using namespace std;

/**
*************************************************************************************
*
* Constructeur par defaut
*
*************************************************************************************
**/
Machine::Machine()
{

}


/**
*************************************************************************************
*
* Constructeur
*
*************************************************************************************
**/
Machine::Machine(string name,
				 map<string,Rotor> availableRotor,
				 map<string, Reflector> availableReflector,
				 int rotorMumber,
				 PlugBoard usedPlugboard)
{
	m_name = name;
	m_availableRotor = availableRotor;
	m_availableReflector= availableReflector;
	m_rotorMumber= rotorMumber;
	m_usedPlugboard= usedPlugboard;
	m_usedReflector = availableReflector.begin()->first;

	map<string, Rotor>::iterator iter_begin(availableRotor.begin()), iter_end(iter_begin);
	
	advance(iter_end, rotorMumber);

	//  par defaut les rotors utilisés sont les trois premiers de la liste des rotors disponibles
	for (iter_begin; iter_begin != iter_end; ++iter_begin) {m_usedRotor.push_back(iter_begin->first);}
}


/**
*************************************************************************************
*
* Destructeur
*
*************************************************************************************
**/
Machine::~Machine()
{
    //dtor
}


/**
*************************************************************************************
*
* Methode pour transformer un caratere avec une machine Enigma
*
* @param[in]   charToCrypt   : Charactere à chiffrer (char)
* @param[out]  charPermuted  : Charactere chiffré (char)
*
*************************************************************************************
**/
char Machine::activate(char charToCrypt)
{
	char char_crypted(' ');
	
	char R1_currentPosition,R1_stepping1,R1_stepping2;
	char R2_currentPosition, R2_stepping1, R2_stepping2;

	R1_stepping1= m_availableRotor[m_usedRotor[0]].get_stepping1();
	R1_stepping2= m_availableRotor[m_usedRotor[0]].get_stepping2();
	R2_stepping1 = m_availableRotor[m_usedRotor[1]].get_stepping1();
	R2_stepping2 = m_availableRotor[m_usedRotor[1]].get_stepping2();

	// Rotation des rotors en fonction de la position du stepping
	//middle rotor
	R1_currentPosition = (m_availableRotor[m_usedRotor[0]].get_rotorPosition()) + 64;
	if (R1_currentPosition == R1_stepping1 || R1_currentPosition == R1_stepping2){
		m_availableRotor[m_usedRotor[1]].rotate(-1);	}

	//slow rotor
    R2_currentPosition = (m_availableRotor[m_usedRotor[1]].get_rotorPosition()) + 64;
	if (R2_currentPosition == R2_stepping1 || R2_currentPosition == R2_stepping2){
		m_availableRotor[m_usedRotor[2]].rotate(-1);	}

	// A chaque chiffrage d'une lettre le premier rotor tourne
	m_availableRotor[m_usedRotor[0]].rotate(-1);

	
	// Sequence de chiffrage d'un caractere
	
	//Premier passage dans le tableau de connection
	char_crypted = m_usedPlugboard.activate(charToCrypt);
	// Premier passage dans les rotors
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, 1);
	// Passage dans le reflecteur
	char_crypted = m_availableReflector[m_usedReflector].activate(char_crypted);
	// Retour dans les rotors
	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, -1);
	// Retour dans le tableau de connection
	char_crypted = m_usedPlugboard.activate(char_crypted);

	return char_crypted;
}


/**
*************************************************************************************
*
* Methode pour 
*
* @param[in]      
* @param[in]    
*
*************************************************************************************
**/
void Machine::initStartPosition(int rotorIndex, int position)
{
	if (rotorIndex>m_rotorMumber) { /* Throw error*/}

	m_availableRotor[m_usedRotor[rotorIndex-1]].set_rotorPosition(position);
}


/**
*************************************************************************************
*
* Methode pour
*
* @param[in]
* @param[in]
*
*************************************************************************************
**/
void Machine::initRingSetting(int rotorIndex, int setting)
{
	if (rotorIndex>m_rotorMumber) { /* Throw error*/ }
	m_availableRotor[m_usedRotor[rotorIndex-1]].set_ringSetting(setting);
}


/**
*************************************************************************************
*
* Methode pour
*
* @param[in]
* @param[in]
*
*************************************************************************************
**/
void Machine::setRotor(string rotorName, int position)
{
	if (position>m_rotorMumber ||position<0) { /* Throw error*/ }
	if (m_availableRotor[rotorName].get_name()=="") { /* Throw error*/ }

	m_usedRotor[position-1]=rotorName;
}