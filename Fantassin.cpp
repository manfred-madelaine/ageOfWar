#include "Fantassin.hpp"

Fantassin::Fantassin(): Unite(10, 0, 10, 4, 1, 1), m_superSoldat(false)
{
    //ctor(10, 0, 10, 4, 1)
}

Fantassin::~Fantassin()
{
    //dtor
}

string Fantassin::toString() const
{
    stringstream ss;
    ss << "-- Fantassin:" << endl << Unite::toString();
    return ss.str();
}

void Fantassin::attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv){
    if(peutAttaquer(u)){
        u.Setpv(u.Getpv()-this->Getpa());
        if(u.Getpv()<=0){
            sousBase+=(u.Getprix()/2);
            if(u.Getprix()==PRIX_F){
                m_superSoldat=true;
            }
            //Suppression des unités.
            for(unsigned int i=0;i<tabTerrain.size();i++){
                if(u.Getpos()==tabTerrain[i]->Getpos()){
                    tabTerrain.erase(tabTerrain.begin() + i);

                }
            }
            for(unsigned int i=0;i<tabBase.size();i++){
                if(u.Getpos()==tabBase[i]->Getpos()){
                    tabBase.erase(tabBase.begin() + i);
                }
            }
        }
    }
    else if(this->peutAttaquerBase()){
        pv-=this->Getpa();
    }
}
