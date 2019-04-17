#include "arete.h"
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<unordered_set>
#include "svgfile.h"

Arete::Arete(int id_arete,int Init , int fin, float poids) : m_id_arete {id_arete},m_init{Init}, m_fin {fin}, m_poids {poids}
{
}

 ///a voir
float Arete::get_poids()
{
    return m_poids;
}

int Arete::get_m_init()
{
    return m_init;
}

int Arete::get_m_fin()
{
    return m_fin;
}


///pour comparer les poids
bool comparaison (Arete *uno, Arete *dos)
{
    return uno->get_poids()<dos->get_poids(); ///ca va begayer avec les m_ donc à voir avec des pros
}

/// mise à jour du tableau de connexité
int findvalsom(int j, int *valsom)
{
    if (valsom[j]==j)
    {
        return j;
    }
    return findvalsom(valsom[j], valsom);
}

///changer les m_x en m_init etc...
void kruskal(std::vector<Arete*> tabArete, int nbresom,int nbrear)
{
    std::sort(tabArete.begin(),tabArete.end(),[](Arete *uno,Arete *dos)
    {
       return uno->get_poids()<dos->get_poids(); ///ca va begayer avec les m_ donc à voir avec des pros
    });



    std::vector<Arete*> connexite;
    //Arete *connexite= new Arete [nbresom-1];
    int *valsom = new int[nbresom];


    for ( int i=0;i<nbresom;i++)
    {
        valsom[i]=i;
    }

    int cmpt=0;
    int i=0;

    while(cmpt!=nbresom-1)
    {
        Arete* areteActuelle=tabArete[i]; ///on regarde si l'ajout de l'arete actuelle ne forme pas un cycle
        int m_initValsom=findvalsom(areteActuelle->get_m_init(),valsom);
        int m_finValsom=findvalsom(areteActuelle->get_m_fin(), valsom);

        if (m_initValsom != m_finValsom)
        {
            connexite.push_back(areteActuelle);
            cmpt++;
            valsom[m_finValsom]=m_initValsom;
        }i++;
    }
    for (int i=0;i<nbresom-1;i++)
    {
        if (connexite[i]->get_m_init() < connexite[i]->get_m_fin())
        {
            std::cout << connexite[i]->get_m_init() <<" " <<connexite[i]->get_m_fin() << " "<< connexite[i]->get_poids()<< std::endl;
        }
        else
        {
            std::cout << connexite[i]->get_m_fin()<<" " << connexite[i]->get_m_init() << " " << connexite[i]->get_poids()<< std::endl;
        }
    }
}


