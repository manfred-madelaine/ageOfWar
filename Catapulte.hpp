#ifndef CATAPULTE_H
#define CATAPULTE_H

#include <iostream>
#include <string>
#include <sstream>

#include "Unite.hpp"

using namespace std;

class Catapulte : public Unite
{
    public:
        Catapulte();
        virtual ~Catapulte();

        virtual bool peutAttaquer(Unite u);
        virtual bool peutAttaquerBase();
        virtual void attaquer(Unite &u, vector<Unite*>& tabTerrain, vector<Unite*>& tabBase, int &sousBase, int &pv);


        string toString() const;


    protected:

    private:
        int m_zone;
};

#endif // CATAPULTE_H
