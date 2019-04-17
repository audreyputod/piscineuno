#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "sommet.h"

class Arete
{
public :
    Arete(int,int,int,float);
    int get_m_fin();
    int get_m_init();
    //void afficherData() ;
    //void comparaison();

    float get_poids();

protected :
    float m_poids;
    int m_init,m_fin,m_id_arete;

};
    void kruskal(std::vector<Arete*> tabArete, int nbresom,int nbrear);
    bool comparaison (Arete *uno, Arete *dos);
#endif // ARETE_H_INCLUDED




