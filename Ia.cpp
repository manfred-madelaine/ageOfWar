#include "Ia.hpp"

Ia::Ia(Base& b) : Joueur(b)
{
    //ctor
}

Ia::~Ia()
{
    //dtor
}

void Ia::newUnite(Terrain &t){
    bool posLibre=true;
    for(unsigned int i=0;i<m_base.getTab().size();i++){
        if((m_base.getUniteTab(i).Getpos()==0&&m_base.getUniteTab(i).isCampA())||
            (m_base.getUniteTab(i).Getpos()==13&&!m_base.getUniteTab(i).isCampA()))
        {
            posLibre=false;
        }
    }
    if(m_base.Getgold()>=20&&posLibre){
        Catapulte *c = new Catapulte();
        if(&m_base==&t.GetbaseB()){
            c->SetcampA(false);
            c->Setpos(NB_CASES);
        }
        m_base.ajouterUnite(c,t.gettab());
    }
    else if(m_base.Getgold()>=12&&posLibre){
        Archer *a= new Archer();
        if(&m_base==&t.GetbaseB()){
            a->SetcampA(false);
            a->Setpos(NB_CASES);
        }
        m_base.ajouterUnite(a,t.gettab());
    }
    else if(m_base.Getgold()>=10&&posLibre){
        Fantassin *f = new Fantassin();
        if(&m_base==&t.GetbaseB()){
            f->SetcampA(false);
            f->Setpos(NB_CASES);
        }
        m_base.ajouterUnite(f,t.gettab());
    }
    else cout<<"Vous n'avez pas assez de sous"<<endl;
}
