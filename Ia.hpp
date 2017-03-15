#ifndef IA_H
#define IA_H

#include "Joueur.hpp"
#include "stdafx.h"



class Ia : public Joueur
{
    public:
        Ia(Base& b);
        virtual ~Ia();
        virtual void newUnite(Terrain &t);

    protected:

    private:
};

#endif // IA_H
