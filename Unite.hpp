#ifndef UNITE_H
#define UNITE_H

#include <iostream>
#include <string>
#include <sstream>
#include<vector>
#include "Affichage.hpp"
#include "stdafx.h"

using namespace std;

class Unite
{
    public:
        Unite(int, int, int, int, int, int);
        virtual ~Unite();

        int Getprix() { return m_prix; }
        void Setprix(int val) { m_prix = val; }
        int Getpos() { return m_pos; }
        void Setpos(int val) { m_pos = val; }
        int Getpv() { return m_pv; }
        void Setpv(int val) { m_pv = val; }
        int Getpa() { return m_pa; }
        void Setpa(int val) { m_pa = val; }
        int GetpoMin() { return m_poMin; }
        void SetpoMin(int val) { m_poMin = val; }
        int GetpoMax() { return m_poMax; }
        void SetpoMax(int val) { m_poMax = val; }
        bool isCampA() { return campA; }
        void SetcampA(bool val) { campA = val; }
        bool getOkAction1() { return okAction1; }
        void setOkAction1(bool val) { okAction1=val; }

        //methode susceptible d'etre redefinie par ses classes derives
        virtual bool isSuper () { return true; }
        virtual int monSkin() { return m_prix; }

        void moveU(bool droite, vector<Unite*>& tab);

        virtual bool peutAttaquer(Unite u);
        virtual bool peutAttaquerBase();
        virtual void attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv);
        void action2(vector<Unite*>& tab);//A voir si on met dans joueur ou dans Unite
        string toString() const;

    protected:
        int m_prix;
        int m_pos;
        int m_pv;
        int m_pa;
        int m_poMin;
        int m_poMax;
        bool campA;
        bool okAction1;
};

#endif // UNITE_H
