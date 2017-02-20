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


	map<string, Rotor>::iterator myIt_begin;
	map<string, Rotor>::iterator myIt_end;

	myIt_begin = availableRotor.begin();
	myIt_end = myIt_begin;
	std::advance(myIt_end, rotorMumber);

	for (myIt_begin; myIt_begin != myIt_end; ++myIt_begin)
	{
		m_usedRotor.push_back(myIt_begin->first);
	}


	
	
}

Machine::~Machine()
{
    //dtor
}

char Machine::initMachine(char char_to_crypt)
{
	char char_crypted;
	
	// Sequence de cryptage d'un caractere
	//char_crypted = connectTab.activate(char_to_crypt);
	char_crypted = char_to_crypt;
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, 1);
	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, 1);

	char_crypted = m_availableReflector[m_usedReflector].activate(char_crypted);

	char_crypted = m_availableRotor[m_usedRotor[2]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[1]].activate(char_crypted, -1);
	char_crypted = m_availableRotor[m_usedRotor[0]].activate(char_crypted, -1);

	//char_crypted = connectTab.activate(char_crypted);

	m_availableRotor[m_usedRotor[0]].rotate(-1);


	return char_crypted;


}
