#ifndef PLAYER_H
#define PLAYER_H

#include "Joueur.hpp"


class Player : public Joueur
{
    public:
        Player(Base& b);
        virtual ~Player();
        virtual void newUnite(Terrain &t);

    protected:

    private:
};

#endif // PLAYER_H
