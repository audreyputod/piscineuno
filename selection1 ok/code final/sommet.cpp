#include "sommet.h"
#include <iostream>
#include<unordered_map>
#include<unordered_set>
#include "svgfile.h"

Sommet::Sommet(int id_sommet,double x,double y):m_id_sommet{id_sommet},m_x{x},m_y{y}
{
}

int Sommet::get_m_x()
{
    return m_x;
}

int Sommet::get_m_y()
{
    return m_y;
}
int Sommet::get_m_id_sommet()
{
    return m_id_sommet;
}


 void Sommet::afficherData(Svgfile &svg) const{
     //std::cout<<"    "<<m_id_sommet<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;

     svg.addCircle(m_x,m_y,20,5,"red");
     svg.addText (m_x-5,m_y+5,m_id_sommet,"black");
 }
Sommet::Sommet()
    {
        m_id_sommet = 0;
        m_x=0;
        m_y=0;
    }
