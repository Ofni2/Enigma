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
    char Permutation[2][6]= {{'a','e','c','d','e','f'},{'f','e','d','c','b','a'}};
    char Ro_I[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'}};
    char Ro_II[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'}};
    char Ro_III[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'}};
    char Re_B[2][26]= {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'}};


    /* Permutation used by Enigma are defined by usera */

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
    PlugBoard connectTab(Permutation);

// 2 - initialisation du premier rotor
    Rotor rotor1("ekmflgdqvzntowyhxuspaibrcj",1,1);

// 3 - initialisation du deuxieme rotor
    Rotor rotor2("ajdksiruxblhwtmcqgznpyfvoe",1,1);

// 4 - initialisation du troisieme rotor
    Rotor rotor3("bdfhjlcprtxvznyeiwgakmusqo",1,1);

// 5 - initialisation du Reflector
    Reflector Reflector(Re_B);




//--------------
// Zone de test
//--------------
// Affichage des tables de correspondance
//Reflector.get_permutationTab();
//connectTab.get_PermutationTab();
//rotor1.get_permutationTab();
//rotor2.get_permutationTab();
//rotor3.get_permutationTab();


//text="YKAE NZAP MSCH ZBFO CUVM RMDP YCOF HADZ IZME FXTH FLOL PZLF GGBO TGOX GRET DWTJ IQHL MXVJ WKZU ASTR"*
// settings : 
//				Reflector: 	B
//				Wheel order		: III	 VI		VIII
//				Ring positions	: 01	 08		13
//				Plug pairs : AN EZ HK IJ LR MQ OT PV SW UX
//           	Message key : UZV

text = "hello";

Enigma t;

t.init();


// pour chaque caractere du texte à chiffrer
	int textSize(text.size());
    for (int i(0); i<textSize; i++)
    {
        if (text[i]==' ')
        {
            text_c=text_c+' ';
            continue;
        }

        // Sequence de cryptage d'un caractere
        char_to_crypt=text[i];

        char_crypted=connectTab.activate(char_to_crypt);
        
		char_crypted=rotor1.activate(char_crypted,1);
        char_crypted=rotor2.activate(char_crypted,1);
        char_crypted=rotor3.activate(char_crypted,1);
		
		char_crypted=Reflector.activate(char_crypted);

        char_crypted=rotor3.activate(char_crypted,-1);
        char_crypted=rotor2.activate(char_crypted,-1);
        char_crypted=rotor1.activate(char_crypted,-1);
        
		char_crypted=connectTab.activate(char_crypted);

        rotor1.rotate(-1);


        if ((i)%26==0 && i!=0)
        {
          rotor2.rotate(-1);
          j=j+1;
          if (j%26==0)
          {
              rotor3.rotate(-1);
          }
        }

        text_c=text_c+char_crypted;
    }

    cout<<"RESULTAT ---> "<< text_c <<endl;


    return 0;
}
