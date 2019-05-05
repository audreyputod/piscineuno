#include "arete.h"
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<unordered_set>
#include "svgfile.h"
#include <fstream>

Arete::Arete(int id_arete,int Init , int fin, float poids1,float poids2) : m_id_arete {id_arete},m_init{Init}, m_fin {fin}, m_poids1 {poids1}, m_poids2 {poids2}
{
}

 ///a voir
float Arete::get_poids1()
{
    return m_poids1;
}

int Arete::get_m_init()
{
    return m_init;
}

int Arete::get_m_fin()
{
    return m_fin;
}
int Arete::get_m_id_arete()
{
    return m_id_arete;
}
float Arete::get_poids2()
{
    return m_poids2;
}

///pour comparer les poids
bool comparaison (Arete *uno, Arete *dos)
{
     return uno->get_poids1()<dos->get_poids1(); ///ca va begayer avec les m_ donc à voir avec des pros
}
bool comparaison2 (Arete *uno, Arete *dos)
{
     return uno->get_poids2()<dos->get_poids2(); ///ca va begayer avec les m_ donc à voir avec des pros
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
std::vector<Arete> kruskal(std::vector<Arete*> tabArete, int nbresom,int nbrear)
{
    std::sort(tabArete.begin(),tabArete.end(),[](Arete *uno,Arete *dos)
    {
       return uno->get_poids1()<dos->get_poids1(); ///ca va begayer avec les m_ donc à voir avec des pros
    });




    std::vector<Arete> connexite;
    //Arete *connexite= new Arete [nbresom-1];
    int *valsom = new int[nbresom];


    for ( int i=0;i<nbresom;i++)
    {
        valsom[i]=i;
    }

    int cmpt=0;
    int j=0;


    while(cmpt!=nbresom-1)
    {

        Arete areteActuelle = *tabArete[j]; ///on regarde si l'ajout de l'arete actuelle ne forme pas un cycle

        int m_initValsom=findvalsom(areteActuelle.get_m_init(),valsom);
        int m_finValsom=findvalsom(areteActuelle.get_m_fin(), valsom);
        if (m_initValsom != m_finValsom)
        {

            connexite.push_back(areteActuelle);
            cmpt++;
            valsom[m_finValsom]=m_initValsom;
        }j++;
    }
    for (int i=0;i<nbresom-1;i++)
    {
        if (connexite[i].get_m_init() < connexite[i].get_m_fin())
        {
            std::cout << connexite[i].get_m_init() <<" " <<connexite[i].get_m_fin() << " "<< connexite[i].get_poids1()<< std::endl;
        }
        else
        {
            std::cout << connexite[i].get_m_fin()<<" " << connexite[i].get_m_init() << " " << connexite[i].get_poids1()<< std::endl;
        }
    }
    return connexite;
}


std::vector<Arete> kruskal2(std::vector<Arete*> tabArete, int nbresom,int nbrear)
{
    std::sort(tabArete.begin(),tabArete.end(),[](Arete *uno,Arete *dos)
    {
       return uno->get_poids2()<dos->get_poids2(); ///ca va begayer avec les m_ donc à voir avec des pros
    });




    std::vector<Arete> connexite;
    //Arete *connexite= new Arete [nbresom-1];
    int *valsom = new int[nbresom];


    for ( int i=0;i<nbresom;i++)
    {
        valsom[i]=i;
    }

    int cmpt=0;
    int j=0;


    while(cmpt!=nbresom-1)
    {

        Arete areteActuelle = *tabArete[j]; ///on regarde si l'ajout de l'arete actuelle ne forme pas un cycle

        int m_initValsom=findvalsom(areteActuelle.get_m_init(),valsom);
        int m_finValsom=findvalsom(areteActuelle.get_m_fin(), valsom);
        if (m_initValsom != m_finValsom)
        {

            connexite.push_back(areteActuelle);
            cmpt++;
            valsom[m_finValsom]=m_initValsom;
        }j++;
    }
    for (int i=0;i<nbresom-1;i++)
    {
        if (connexite[i].get_m_init() < connexite[i].get_m_fin())
        {
            std::cout << connexite[i].get_m_init() <<" " <<connexite[i].get_m_fin() << " "<< connexite[i].get_poids2()<< std::endl;
        }
        else
        {
            std::cout << connexite[i].get_m_fin()<<" " << connexite[i].get_m_init() << " " << connexite[i].get_poids2()<< std::endl;
        }
    }
    return connexite;
}



std::vector<std::vector<bool>>binaire(std::vector<Arete*> m_aretes)
{
    std::vector<std::vector<bool>>tabbin(pow(2,m_aretes.size()));
    std::vector<bool> inter;
    for (int i=0; i<m_aretes.size(); i++)
    {
        //tabbin[i].push_back(inter);
        for (int j=0; j<pow(2,m_aretes.size()); j++)
        {
            tabbin[j].push_back((j>>i)&1);

        }
    }
  /*  for (int k=0; k<pow(2,m_aretes.size()); ++k)
    {
        for (int l=0; l<(m_aretes.size()); ++l)
        {
            std::cout << tabbin[k][l] << " ";
        }
        std::cout<<std::endl;
    }*/
    return tabbin;
}



std::vector<std::vector<bool>> Selection1 (std::vector<std::vector<bool>>tab3,std::vector<Arete*> m_aretes,std::vector<Sommet*>m_sommets)
{

    int nbSom = m_sommets.size();
    std::vector<std::vector<bool>> tab4;
    for (size_t i=0; i<tab3.size(); ++i)
    {
        int nbArLigne=0;
        // std::cout<<"FAUR 1"<<std::endl;
        for (size_t j=0; j<tab3[i].size(); ++j)
        {
            // std::cout<<"FAUR 2"<<std::endl;
            if (tab3[i][j]==1)
            {
                nbArLigne=nbArLigne+1;
            }
            // std::cout<<" Probleme nbar"<<std::endl;

            }if (nbArLigne == (nbSom-1))
            {
                //std::cout<<"IF"<<std::endl;
                tab4.push_back (tab3[i]);
            }

        }
      for (int k=0; k<pow(2,m_aretes.size()); ++k)
      {
          for (int l=0; l<(m_aretes.size()); ++l)
          {
              std::cout << tab4[k][l] << " ";
          }
          std::cout<<std::endl;
      }
    return tab4;
}

std::vector<std::vector<bool>> Selection2 (std::vector<std::vector<bool>>tab4,std::vector<Arete*> m_aretes,std::vector<Sommet*>m_sommets)
{
    for (size_t i=0;i<tab4[i].size();++i)
    {
        for (size_t j=0;j<m_aretes.size();++j)
        {
            if (tab4[i][j]==1)
            {

            }
        }
    }
}
