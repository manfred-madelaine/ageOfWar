#ifndef PARTIE_H
#define PARTIE_H

//#include <cstdlib.hpp>

#include "Terrain.hpp"
#include "Joueur.hpp"

#include "Unite.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Console.hpp"
#include "stdafx.h"
#include "Joueur.hpp"
#include "Player.hpp"
#include "Ia.hpp"

class Partie
{
    public:
        Partie();
        virtual ~Partie();

        Joueur* GetjoueurA() { return m_joueurA; }
        void SetjoueurA(Joueur* val) { m_joueurA = val; }
        Joueur* GetjoueurB() { return m_joueurB; }
        void SetjoueurB(Joueur* val) { m_joueurB = val; }
        Terrain& Getterrain() { return m_terrain; }
        void Setterrain(Terrain& val) { m_terrain = val; }
        int Gettour() { return m_tour; }
        void setTour(int val) {m_tour=val;}

        bool play();
        bool init();
        void update();
        bool attendreAction(/*int choix*/);
        void modeSpect();

        bool nextTour();
        void nextJoueur();
        void nextPhase();

        bool choixUser(int choix);

        void menu();
        void mode();
        bool boucle();
        bool endGame();
        bool tourJoueur(Joueur& j);

    protected:

    private:
        Terrain m_terrain;

        Joueur *m_joueurA;
        Joueur *m_joueurB;
        int m_tour;
        int phase;
        bool isA;
        bool modeSpec;
};

#endif // PARTIE_H
