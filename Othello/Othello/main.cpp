#include "Plateau.h"
#include "jeu.h"


int main()
{
    ///Lancement de la musique
    //PlaySound("SIAM.wav",NULL ,SND_FILENAME|SND_ASYNC|SND_NOSTOP);

    ///Grand écran
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);

    ///Appel du menu
    menu();

    return 0;
}
