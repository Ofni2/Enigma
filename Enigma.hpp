#ifndef ENIGMA_H
#define ENIGMA_H

#include <map>
#include <string>

class Enigma
{

public:
	
	Enigma();
	~Enigma();

	void init();


protected:



private:
	std::map<int, std::string> m_availableMachine;
	std::map<int, std::string> m_availableRotor;
	std::map<int, std::string> m_availableReflector;
};



#endif // ENIGMA_H