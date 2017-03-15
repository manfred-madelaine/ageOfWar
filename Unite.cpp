#include "Unite.hpp"

Unite::Unite(int prix, int pos, int pv, int pa, int poMin, int poMax): m_prix(prix), m_pos(pos), m_pv(pv), m_pa(pa), m_poMin(poMin), m_poMax(poMax)
{
    campA=true;
    okAction1=false;
}

Unite::~Unite()
{
    //dtor
}

string Unite::toString() const
{
    stringstream ss;
    ss << "PX: " << m_prix << "\tPOS: " << m_pos << "\nPV: " << m_pv << "\tPA: " << m_pa << "\tPOMIN: " << m_poMin<< "\tPOMAX: " << m_poMax;
    return ss.str();
}

bool Unite::peutAttaquer(Unite u){
    if( (((m_pos+m_poMin<=u.Getpos()-1)&&(m_pos+m_poMax>=u.Getpos()-1)) || ((m_pos-m_poMin-1>=u.Getpos())&&(m_pos-m_poMax-1<=u.Getpos())))&& (campA!=u.isCampA())){
        okAction1=true;
        return true;
    }
    else return false;
}

void Unite::action2(vector<Unite*>& tab)
{
        if(campA)
            moveU(true,tab);
        else
            moveU(false,tab);
}

void Unite::moveU(bool droite, vector<Unite*> &tab)
{
    //on va vers la droite
    bool caseSuivanteLibre=true;
    for(unsigned int i=0;i<tab.size();i++){
        if(campA){
            if(tab[i]->isCampA()){
                if(tab[i]->Getpos()==m_pos+1){
                    caseSuivanteLibre=false;
                }
            }
            else{
                if(tab[i]->Getpos()-1==m_pos+1){
                    caseSuivanteLibre=false;
                }
            }

        }
        else {
            if(tab[i]->isCampA()){
                if(tab[i]->Getpos()==m_pos-2){
                    caseSuivanteLibre=false;
                }
            }
            else{
                if(tab[i]->Getpos()-1==m_pos-2){
                    caseSuivanteLibre=false;
                }
            }
        }
    }

    if(caseSuivanteLibre){
        if(droite&&(m_pos+m_poMax<NB_CASES-1))
        {
            m_pos++;
        }
        else if(!droite &&(m_pos-1-m_poMax>0))
        {
            m_pos--;
        }
    }

}

bool Unite::peutAttaquerBase(){
    if( ((m_pos==NB_CASES-1-m_poMax)&&this->campA)||((m_pos-1==0+m_poMax)&&!this->campA)){
        okAction1=true;
        return true;
    }
    else return false;
}

void Unite::attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv){

    if(this->peutAttaquer(u)){
        u.Setpv(u.Getpv()-this->Getpa());
        if(u.Getpv()<=0){
            sousBase+=(u.Getprix()/2);
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
