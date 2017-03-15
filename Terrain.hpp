#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
#include "Base.hpp"

using namespace std;

class Terrain
{
    public:
        Terrain(int nbCases);
        virtual ~Terrain();

        int GetnbCases() { return m_nbCases; }
        void SetnbCases(int val) { m_nbCases = val; }
        Base& GetbaseA() { return m_baseA; }
        void SetbaseA(Base val) { m_baseA = val; }
        Base& GetbaseB() { return m_baseB; }
        void SetbaseB(Base val) { m_baseB = val; }
        vector<Unite*>& gettab() {return tab;}
        Unite&  getUniteTab(int val) { return *tab[val]; }

        void initTerrain();

        void newTour();
        void trierTabCroissant();
        void afficherTab();
        void ajouterUnite(Unite *u) { tab.push_back(u); }
        void supprimerUnite(Unite *u);

    protected:

    private:
        int m_nbCases;
        Base m_baseA;
        Base m_baseB;
        vector<Unite*> tab;

};

#endif // TERRAIN_H
