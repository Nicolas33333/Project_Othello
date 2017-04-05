#ifndef PION_H_INCLUDED
#define PION_H_INCLUDED

class Pion
 {
    private:
        bool m_cote; /// 0 si blanc, 1 si noir
        int m_ligne;
        int m_colonne;
        bool m_visible; /// 0 si à l'exterieur du plateau, 1 si à l'interieur

    public:
    Pion();
    ~Pion();

    ///Acesseurs
    bool getcote() { return m_cote; }
    int getligne() {return m_ligne; }
    int getcolonne() { return m_colonne;}
    bool getvisible() {return m_visible;}

    //void Setcote(bool cote) {}

 };
#endif // PION_H_INCLUDED
