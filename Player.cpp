#include "Player.hpp"

Player::Player(Base& b) : Joueur(b)
{
    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::newUnite(Terrain &t){
    Affichage a = Affichage();
    a.acheter();
    //Il faut ajouter un choix rien acheter
    string rep("");
    string enumeration[3];
    enumeration[0] = "1";
    enumeration[1] = "2";
    enumeration[1] = "3";
    //Le while est bizarre et il faut faire un while dans les choix si c'est pas possible d'acheter
    while (a.repIncorrecte(rep, enumeration, 3))
    {
        if(rep != "")
            a.reponseIncorecte();
        a.mode();
        getline(cin,rep);
    }
    if (rep == enumeration[0])
    {
        Fantassin *f= new Fantassin();
        if(peutAcheter(f)){
            if(&m_base==&t.GetbaseB()){
                f->SetcampA(false);
                f->Setpos(NB_CASES);
            }
            m_base.ajouterUnite(f,t.gettab());
            //t.ajouterUnite(f);
        }

    }
    else if(rep == enumeration[1])
    {
        Archer *a = new Archer();
        if(peutAcheter(a)){
            if(&m_base==&t.GetbaseB()){
                a->SetcampA(false);
                a->Setpos(NB_CASES);
            }
            m_base.ajouterUnite(a,t.gettab());
            //t.ajouterUnite(a);
        }
    }
    else
    {
        Catapulte *c = new Catapulte();
        if(peutAcheter(c)){
            if(&m_base==&t.GetbaseB()){
                c->SetcampA(false);
                c->Setpos(NB_CASES);
            }
            m_base.ajouterUnite(c,t.gettab());
            //t.ajouterUnite(c);
        }
    }
}
