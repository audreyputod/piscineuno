#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "sommet.h"

class Arete
{
public :
    Arete(int,int,int,float,float);
    Arete(Arete* arete)
    {

        m_poids1 = arete->get_poids1();

        m_poids2 = arete->get_poids2();

        m_init = arete->get_m_init();

        m_fin=arete->get_m_fin();

        m_id_arete=arete->get_m_id_arete();


    }
    int get_m_fin();
    int get_m_init();
    int get_m_id_arete();

    //void afficherData() ;
    //void comparaison();

    float get_poids1();
    float get_poids2();

protected :
    float m_poids1,m_poids2;
    int m_init,m_fin,m_id_arete;

};
        std::vector<Arete> kruskal(std::vector<Arete*> tabArete, int nbresom,int nbrear);
        bool comparaison (Arete *uno, Arete *dos);
        std::vector<Arete> kruskal2(std::vector<Arete*> tabArete, int nbresom,int nbrear);
        bool comparaison2 (Arete *uno, Arete *dos);
        std::vector<std::vector<bool>>binaire(std::vector<Arete*> m_aretes);
        std::vector<std::vector<bool>> Selection1 (std::vector<std::vector<bool>>tab3,std::vector<Arete*> m_aretes,std::vector<Sommet*>m_sommets);
        std::vector<std::vector<bool>> Selection2 (std::vector<std::vector<bool>>tab4,std::vector<Arete*> m_aretes,std::vector<Sommet*>m_sommets);
//        void affichage_tableau(,std::vector<std::vector<bool>>tab3);
#endif // ARETE_H_INCLUDED




