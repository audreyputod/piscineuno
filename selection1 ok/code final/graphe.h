#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <vector>
#include <unordered_map>
#include "sommet.h"
#include "arete.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string);
        ~graphe();
        void afficher(std::vector<Arete> tab,std::vector<Arete> tab2) const;
        std::vector<Arete> tableau();
        std::vector<Arete> tableau2();
        std::vector<Arete*> get_m_aretes();
        std::vector<Sommet*> get_m_sommets();

        //Arete * kruskal(Arete *(graphe),int ordre,int s, int n);



    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::vector<Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arete*> m_aretes;
};

#endif // GRAPHE_H


