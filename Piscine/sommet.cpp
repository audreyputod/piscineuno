#include "sommet.h"
#include <iostream>
#include<unordered_map>
#include<unordered_set>

Sommet::Sommet(int id_sommet,double x,double y):m_id_sommet{id_sommet},m_x{x},m_y{y}
{
}

 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id_sommet<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }
Sommet::Sommet()
    {
        m_id_sommet = 0;
        m_x=0;
        m_y=0;
    }
