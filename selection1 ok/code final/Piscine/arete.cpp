#include "arete.h"
#include <iostream>
#include<unordered_map>
#include<unordered_set>
Arete::Arete(int id_arete,int x , int y, float poids):  m_id_arete {id_arete}, m_x {x}, m_y {y}, m_poids {poids}

{
}

void Arete::afficherData() {
    std::cout<<"    "<<m_id_arete<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<< "poids" << m_poids <<std::endl;
 }
