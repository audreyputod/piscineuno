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



   std::ifstream ifs{"cubetown_weights_0.txt"};
      if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + graphe1 );
       if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
        float poids;
        ifs>>poids; if(ifs.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
         m_aretes.insert({id_arete,new Arete{id_arete,Init,fin,poids}});
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        //(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        //(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté

}
}

void graphe::afficher() const{

    std::cout << "Graphe :" << std::endl << std::endl;
    std::cout << "  Ordre : " << m_sommets.size() << std::endl << std::endl;
  std::cout << "      Sommet : \n ";
    for (auto it : m_sommets)
    {

        it.second->afficherData();
        std::cout << "" <<std::endl;


    }
    std::cout << "      Aretes : \n ";
    for (auto it : m_aretes)
    {

        it.second->afficherData();
        std::cout << "" <<std::endl;
    }
}

graphe::~graphe()
{

}
