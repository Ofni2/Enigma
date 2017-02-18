#ifndef MACHINE_H
#define MACHINE_H

#include <string>
#include <map>
#include "Rotor.hpp"
#include "Reflector.hpp"


class Machine
{
    public:
        Machine();
        ~Machine();
		
		void initMachine(std::string name);


    protected:

		std::string m_name;
		int m_rotorMumber;
		
		//std::map<int,Rotor::Rotor*> m_availableRotor;
		int m_usedRotor;
		
		int m_availableReflector;
		int m_usedReflector;

		

    private:

};

#endif // MACHINE_H
