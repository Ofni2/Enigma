#include "Machine.hpp"

#include <fstream>
#include <iostream>

using namespace std;

Machine::Machine()
{

}

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

	for (iter_begin; iter_begin != iter_end; ++iter_begin) {m_usedRotor.push_back(iter_begin->first);}
}

Machine::~Machine()
{
    //dtor
}

char Machine::initMachine(char char_to_crypt)
{
	return ' ';
}


char Machine::activate(char charToCrypt)
{
	char char_crypted(' ');
	
	char R1_currentPosition,R1_stepping1,R1_stepping2;
	char R2_currentPosition, R2_stepping1, R2_stepping2;
	char R3_currentPosition;

	R1_currentPosition = (m_availableRotor[m_usedRotor[0]].get_rotorPosition()) + 64;
	R1_stepping1= m_availableRotor[m_usedRotor[0]].get_stepping1();
	R1_stepping2= m_availableRotor[m_usedRotor[0]].get_stepping2();
		
	R2_currentPosition = (m_availableRotor[m_usedRotor[1]].get_rotorPosition()) + 64;
	R2_stepping1 = m_availableRotor[m_usedRotor[1]].get_stepping1();
	R2_stepping2 = m_availableRotor[m_usedRotor[1]].get_stepping2();

	R3_currentPosition = (m_availableRotor[m_usedRotor[2]].get_rotorPosition()) + 64;
	

	// Rotation des rotors en fonction de la position du stepping
	if (R1_currentPosition == R1_stepping1 || R1_currentPosition == R1_stepping2){
		m_availableRotor[m_usedRotor[1]].rotate(-1);	}
	if (R2_currentPosition == R2_stepping1 || R2_currentPosition == R2_stepping2){
		m_availableRotor[m_usedRotor[2]].rotate(-1);	}

	// A chaque chiffrage d'une lettre le premier rotor tourne
	m_availableRotor[m_usedRotor[0]].rotate(-1);

	
	// Sequence de chiffrage d'un caractere
	
	//Premier passage dans le tableau de connection
	char_crypted = m_usedPlugboard.activate(charToCrypt);
	// Premier passage dans les rotor
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, 1);
	// Passage dans le reflecteur
	char_crypted = m_availableReflector[m_usedReflector].activate(char_crypted);
	// Retour dans les rotor
	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, -1);
	// Retour dans le tableau de connection
	char_crypted = m_usedPlugboard.activate(char_crypted);

	return char_crypted;



}


void Machine::initStartPosition(int rotorIndex, int position)
{
	if (rotorIndex>m_rotorMumber) { /* Throw error*/}

	m_availableRotor[m_usedRotor[rotorIndex-1]].set_rotorPosition(position);
}

void Machine::initRingSetting(int rotorIndex, int setting)
{
	if (rotorIndex>m_rotorMumber) { /* Throw error*/ }
	m_availableRotor[m_usedRotor[rotorIndex-1]].set_ringSetting(setting);
}

void Machine::setRotor(string rotorName, int position)
{
	if (position>m_rotorMumber ||position<0) { /* Throw error*/ }
	if (m_availableRotor[rotorName].get_name()=="") { /* Throw error*/ }

	m_usedRotor[position-1]=rotorName;
}