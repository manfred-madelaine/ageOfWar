#include "Base.hpp"

Base::Base(int gold): m_pv(20), m_gold(gold)
{
    //ctor
}

Base::~Base()
{
    //dtor
}

void Base::acheter()
{

}

void Base::addGold(int gold)
{
    m_gold += gold;
}

void Base::removeGold(int gold)
{
    m_gold -= gold;
}

void Base::ajouterUnite(Unite *u, vector<Unite*> &tabTerrain)
{
    tab.push_back(u);
    m_gold -= u->Getprix();
    tabTerrain.push_back(tab[tab.size()-1]);
}

void Base::supprimerUnite(Unite u)
{
    //Chercher comment faire un find
    //tab.erase(find(tab.begin(),tab.end(),u));
}

void Base::afficherTab()
{
    for(unsigned int i=0;i<tab.size();i++){
        cout<<tab[i]->toString()<<endl;
    }
}

void Base::trierTabCroissant(){
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
