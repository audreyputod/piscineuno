#include <iostream>
//#include "svgfile.h"
#include "arete.h"
#include "sommet.h"

#include <fstream>
#include <unordered_map>
#include "graphe.h"

int main()
{
     graphe g{"graphe_2.txt"};
     g.afficher();
}
