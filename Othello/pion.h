#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED


#include "console.h"

enum
{
    NOIR /*= 0*/,
    BLANC /*= 1*/,
};

class Pion
 {
    private:
        bool m_couleur; /// 0 si noir, 1 si blanc
        int m_ligne;
        int m_colonne;
        bool m_visible; /// 0 si à l'exterieur du plateau, 1 si à l'interieur

    public:
    Pion();
    ~Pion();

    ///Acesseurs
    bool getcouleur() { return m_couleur; }
    void setcouleur(bool _couleur) {m_couleur=_couleur; }
    int getligne() {return m_ligne; }
    void setligne(int _ligne) {m_ligne = _ligne; }
    int getcolonne() { return m_colonne;}
    void setcolonne (int _colonne) {m_colonne = _colonne; }
    bool getvisible() {return m_visible;}
    void setvisible (bool _visible) {m_visible = _visible; }

    //void Setcote(bool cote) {}

    void placer_pions(); ///a faire
    void encadrement(); /// a faire

    void afficher_pions(Console *pConsole, int l, int c);

 };

#endif // PION_H_INCLUDED
