#ifndef STDAFX_H
#define STDAFX_H

#pragma once

#include <string>
using namespace std;

const int RESTART = 0;
const int MENU_PRINCIPAL = 5;
const int PLAY = 2;
const int HELP = 3;
const int ENTRER = 1;
const int MOVE = 6;

const int GOLD_TOUR = 8;
const int GOLD_INIT = 2;
const int MAX_TOUR = 20;
const int PV_BASE = 100;

const int MAX_Y = 42;
const int MAX_X = 140;

const int C_MENU_X = 64;
const int C_MENU_Y = 25;

const int BASE_X = 17;
const int BASE_Y = 26;

const int DEB_TERR_X = BASE_X+1;
const int DEB_TERR_Y = 25;
const int NB_CASES = 12;
const int SIZE_CASE = 9;

const int INFO_BASE_X = BASE_X-2;
const int INFO_BASE_Y = 28;
const int INFO_BASEB_X = BASE_X+10+(NB_CASES-2)*(SIZE_CASE-1);
const int INFO_BASEB_Y = 28;

const int DEB_QUEST_X = 31;
const int DEB_QUEST_Y = 33;
const int QUEST_L = 47;
const int QUEST_H = 5;
const int TAB = 4;

const int PRIX_F = 10;
const int PRIX_A = 12;
const int PRIX_C = 20;
const int H_MAX_U = 5;

//liste des question
const int TOUR_JOUEUR = 0;
const int BUY_UNIT = 1;

const int NB_INFO = 4;
const int TOUR_VALUE_X = MAX_X-15;
const int TOUR_VALUE_Y = 31;

const string K_UP = "z";
const string K_DOWN = "s";
const string K_LEFT = "q";
const string K_RIGHT = "d";

const string KEY_A = "a";
const string KEY_C = "c";
const string KEY_D = "d";
const string KEY_F = "f";
const string KEY_W = "w";
const string KEY_R = "r";
const string KEY_M = "m";
//const int KEY_A = 0x41;
//const int KEY_C = 0x43;
//const int KEY_D = 0x44;
//const int KEY_F = 0x46;
//const int KEY_Q = 0x51;
//const int KEY_R = 0x52;
//const int VK_RETURN = 0x0D;

#include <cstdio>
#include <iostream>
#include <stdlib.h>

#endif
