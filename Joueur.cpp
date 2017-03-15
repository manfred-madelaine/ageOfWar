#include "Joueur.hpp"

Joueur::Joueur(Base& b) : m_base(b)
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}


void Joueur::action1(Terrain &t)
{
    Affichage::phase1();
    for(unsigned int i=0;i<m_base.getTab().size();i++){
            for(unsigned int j=0;j<t.gettab().size();j++){
                if(!m_base.getUniteTab(i).getOkAction1()){
                    if(m_base.getUniteTab(i).isCampA()){
                        m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseB().getTab(),m_base.Getgold(),t.GetbaseB().Getpv());
                    }
                    else {
                        m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseA().getTab(),m_base.Getgold(),t.GetbaseA().Getpv());
                    }
                }
            }
    }

}

void Joueur::action2(Terrain &t)
{
    Affichage::phase2();
    for(unsigned int i=0;i<m_base.getTab().size();i++){
        if(m_base.getUniteTab(i).Getprix()!=PRIX_C){
            m_base.getUniteTab(i).action2(t.gettab());
        }
    }
}

bool Joueur::peutAvancer(Unite &u)
{
    for(unsigned int i=0;i<m_base.getTab().size();i++){
        if(m_base.getUniteTab(i).isCampA() && u.Getpos()+1 == m_base.getUniteTab(i).Getpos() ){
            return false;
        }
        else if(!m_base.getUniteTab(i).isCampA() && u.Getpos() -1 == m_base.getUniteTab(i).Getpos() ){
            return false;
        }
    }
    return true;
}

void Joueur::action3(Terrain &t)
{
    Affichage::phase3();
    for(unsigned int i=0;i<m_base.getTab().size();i++){
                //Si c'est un super-soldat
            if(m_base.getUniteTab(i).Getprix()==PRIX_F){
                if(m_base.getUniteTab(i).isSuper()){
                    for(unsigned int j=0;j<t.gettab().size();j++){
                        if(!m_base.getUniteTab(i).getOkAction1()){
                            if(m_base.getUniteTab(i).isCampA()){
                                m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseB().getTab(),m_base.Getgold(),t.GetbaseB().Getpv());
                            }
                            else m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseA().getTab(),m_base.Getgold(),t.GetbaseA().Getpv());
                        }
                    }
                }
                //Sinon si c'est un fantassin qui n'as pas jouer au 1er tour
                else if(!m_base.getUniteTab(i).getOkAction1()){
                    for(unsigned int j=0;j<t.gettab().size();j++){
                        if(!m_base.getUniteTab(i).getOkAction1()){
                             if(m_base.getUniteTab(i).isCampA()){
                                m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseB().getTab(),m_base.Getgold(),t.GetbaseB().Getpv());
                            }
                            else m_base.getUniteTab(i).attaquer(t.getUniteTab(j), t.gettab(), t.GetbaseA().getTab(),m_base.Getgold(),t.GetbaseA().Getpv());
                        }
                    }
                }
            }
            //Si cest une catapulte qui nas pas jouer au premier tour
            else if((m_base.getUniteTab(i).Getprix()==PRIX_C)&& (!m_base.getUniteTab(i).getOkAction1())){
                m_base.getUniteTab(i).action2(t.gettab());
            }

    }
}

bool Joueur::peutAcheter(Unite *u)
{
    if(u->Getprix() > m_base.Getgold()){
        return false;
    }
    return true;
}
