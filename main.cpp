#include <iostream>

#include "PlugBoard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Machine.hpp"
#include "Enigma.hpp"


using namespace std;

int main()
{
    int i(0),j(0);
    char char_to_crypt(' ');
    char char_crypted(' ');
    string text(" ");
    string text_c("");


// configuration de la machine
   
    /* Permutation used by Enigma are defined by user */

    /* Rotor used for Enigma
    I 	   EKMFLGDQVZNTOWYHXUSPAIBRCJ ekmflgdqvzntowyhxuspaibrcj 	    1930 	    Enigma I
    II 	   AJDKSIRUXBLHWTMCQGZNPYFVOE ajdksiruxblhwtmcqgznpyfvoe 	    1930 	    Enigma I
    III    BDFHJLCPRTXVZNYEIWGAKMUSQO bdfhjlcprtxvznyeiwgakmusqo 	    1930 	    Enigma I
    IV     ESOVPZJAYQUIRHXLNFTGKDCMWB esovpzjayquirhxlnftgkdcmwb 	    Dec. 1938 	M3 Army
    V 	   VZBRGITYUPSDNHLXAWMJQOFECK vzbrgityupsdnhlxawmjqofeck 	    Dec. 1938 	M3 Army
    VI     JPGVOUMFYQBENHZRDKASXLICTW jpgvoumfyqbenhzrdkasxlictw 	    1939 	    M3 & M4 Naval (FEB 1942)
    VII    NZJHGRCXMYSWBOUFAIVLPEKQDT nzjhgrcxmyswboufaivlpekqdt 	    1939 	    M3 & M4 Naval (FEB 1942)
    VIII   FKQHTLXOCBJSPDZRAMEWNIUYGV fkqhtlxocbjspdzramewniuygv
	*/

    /* Reflector used for Enigma
    reflector B	        (AY) (BR) (CU) (DH) (EQ) (FS) (GL) (IP) (JX) (KN) (MO) (TZ) (VW)
    reflector C	        (AF) (BV) (CP) (DJ) (EI) (GO) (HY) (KR) (LZ) (MX) (NW) (TQ) (SU)
    reflector B Dünn	(AE) (BN) (CK) (DQ) (FU) (GY) (HW) (IJ) (LO) (MP) (RX) (SZ) (TV)
    reflector C Dünn	(AR) (BD) (CO) (EJ) (FN) (GT) (HK) (IV) (LM) (PW) (QZ) (SX) (UY)
    */

//initialisation de la machine
// 1 - initialisation du tableau de permutation
// 2 - initialisation du premier rotor
// 3 - initialisation du deuxieme rotor
// 4 - initialisation du troisieme rotor
// 5 - initialisation du Reflector




//--------------
// Zone de test
//--------------


//text="YKAE NZAP MSCH ZBFO CUVM RMDP YCOF HADZ IZME FXTH FLOL PZLF GGBO TGOX GRET DWTJ IQHL MXVJ WKZU ASTR"*
// settings : 
//				Reflector: 	B
//				Wheel order		: III	 VI		VIII
//				Ring positions	: 01	 08		13
//				Plug pairs : AN EZ HK IJ LR MQ OT PV SW UX
//           	Message key : UZV

text = "HELLO";

Enigma t;
Machine M;
PlugBoard P;


t.init();

M=t.get_machine("Enigma I");


M.setRotor("V", 1);
M.setRotor("II", 2);
M.setRotor("I", 3);



M.initRingSetting(1, 14);
M.initRingSetting(2, 22);
M.initRingSetting(3, 6);

M.initStartPosition(1, 2);
M.initStartPosition(2, 23);
M.initStartPosition(3, 24);


text = "QBLTWLDAHHYEOEFPTWYBLENDPMKOXLDFAMUDWIJDXRJZ";
//solution = DERFU EHRER ISTTO DXDER KAMPF GEHTW EITER XDOEN ITZX

int textSize(text.size());
for (int i(0); i<textSize; i++)
{
	if (text[i] == ' ')
	{
		text_c = text_c + ' ';
		continue;
	}

	char_crypted=M.activate(text[i]);
	text_c = text_c + char_crypted;

}

cout << "RESULTAT ---> " << text_c << endl;
 


    return 0;
}
