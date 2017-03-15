#ifndef BASE_H
#define BASE_H

#include <iostream>
#include<vector>
#include "Unite.hpp"
#include "stdafx.h"

using namespace std;

class Base
{
    public:
        Base(int gold);
        virtual ~Base();

        int Getpv() { return m_pv; }
        void Setpv(int val) { m_pv = val; }
        int Getgold() { return m_gold; }
        void Setgold(int val) { m_gold = val; }
        vector<Unite*>& getTab() { return tab; }
        Unite& getUniteTab(int val) { return *tab[val]; }

        void acheter();
        void addGold(int gold);
        void removeGold(int gold);
        void trierTabCroissant();
        void afficherTab();
        void ajouterUnite(Unite *u, vector<Unite*> &tab);
        void supprimerUnite(Unite u);


    protected:

    private:
        int m_pv;
        int m_gold;
        vector<Unite*> tab;
};

#endif // BASE_H
