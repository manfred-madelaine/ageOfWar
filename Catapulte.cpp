#include "Catapulte.hpp"

Catapulte::Catapulte(): Unite(20, 0, 12, 6, 2, 3), m_zone(2)
{
    //ctor
}

Catapulte::~Catapulte()
{
    //dtor
}

string Catapulte::toString() const
{
    stringstream ss;
    ss << "-- Catapulte:" << endl << Unite::toString();
    return ss.str();
}


bool Catapulte::peutAttaquer(Unite u){
    if( ((((m_pos+m_poMin<=u.Getpos()-1)&&(m_pos+m_poMax+1>=u.Getpos()-1)) || ((m_pos-m_poMin-1>=u.Getpos())&&(m_pos-m_poMax-2<=u.Getpos()))))&& (campA!=u.isCampA()) && (m_pv>0)){
        okAction1=true;
        return true;
    }
    else return false;
}

bool Catapulte::peutAttaquerBase(){
    if( ((m_pos+1==NB_CASES-1-m_poMax)&&this->campA)||((m_pos-2==0+m_poMax)&&!this->campA)){
        okAction1=true;
        return true;
    }
    else return false;
}

void Catapulte::attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv){
    if(peutAttaquer(u)){
        if((m_pos+m_poMin==u.Getpos()-1)||(m_pos+m_poMax==u.Getpos()-1)){
            u.Setpv(u.Getpv()-this->Getpa());
            if(u.Getpv()<=0){
                sousBase+=(u.Getprix()/2);
                //Suppression des unit�s.
                for(unsigned int i=0;i<tabTerrain.size();i++){
                    if(u.Getpos()==tabTerrain[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);
                    }
                }
                for(unsigned int i=0;i<tabBase.size();i++){
                    if(u.Getpos()==tabBase[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabBase[i]->Getpv()<<endl;
                        tabBase.erase(tabBase.begin() + i);
                    }
                }
            }

            for(unsigned int i=0;i<tabTerrain.size();i++){
                if(u.Getpos()==tabTerrain[i]->Getpos()){
                    tabTerrain[i]->Setpv(tabTerrain[i]->Getpv()-this->Getpa());

                    if(tabTerrain[i]->Getpv()<=0){
                        sousBase+=(tabTerrain[i]->Getprix()/2);
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);

                        for(unsigned int j=0;j<tabBase.size();j++){
                            if(tabTerrain[i]->Getpos()==tabBase[j]->Getpos()){
                                cout<<"Unite supprimer : "<<tabBase[j]->Getpv()<<endl;
                                tabBase.erase(tabBase.begin() + j);
                            }
                        }
                    }
                }
            }
        }



        else if(/*(m_pos+m_poMax==u.Getpos())||*/(m_pos+m_poMax+1==u.Getpos()-1)){
            u.Setpv(u.Getpv()-this->Getpa());
            if(u.Getpv()<=0){
                sousBase+=(u.Getprix()/2);
                //Suppression des unit�s.
                for(unsigned int i=0;i<tabTerrain.size();i++){
                    if(u.Getpos()==tabTerrain[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);
                    }
                }
                for(unsigned int i=0;i<tabBase.size();i++){
                    if(u.Getpos()==tabBase[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabBase[i]->Getpv()<<endl;
                        tabBase.erase(tabBase.begin() + i);
                    }
                }
            }

            for(unsigned int i=0;i<tabTerrain.size();i++){
                if(u.Getpos()-2==tabTerrain[i]->Getpos()){
                    tabTerrain[i]->Setpv(tabTerrain[i]->Getpv()-this->Getpa());

                    if(tabTerrain[i]->Getpv()<=0){
                        sousBase+=(tabTerrain[i]->Getprix()/2);
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);

                        for(unsigned int j=0;j<tabBase.size();j++){
                            if(tabTerrain[i]->Getpos()==tabBase[j]->Getpos()){
                                cout<<"Unite supprimer : "<<tabBase[j]->Getpv()<<endl;
                                tabBase.erase(tabBase.begin() + j);
                            }
                        }
                    }
                }
            }
        }


        if((m_pos-m_poMin-1==u.Getpos())||(m_pos-m_poMax-1==u.Getpos())){
            u.Setpv(u.Getpv()-this->Getpa());
            if(u.Getpv()<=0){
                sousBase+=(u.Getprix()/2);
                //Suppression des unit�s.
                for(unsigned int i=0;i<tabTerrain.size();i++){
                    if(u.Getpos()==tabTerrain[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);
                    }
                }
                for(unsigned int i=0;i<tabBase.size();i++){
                    if(u.Getpos()==tabBase[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabBase[i]->Getpv()<<endl;
                        tabBase.erase(tabBase.begin() + i);
                    }
                }
            }

            for(unsigned int i=0;i<tabTerrain.size();i++){
                if(u.Getpos()-1==tabTerrain[i]->Getpos()){
                    tabTerrain[i]->Setpv(tabTerrain[i]->Getpv()-this->Getpa());

                    if(tabTerrain[i]->Getpv()<=0){
                        sousBase+=(tabTerrain[i]->Getprix()/2);
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);

                        for(unsigned int j=0;j<tabBase.size();j++){
                            if(tabTerrain[i]->Getpos()==tabBase[j]->Getpos()){
                                cout<<"Unite supprimer : "<<tabBase[j]->Getpv()<<endl;
                                tabBase.erase(tabBase.begin() + j);
                            }
                        }
                    }
                }
            }
        }



        else if(/*(m_pos+m_poMax==u.Getpos())||*/(m_pos-m_poMax-2==u.Getpos())){
            u.Setpv(u.Getpv()-this->Getpa());
            if(u.Getpv()<=0){
                sousBase+=(u.Getprix()/2);
                //Suppression des unit�s.
                for(unsigned int i=0;i<tabTerrain.size();i++){
                    if(u.Getpos()==tabTerrain[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);
                    }
                }
                for(unsigned int i=0;i<tabBase.size();i++){
                    if(u.Getpos()==tabBase[i]->Getpos()){
                        cout<<"Unite supprimer : "<<tabBase[i]->Getpv()<<endl;
                        tabBase.erase(tabBase.begin() + i);
                    }
                }
            }

            for(unsigned int i=0;i<tabTerrain.size();i++){
                if(u.Getpos()+1==tabTerrain[i]->Getpos()){
                    tabTerrain[i]->Setpv(tabTerrain[i]->Getpv()-this->Getpa());

                    if(tabTerrain[i]->Getpv()<=0){
                        sousBase+=(tabTerrain[i]->Getprix()/2);
                        cout<<"Unite supprimer : "<<tabTerrain[i]->Getpv()<<endl;
                        tabTerrain.erase(tabTerrain.begin() + i);

                        for(unsigned int j=0;j<tabBase.size();j++){
                            if(tabTerrain[i]->Getpos()==tabBase[j]->Getpos()){
                                cout<<"Unite supprimer : "<<tabBase[j]->Getpv()<<endl;
                                tabBase.erase(tabBase.begin() + j);
                            }
                        }
                    }
                }
            }
        }

    }
    else if(this->peutAttaquerBase()){
        pv-=this->Getpa();
    }
}
