#include <fstream>
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include "graphe.h"
#include "sommet.h"
#include "arete.h"
#include <vector>


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
        Sommet* S = new Sommet(id_sommet,x,y);
         m_sommets.push_back(S);

    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_arete;
    float Init,fin;
    std::ifstream ifs2{"cubetown_weights_0.txt"};
      if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + graphe1 );
       if ( ifs2.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
        float poids1,poids2;
        int nbpoids;
        ifs2>>taille; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs2>>nbpoids;if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");

    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>id_arete; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>Init; if(ifs.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs>>fin ; if(ifs.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs2>>id_arete; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs2>>poids1; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");
        ifs2>>poids2; if(ifs2.fail()) throw std::runtime_error ("Probleme lecture arete sommet 1");

         Arete*A = new Arete(id_arete,Init,fin,poids1,poids2);
         m_aretes.push_back(A);

        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        //(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        //(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
    }

}


std::vector<Arete*> graphe:: get_m_aretes()
{
    return m_aretes;
}
std::vector<Sommet*> graphe:: get_m_sommets()
{
    return m_sommets;
}


void graphe::afficher(std::vector<Arete> tab,std::vector<Arete> tab2) const{

    Svgfile svgout;
    double x,y;
    double x_init,y_init,x_fin,y_fin,id_init,id_fin,id_arete,id_som;
    double mil_areteX,mil_areteY;
    double p1,p2;
    double xGraph=50;
    double yGraph=1000;
    double xGraph1=500;
    double yGraph1=500;


for (auto it = m_aretes.begin();it!=m_aretes.end();++it)
    {
        id_arete=(*it)->get_m_id_arete();
        id_init=(*it)->get_m_init();
        id_fin=(*it)->get_m_fin();
        x_init=m_sommets[id_init]->get_m_x();
        y_init=m_sommets[id_init]->get_m_y();
        x_fin=m_sommets[id_fin]->get_m_x();
        y_fin=m_sommets[id_fin]->get_m_y();
        p1=(*it)->get_poids1();
        mil_areteX=(x_init+x_fin)/2;
        mil_areteY=(y_init+y_fin)/2;
        svgout.addLine(x_init,y_init,x_fin,y_fin,"blue");
        svgout.addText(mil_areteX,mil_areteY,p1,"black");
    }


for (int i=0;i<tab.size();++i)
    {
        id_arete=(tab[i]).get_m_id_arete();
        id_init=(tab[i]).get_m_init();
        id_fin=(tab[i]).get_m_fin();
        x_init=m_sommets[id_init]->get_m_x();
        y_init=m_sommets[id_init]->get_m_y();
        x_fin=m_sommets[id_fin]->get_m_x();
        y_fin=m_sommets[id_fin]->get_m_y();
        p1=(tab[i]).get_poids1();
        mil_areteX=(x_init+x_fin)/2;
        mil_areteY=(y_init+y_fin)/2;
        svgout.addLine(x_init,y_init,x_fin,y_fin,"pink");


    }

    for (auto it = m_sommets.begin();it!=m_sommets.end();++it)
    {
        x=(*it)->get_m_x();
        y=(*it)->get_m_y();
        id_som=(*it)->get_m_id_sommet();

        svgout.addCircle(x,y,20,10,"red");
        svgout.addText(x-3,y+3,id_som,"black");

    }

for (auto it = m_aretes.begin();it!=m_aretes.end();++it)
    {
        id_arete=(*it)->get_m_id_arete();
        id_init=(*it)->get_m_init();
        id_fin=(*it)->get_m_fin();
        x_init=m_sommets[id_init]->get_m_x();
        y_init=m_sommets[id_init]->get_m_y();
        x_fin=m_sommets[id_fin]->get_m_x();
        y_fin=m_sommets[id_fin]->get_m_y();
        p2=(*it)->get_poids2();
        mil_areteX=(x_init+x_fin)/2;
        mil_areteY=(y_init+y_fin)/2;
        svgout.addLine(x_init+400,y_init,x_fin+400,y_fin,"blue");
        svgout.addText(mil_areteX+400,mil_areteY,p2,"black");
    }


for (int i=0;i<tab2.size();++i)
    {
        id_arete=(tab2[i]).get_m_id_arete();
        id_init=(tab2[i]).get_m_init();
        id_fin=(tab2[i]).get_m_fin();
        x_init=m_sommets[id_init]->get_m_x();
        y_init=m_sommets[id_init]->get_m_y();
        x_fin=m_sommets[id_fin]->get_m_x();
        y_fin=m_sommets[id_fin]->get_m_y();
        p2=(tab2[i]).get_poids2();
        mil_areteX=(x_init+x_fin)/2;
        mil_areteY=(y_init+y_fin)/2;
        svgout.addLine(x_init+400,y_init,x_fin+400,y_fin,"pink");


    }

    for (auto it = m_sommets.begin();it!=m_sommets.end();++it)
    {
        x=(*it)->get_m_x();
        y=(*it)->get_m_y();
        id_som=(*it)->get_m_id_sommet();

        svgout.addCircle(x+400,y,20,10,"red");
        svgout.addText(x+397,y+3,id_som,"black");

    }
    svgout.addLine(xGraph,yGraph,xGraph,yGraph1,"black");
     svgout.addLine(xGraph,yGraph,xGraph1,yGraph,"black");
     svgout.addText(xGraph,yGraph1-10,"Cout 2","black");
     svgout.addText(xGraph1+30,yGraph,"Cout 1","black");
}

graphe::~graphe()
{

}


///à mettre dans le graphe.cpp
std::vector<Arete> graphe::tableau()
{
    std::vector<Arete*> tabArete;
    std::vector <Arete>tab;

    int nbresom=m_sommets.size();
    int nbrear= m_aretes.size();

    //std::cin >>nbresom >>nbrear;


    //Arete * tabArete = new Arete[nbrear];

    for (int a=0; a<m_aretes.size();++a)
    {
        //int s,d,w;
        //std::cin << s << d << w;
        tabArete.push_back(m_aretes[a]);
    }
    tab=kruskal(tabArete, nbresom,nbrear);
return tab;

}



std::vector<Arete> graphe::tableau2()
{
    std::vector<Arete*> tabArete;
    std::vector <Arete>tab;

    int nbresom=m_sommets.size();
    int nbrear= m_aretes.size();

    //std::cin >>nbresom >>nbrear;


    //Arete * tabArete = new Arete[nbrear];

    for (int a=0; a<m_aretes.size();++a)
    {
        //int s,d,w;
        //std::cin << s << d << w;
        tabArete.push_back(m_aretes[a]);
    }
    tab=kruskal2(tabArete, nbresom,nbrear);
return tab;

}



