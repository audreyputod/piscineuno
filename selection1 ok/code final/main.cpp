#include <iostream>
//#include "svgfile.h"
#include "arete.h"
#include "sommet.h"
#include <algorithm>
#include <fstream>
#include "graphe.h"

int main()
{
    std::vector<Arete> tab;
    std::vector<Arete> tab2;
    // std::vector<Arete*>  graphe arete;
    graphe g{"graphe_2.txt"};
    std::vector<std::vector<bool>>tab3;
    std::vector<std::vector<bool>>AreteSelectBin;
    tab=g.tableau();
    tab2=g.tableau2();
    g.afficher(tab,tab2);
    tab3=binaire(g.get_m_aretes());
    std::cout<<"apres binaire"<<std::endl;
    AreteSelectBin=Selection1(tab3,g.get_m_aretes(),g.get_m_sommets());
    std::cout<<"apres selection1"<<std::endl;



    for (size_t i=0; i<AreteSelectBin.size(); ++i)
    {

        for (size_t j=0; j<g.get_m_aretes().size(); ++j)
        {

            std::cout<<AreteSelectBin[i][j]<<" ";
        }
        std::cout<<std::endl;
    }




}
