#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include "svgfile.h"

class Sommet
{
protected:
     int m_id_sommet; // Identifiant
    double m_x, m_y; // Position

public :
    Sommet (int,double,double);
    Sommet ();
    void afficherData(Svgfile &svg) const;
    int get_m_x();
    int get_m_y();
    int get_m_id_sommet();

};


#endif // SOMMET_H_INCLUDED
