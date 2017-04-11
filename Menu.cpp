#include "jeu.h"
#include "plateaujeu.h"

void menu(Console*pConsole)
{
    ///on clean l'ecran
    system("cls");

	bool sortie = false;

        pConsole->gotoLigCol(2,50);
	    cout <<"**********"<<endl;
	    pConsole->gotoLigCol(3,50);
	    cout << "*        *"<<endl;
	    pConsole->gotoLigCol(4,50);
	    cout <<"*  Menu  *"<<endl;
        pConsole->gotoLigCol(5,50);
	    cout << "*        *"<<endl;
	    pConsole->gotoLigCol(6,50);
	    cout <<"**********"<<endl;

        for (int i=0; i<6; i++)
        {
            pConsole->gotoLigCol(10+3*i,15);

            if(i==0) cout << " * Commencer une nouvelle partie (2 joueurs) "<<endl;
            if(i==1) cout << " * Commencer une nouvelle partie contre l'ordinateur" << endl;
            if(i==2) cout << " * Reprendre une partie"<<endl;
            if(i==3) cout << " * Regles du jeu"<<endl;
            if(i==4) cout << " * Credits"<< endl;
            if(i==5) cout << " * Quitter le jeu"<<endl;
        }
        ///On place le curseur au position 10, 16 ( Commencer une nouvelle partie).
        int ligne=10;
        int colonne=16;
        pConsole->gotoLigCol(ligne,colonne);

    while(!sortie)
        {
        /// On recupere la valeur que l'utilisateur tappe
        char caractere = getch();
        ///on modifie l'endroit du curseur avec les touches 2,4,6,8+ blindage
        if ((caractere == TOUCHEHAUT)&&(ligne>10)) { pConsole->gotoLigCol((ligne-3),colonne), (ligne)=(ligne-3 ); }
        if ((caractere == TOUCHEBAS)&&(ligne<23)) { pConsole->gotoLigCol((ligne+3),colonne), (ligne)=(ligne+3) ; }


        if (caractere==13) /// Si on appuie sur la touche Entrée (13 en caractère ASCII)
        {
        caractere=0;

		///En fonction de la ligne, on appelle les différentes fonctions
            switch(ligne)
            {
            case 10 : ///Nouvelle partie entre 2 joueurs
                system("cls");
                jeu(pConsole); /// Lancement d'une partie
                break;

            case 13: ///Nouvelle partie contre l'IA
                system("cls");
                cout <<"Nouvelle partie contre l'IA"<<endl;
                //jeu(pConsole);
                menu(pConsole); ///on rappelle le menu
                break;

            case 16: ///Reprendre une partie
                system("cls");
                //recup_sauvegarde(tab);
                cout << "A faire"<<endl;
                system("pause");
                menu(pConsole); ///on rappelle le menu
                break;

            case 19:/// Règles du jeu
                system("cls");
                cout <<"Regle du jeu Othello"<< endl;

                system("pause > nul");
                menu(pConsole);
                break;

            case 22: /// Crédits
                system("cls");
                pConsole->gotoLigCol(13,10);
                cout<< "Jeu realise par :"<<endl;
                pConsole->gotoLigCol(17,10);
                cout<< "Uza-Lara Karthigesu"<<endl;
                pConsole->gotoLigCol(19,10);
                cout<< "Nicolas Baralle"<<endl;
                pConsole->gotoLigCol(21,10);
                cout<< "Theophane Vu"<<endl;
                 pConsole->gotoLigCol(23,10);
                cout<< "ECE PARIS ING2, TD07"<<endl;
                cout <<endl;
                cout<< endl;
                system("pause");
                menu(pConsole);

                break;


            case 25:/// quitter le jeu
                sortie = true;
                pConsole->gotoLigCol(30,10);
                cout << "Merci d'avoir joue au jeu Othello"<<endl;
                system("pause > nul");
                break;

            default:
                ///Si erreur de saisie
                pConsole->gotoLigCol(30,10);
                cout << "Erreur de saisie."<<endl;
                system("pause > nul");
                break;

                } ///fin switch
        }///fin if
    }///fin while
}


void debut(Console*pConsole)
{
        std::cout << std::endl;
        ifstream fichier("Othello.txt", ios::in);  // on ouvre le fichier en lecture

        if(fichier) // si l'ouverture a réussi
            {
                string contenu[20];  // déclaration d'une chaîne qui contiendra la ligne lue

                system("cls");

                pConsole->gotoLigCol(12,20);
                for(int i=0;i<20;i++)
                {
                   // cout << "     ";
                    getline(fichier, contenu[i]);  // on met dans "contenu" la ligne
                   // fichier >> contenu[i];
                    cout<< contenu[i];
                     Sleep(70);
                    cout<<endl;
                    //cout<<endl;

                        /*if((i==0)||(i==5)) pConsole->setColor(COLOR_WHITE);
                        if((i==1)||(i==6)) pConsole->setColor(COLOR_GREEN);
                        if((i==2)||(i==7)) pConsole->setColor(COLOR_RED);
                        if((i==3)||(i==8)) pConsole->setColor(COLOR_PURPLE);
                        if((i==4)||(i==9)) pConsole->setColor(COLOR_BLUE);*/

                        if((i==0)||(i==1)||(i==6)||(i==7)||(i==12)||(i==13)) pConsole->setColor(COLOR_BLUE);
                        if((i==2)||(i==3)||(i==8)||(i==9)||(i==14)||(i==15)) pConsole->setColor(COLOR_WHITE);
                        if((i==4)||(i==5)||(i==10)||(i==11)||(i==16)||(i==17)) pConsole->setColor(COLOR_RED);

                }
                pConsole->setColor(COLOR_DEFAULT);
                pConsole->gotoLigCol(35,70);
                cout<< "U", Sleep(70), cout <<"z", Sleep(70), cout <<"a", Sleep(70), cout <<"-", Sleep(70), cout <<"L", Sleep(70), cout <<"a", Sleep(70), cout <<"r", Sleep(70), cout <<"a";
                Sleep(70), cout <<" ", Sleep(70), cout <<"K", Sleep(70), cout <<"e", Sleep(70), cout <<"r", Sleep(70), cout <<"t", Sleep(70), cout <<"h", Sleep(70), cout <<"i", Sleep(70), cout <<"g", Sleep(70), cout <<"e", Sleep(70), cout <<"s", Sleep(70), cout <<"u";
                Sleep(70);
                Sleep(70);
                pConsole->gotoLigCol(38,70);
                Sleep(70), cout <<"N", Sleep(70), cout <<"i", Sleep(70), cout <<"c", Sleep(70), cout <<"o", Sleep(70), cout <<"l", Sleep(70), cout <<"a", Sleep(70), cout <<"s", Sleep(70), cout <<" ";
                Sleep(70), cout <<"B", Sleep(70), cout <<"a", Sleep(70), cout <<"r", Sleep(70), cout <<"a", Sleep(70), cout <<"l", Sleep(70), cout <<"l", Sleep(70), cout <<"e";
                Sleep(70);
                Sleep(70);
                pConsole->gotoLigCol(41,70);
                Sleep(70), cout <<"T",Sleep(70), cout <<"h",Sleep(70),cout <<"e",Sleep(70), cout <<"o",Sleep(70), cout <<"p",Sleep(70), cout <<"h",Sleep(70), cout <<"a",Sleep(70), cout <<"n",Sleep(70), cout <<"e";
                Sleep(70), cout <<" ",Sleep(70), cout <<"V",Sleep(70), cout <<"u",
                Sleep(200);

                fichier.close();  // on ferme le fichier
                }
                    else  cout << "Impossible d'ouvrir le fichier !" << endl;


}

