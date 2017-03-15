
#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "stdafx.h"
#include "Unite.hpp"
#include "Affichage.hpp"
#include "Terrain.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"

using namespace std;

class Console
{
    public:
        Console();
        virtual ~Console();

        static void intiMap();
        static bool Move(int v, int m);

        static void update();
        static void updateUnites(vector<Unite*> tab);
        static void updateTerrain(Terrain &t, int tour, bool joueurA, int phase, bool modespec);
        static void UpdateInfoBase(Base &b, bool isA);
        static void updateQestion(bool modespec);

        static void clearZ(int x, int y, int dx, int dy);
        static void positionnerCuseur(int posx, int posy);

        static bool addUnite(Unite *u);
        static bool drawUnite(Unite *u, vector<string> v, int posX);
        static vector<string> selectSkin(int skin);
        static void drawInfoBulle(vector<char> &text, int posx, int posy);

        static void drawBox(char contour_l, char contour_h, char Fill, int l, int h, int posX, int posY);

        static void afficherQuestion(vector<string> blocQuestion);
        static void affQTourJoueur();
        static void affQAcheterUnite();
        static void infoPartie(int tour, int nbMob, bool joueurA, int phase);
        static bool choixJoueur(Terrain &t);
        static void modeSpectateur();

        static void clignoter(int nb_clign, unsigned int microseconds, int posx, int posy, string old, string new_);
        static void addGold();
        static void affTextBox(vector<string> me, int posx, int posy);

        static bool attendreAction(string key);
        static int deplacement(string key);

        static void lireFichier(string nomFichier, int posX, int posY);
        static void ecranAccueil();
        static void controlKey();
        static void menu();
        static void mode();
        static void clearMap();
        static void affTerrain();
        static void retourEcran();
        static void nettoyerConsole();
        static void /*int*/ pauseConsole();
        static string intToString(int x);
        static void centrerTexte(string s, int posy);
        static void afficherText(string Result, int posX, int posY);
};
extern char map[MAX_Y][MAX_X];
extern int x;
extern int y;

#endif // CONSOLE_H
