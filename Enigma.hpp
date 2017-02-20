#ifndef ENIGMA_H
#define ENIGMA_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Machine.hpp"

class Enigma
{

public:
	
	Enigma();
	~Enigma();

	void init();

	Machine get_machine(std::string name);



protected:



private:
	std::map<std::string, Machine> m_availableMachine;
	std::map<std::string, Rotor> m_availableRotor;
	std::map<std::string, Reflector> m_availableReflector;
};



#endif // ENIGMA_H