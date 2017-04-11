#include "plateaujeu.h"
#include "jeu.h"


int main()
{
    ///Permet la gestion de la Console+curseur
    Console* pConsole = NULL;
	/// Alloue la mémoire du pointeur
	pConsole = Console::getInstance();

    ///Lancement de la musique
    //PlaySound("SIAM.wav",NULL ,SND_FILENAME|SND_ASYNC|SND_NOSTOP);

    ///Permet de mettre la console en grand écran
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);

    ///Appel de la fonction debut qui affiche le mot Othello
    //debut(pConsole);

    ///Appel du menu
    menu(pConsole);

    return 0;
}
