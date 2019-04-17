#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
class Sommet
{
protected:
     int m_id_sommet; // Identifiant
    double m_x, m_y; // Position

public :
    Sommet (int,double,double);
    Sommet ();
    void afficherData() const;

};


#endif // SOMMET_H_INCLUDED
