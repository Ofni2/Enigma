#include "Machine.hpp"

#include <fstream>
#include <iostream>

using namespace std;

Machine::Machine(string name,
				 map<string,Rotor> availableRotor,
				 map<string, Reflector> availableReflector,
				 int rotorMumber,
				 vector<string> usedPlugboard)
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

	for (int i(0); i < rotorMumber; i++) ++myIt_end;

	for (myIt_begin; myIt_begin != myIt_end; ++myIt_begin)
	{
		m_usedRotor.push_back(myIt_begin->first);
	}


	
	
}

Machine::~Machine()
{
    //dtor
}

void Machine::initMachine(string name)
{



}
