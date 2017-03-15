#include "Terrain.hpp"

Terrain::Terrain(int nbCases): m_nbCases(nbCases), m_baseA(GOLD_INIT), m_baseB(GOLD_INIT)
{

}

Terrain::~Terrain()
{
    //dtor
}


void Terrain::initTerrain()
{
    m_baseA.Setpv(PV_BASE);
    m_baseB.Setpv(PV_BASE);
    m_baseA.Setgold(GOLD_INIT*2);
    m_baseB.Setgold(GOLD_INIT*2);
    tab.clear();
}


void Terrain::newTour()
{
    m_baseA.addGold(GOLD_TOUR);
    m_baseB.addGold(GOLD_TOUR);
}

void Terrain::trierTabCroissant(){
    unsigned int ok=0;
    while(ok!=tab.size()){
        int maxVal=tab[ok]->Getpos();
        unsigned int max=ok;
        for(unsigned int i=ok+1;i<tab.size();i++){
            if(maxVal<tab[i]->Getpos()){
                maxVal=tab[i]->Getpos();
                max=i;
            }
        }
        if(max!=ok){
            Unite *tmp= tab[ok];
            tab[ok]=tab[max];
            tab[max]=tmp;

        }
        ok+=1;
    }
}

