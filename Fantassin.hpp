#ifndef FANTASSIN_H
#define FANTASSIN_H

#include <iostream>
#include <string>
#include <sstream>

#include "Unite.hpp"

using namespace std;

class Fantassin : public Unite
{
    public:
        Fantassin();
        virtual ~Fantassin();
        void setSuper(bool v) {m_superSoldat = v; }

        string toString() const;

        virtual void attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv);

        //redefinition
        virtual bool isSuper () {return m_superSoldat; }
        virtual int monSkin() {
            if(m_superSoldat) return m_prix+1;
            else return m_prix;
        }

    protected:

    private:
        bool m_superSoldat;
};

#endif // FANTASSIN_H
