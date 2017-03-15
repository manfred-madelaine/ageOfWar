#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Affichage
{
    public:
        Affichage();
        virtual ~Affichage();

        static void mode();
        static void playerVSia();
        static void iaVSia();
        static void camp();
        static void campX(string nomCamp);
        static void reponseIncorecte();
        static void toucheIncorecte();
        static void moveIncorecte();
        static bool repIncorrecte(string rep, string enumeration[], int l);
        static void fonctIndisponible();

        static void tour(int tour);
        static void phase1();
        static void phase2();
        static void phase3();
        static void acheter();
        static void unite(string nom, int p);
        static void goldsBase(int gold);

        static void vainceur();
        static void pasDeVainceur();
        static void vainqueur(bool campA);

    protected:

    private:
};

#endif // AFFICHAGE_H
