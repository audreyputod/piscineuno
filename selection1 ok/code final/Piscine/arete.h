#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Arete
{
public :
    Arete(int,int,int,float);

   // Arete::dessiner ()
  void afficherData() ;

protected :
    float m_poids;
    int m_x,m_y,m_id_arete;

};
#endif // ARETE_H_INCLUDED




