#include <fstream>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include "graphe.h"
#include "sommet.h"
#include "arete.h"


graphe::graphe(std::string graphe1){
    std::ifstream ifs{"cubetown.txt"};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + graphe1 );
    int ordre;
    ifs >> ordre;

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id_sommet;
    double x,y;
    ///lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id_sommet; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
         m_sommets.insert({id_sommet,new Sommet{id_sommet,x,y}});

    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_arete;
    float Init,fin;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>id_arete; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>Init; if(ifs.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs>>fin ; if(ifs.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");



   std::ifstream ifs2{"cubetown_weights_0.txt"};
      if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + graphe1 );
       if ( ifs2.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
        float poids;
        ifs2>>taille; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        //ifs2>>id_arete; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs2>>poids; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
         m_aretes.insert({id_arete,new Arete{id_arete,Init,fin,poids}});
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        //(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        //(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté

}
}

void graphe::afficher() const{

    Svgfile svgout;
    std::cout << "Graphe :" << std::endl << std::endl;
    std::cout << "  Ordre : " << m_sommets.size() << std::endl << std::endl;
    std::cout << "      Sommet : \n ";

    std::cout << "      Aretes : \n ";
    for (auto it : m_aretes)
    {
        svgout.addLine(m_sommets.find(it.second->get_m_init())->second->get_m_x(),m_sommets.find(it.second->get_m_init())->second->get_m_y(),m_sommets.find(it.second->get_m_fin())->second->get_m_x(),m_sommets.find(it.second->get_m_fin())->second->get_m_y(),"blue");
        //svgout.addText((m_sommets.find(it.second->get_m_init())->second->get_m_x())+ m_sommets.find(it.second->get_m_fin())->second->get_m_x())/2 ,(m_sommets.find(it.second->get_m_init())->second->get_m_y()+m_sommets.find(it.second->get_m_fin())->second->get_m_y())/2 ,m_poids,"black");
    }
    for (auto it : m_sommets)
    {
        it.second->afficherData(svgout);
    }
}

graphe::~graphe()
{

}


///à mettre dans le graphe.cpp
void graphe::tableau()
{
    int nbresom=m_sommets.size();
    int nbrear= m_aretes.size();
    //std::cin >>nbresom >>nbrear;

    std::vector<Arete*>tabArete;
    //Arete * tabArete = new Arete[nbrear];

    for (a: m_aretes)
    {
        //int s,d,w;
        //std::cin << s << d << w;
        tabArete.push_back(a.second);
    }
    kruskal(tabArete, nbresom,nbrear);
}



