#ifndef JOUEUR_H
#define JOUEUR_H

#include "Base.hpp"
#include "Unite.hpp"
#include "Archer.hpp"
#include "Fantassin.hpp"
#include "Catapulte.hpp"
#include "Affichage.hpp"
#include "Terrain.hpp"
#include "stdafx.h"

class Joueur
{
    public:
        Joueur(Base& base);
        virtual ~Joueur();

        Base& Getbase() { return m_base; }
        void Setbase(Base val) { m_base = val; }

        void action1(Terrain &t);
        void action2(Terrain &t);
        void action3(Terrain &t);
        virtual void newUnite(Terrain &t) {cout<<"Erreur de definition du type de joueur"<<endl;}
        bool peutAcheter(Unite *u);
        bool peutAvancer(Unite &u);

    protected:
        Base &m_base;
};

#endif // JOUEUR_H
