#include "Console.hpp"

char map[MAX_Y][MAX_X];

//coordonnees du curseur
int x = DEB_QUEST_X+1;
int y = DEB_QUEST_Y+1;
int question;

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}


bool Console::Move (int v, int h)
{
    int y2 = y + v;
//    int x2 = x + h;

//    deplacement vertical uniquement
    if (map[y2][x+6] != ' ')
    {
        afficherText("  ", x, y);
        y+= v;
        afficherText("->", x, y);
/*        update();
*/    }
    else
        return false;
//
//    if (map[y][x2] != '#' && map[y][x2+1] != '#')
//    {
//        afficherText("  ", x, y);
//        x+= h;
//        afficherText("->", x, y);
//        update();
//    }
//    else
//        return false;
//    if (map[y2][x] != '#'&& map[y2][x+1] != '#')
//    {
//        afficherText("  ", x, y);
//        y+= v;
//        afficherText("->", x, y);
//        update();
//    }
//    else
//        return false;
    return true;
}

void Console::intiMap()
{
    clearMap();
    lireFichier("banderole.txt", 17, 1);
    //base A
    lireFichier("base.txt", BASE_X-11, BASE_Y-8);
    afficherText("baseA( )\npv:\ngold:", BASE_X-9, BASE_Y+1);

    //cases du terrain
    for(int i=0; i<NB_CASES-2;i++)
    {
        afficherText("I_______I",BASE_X+i*(SIZE_CASE-1), BASE_Y);
    }
    //base B
    lireFichier("base.txt", BASE_X+1+(NB_CASES-2)*(SIZE_CASE-1), BASE_Y-8);
    afficherText("baseB( )\npv:\ngold:", BASE_X+3+(NB_CASES-2)*(SIZE_CASE-1), BASE_Y+1);
    //info de la partie
    infoPartie(0, 0, true, 0);
    //question
    updateQestion(true);

    Move(0,0);
}

void Console::nettoyerConsole()
{
    //faire attention à la portabilite du code
    //system("cls");//windows
//    system("clear");//linux
}

void Console::pauseConsole()
{
    //faire attention à la portabilite du code
//    system("pause>nul");
    string rep("");
    getline(cin,rep);
//    getchar();
}


void Console::ecranAccueil()
{
    drawBox('#', '#', ' ', MAX_X-1, MAX_Y, 0, 0);
    lireFichier("ageofwar.txt", MAX_X/2-30, 3);
    retourEcran();

    string creators = "Creators: Manfred   &   Alex";
    int posx = MAX_X/2 - creators.size()/2;
    clignoter(2, 500, posx, MAX_Y-3, creators, " ");
}

void Console::lireFichier(string nomFichier, int posX, int posY)
{
    vector<string> map3;
    ifstream fichier;
    fichier.open(nomFichier.c_str(), ifstream::in);
    if(fichier.is_open())  // si l'ouverture a réussi
    {
        string uneLigne;
        while( getline(fichier, uneLigne))
        {
            map3.push_back(uneLigne);
        }
        fichier.close();  // on ferme le fichier
    }

    for (unsigned int i=0; i<map3.size(); i++)
    {
        afficherText(map3[i], posX, posY+i);
    }
}

void Console::menu()
{
    clearMap();
    vector<string> me;
    me.push_back("Menu:");
    me.push_back("_______");
    me.push_back(" ");
    me.push_back("Joueur");
    me.push_back("Aide");
    me.push_back("Quitter");

    affTextBox(me, MAX_X/2, MAX_Y/2);

    lireFichier("banderole.txt", MAX_X/2-30, 1);
    positionnerCuseur(MAX_X/2, 25);
}

void Console::affTextBox(vector<string> me, int posx, int posy)
{
    int pos=0;
    int maxY=me.size()+TAB;
    for (unsigned int i=0; i<me.size(); i++)
    {
        if(me[i].size() > me[pos].size())
            pos = i;
    }
    int maxX = me[pos].size()+2*TAB;

    drawBox('~', '|', ' ', maxX, maxY, posx-maxX/2, posy+TAB-maxY/2);

    for(unsigned int i=0; i<me.size(); i++)
    {
        afficherText(me[i], posx - me[i].size()/2, posy+TAB+i - me.size()/2);
    }
}

void Console::clearMap()
{
    clearZ(1, MAX_Y-2,MAX_X-3, MAX_Y-2);
}

void Console::positionnerCuseur(int posx, int posy)
{
    while(map[posy][posx-1] != ' ')
    {
        posx--;
    }
    x=posx-3;
    y=posy;
    Move(0,0);
}

void Console::affTerrain()
{
    ofstream fichier("save.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        for(int i = 0; i< MAX_Y; i++)
        {
            fichier << map[i]<<endl;
        }
        fichier.close();  // on referme le fichier
    }
    else
        cerr << "Erreur à l'ouverture !" << endl;

    for(int i = 0; i< MAX_Y; i++)
    {
        cout << map[i] << endl;
    }
}

void Console::update()
{
    //on actualise l'affichage des coordonnees du pointeur
    string Result;

    int psx = 130;
    int psy = 25;
    Result = "x="+ intToString(x);
    clearZ(psx, psy, 7, 1);
    afficherText(Result, psx, psy);

    Result =  "y="+ intToString(y);
    clearZ(psx, psy+1, 7, 1);
    afficherText(Result, psx, psy+1);
}

void Console::updateTerrain(Terrain &t, int tour, bool joueurA, int phase, bool modeSpec)
{
    infoPartie(tour, t.gettab().size(), joueurA, phase);

    UpdateInfoBase(t.GetbaseA(), true);
    UpdateInfoBase(t.GetbaseB(), false);
    updateUnites(t.gettab());
    updateQestion(modeSpec);

    retourEcran();
}

void Console::retourEcran()
{
    nettoyerConsole();
    affTerrain();
    pauseConsole();
}

void Console::updateUnites(vector<Unite*> tab)
{
    int dx = (NB_CASES-2)*(SIZE_CASE-1);
    int dy = H_MAX_U+1;

    //nettoie du debut gauche du terrain, ord du toit du terrain, longueur du terrain, hauteur du terrain)
    clearZ(DEB_TERR_X, DEB_TERR_Y, dx, dy);
    //nettoie les infos bulles
    clearZ(DEB_TERR_X, DEB_TERR_Y+3,dx, 2);
    //clear new unite base A & B
    clearZ(INFO_BASE_X-1, INFO_BASE_Y-1, 1, 1);
    clearZ(INFO_BASEB_X-1, INFO_BASEB_Y-1, 1, 1);
    for(unsigned int i=0; i<tab.size(); i++)
    {
        addUnite(tab[i]);
    }
}

void Console::updateQestion(bool modeSpec)
{
    if(modeSpec)
        modeSpectateur();

}

void Console::UpdateInfoBase(Base &b, bool isA)
{
    string s = intToString(b.Getpv());
    s += "\n" + intToString(b.Getgold());
    int posx = INFO_BASE_X;

    if(!isA)
        posx =  INFO_BASEB_X;

    clearZ(posx, INFO_BASE_Y+1, 3, 2);
    afficherText(s, posx, INFO_BASE_Y);
}

/** \brief nettoie une zone rectangulaire
 *
 * \param x: abscisse du coin inferieur gauche de la zone
 * \param y: ordonnee du coin inferieur gauche de la zone
 * \param dx: longueur de la zone
 * \param dy: hauteur de la zone
 * \return
 *
 */
void Console::clearZ(int x_, int y_, int dx, int dy)
{
    for (int i=0; i<dx; i++)
    {
        for (int j=0; j<dy; j++)
        {
            if (map[y_-j][x_+i] != ' ')
                map[y_-j][x_+i] = ' ';
        }
    }
}


bool Console::addUnite(Unite *u)
{
    int posX = DEB_TERR_X + (u->Getpos()-1)*(SIZE_CASE-1);

    vector<string> skin;
    skin = selectSkin(u->monSkin());
    if(!u->isCampA())
    {
        posX -= SIZE_CASE-1;
        //on inverse le skin
        for (unsigned int i=0; i<skin.size(); i++)
        {
            skin[i] = string ( skin[i].rbegin(), skin[i].rend() );
        }
    }
    drawUnite(u, skin, posX);

    return true;
}

vector<string> Console::selectSkin(int skin)
{
    vector<string> map2;
    if(skin==PRIX_F)
    {
        map2.push_back("F");
        map2.push_back(" o  ");
        map2.push_back("@|^-");
        map2.push_back(" W  ");
    }else if(skin==PRIX_F+1)
    {
        map2.push_back("S");
        map2.push_back("  O  ");
        map2.push_back(".+S+.");
        map2.push_back("  W  ");
    } else if(skin==PRIX_A)
    {
        map2.push_back("A");
        map2.push_back(" A ");
        map2.push_back("i|i");
        map2.push_back(" W ");
    } else if(skin==PRIX_C)
    {
        map2.push_back("C");
        map2.push_back(" .| ");
        map2.push_back("o | ");
        map2.push_back("__|_");
        map2.push_back("O  O");
    }
    else
        map2.push_back("  ?  ");

    return map2;
}


void Console::clignoter(int nb_clign, unsigned int microseconds, int posx, int posy, string old, string new_)
{
    for (int i=0; i<nb_clign; i++)
    {
        clearZ(posx, posy, old.size(), 1);
        afficherText(new_, posx, posy);
        nettoyerConsole();
        affTerrain();

/*        Sleep(microseconds);
*/
        clearZ(posx, posy, new_.size(), 1);
        afficherText(old, posx, posy);
        nettoyerConsole();
        affTerrain();
/*        Sleep(microseconds);
*/        clearZ(posx, posy, old.size(), 1);
    }
}

void Console::addGold()
{
    string new_ = "+"+intToString(GOLD_TOUR)+" gold";
    unsigned int microseconds = 700;
    Console::clignoter(1, microseconds, INFO_BASE_X+2,INFO_BASE_Y+1, new_, " ");
    Console::clignoter(1, microseconds, INFO_BASEB_X+2,INFO_BASEB_Y+1, new_, " ");
}

/** \brief
 *
 * \param u : adresse de l'unite
 * \param map2 : tableau contenant le skin de l'unite
 * \param posX : position de l'unite  selon l'axe des abscisse
 *
 * \return true
 *
 */
bool Console::drawUnite(Unite *u, vector<string> map2, int posX)
{
    //on place l'unite au sol
    int posY = DEB_TERR_Y;
    posX += 1;

    //si on vient de creer l'unite
    if(u->Getpos() == 0 && u->isCampA())
    {
        afficherText(map2[0], INFO_BASE_X-1, INFO_BASE_Y-1);
        return false;
    }
    else if(u->Getpos() == NB_CASES && !u->isCampA())
    {
        afficherText(map2[0], INFO_BASEB_X-1, INFO_BASEB_Y-1);
        return false;
    }

    //on se balade en ordonee
    for(unsigned int i= 0; i < map2.size()-1; i++)
    {
        //map[niveau du sol - (hauteur de l'unite -1)][pos de l'unite + pos du carac a dessiner]
        //          = map2[hauteur du carac de l'unite][largeur du carac de l'unite]
        //[1]: on part du sol et on remonte
        //[2]: on dessine tous les caracteres de la hauteur fixee
//        map[posY-(h-1) + i][posX+j] = map2[i][j];
        afficherText(map2[map2.size()-i-1], posX, posY-i);
    }

    string s = map2[0] + "\n";
    s += intToString(u->Getpv());

    afficherText(s, posX+1, DEB_TERR_Y+2);
    return true;
}


/** \brief dessine une boite dans la console
 *
 * \param contour_l : le caractere utilise pour faire le contour en longueur
 * \param contour_h : le caractere utilise pour faire le contour en hauteur
 * \param int l : longueur de la boite
 * \param int h : hauteur de la boite
 * \param int posX : position en abscisse du coin superieur gauche de la boite
 * \param int posY : position en ordonnee du coin superieur gauche de la boite
 */
void Console::drawBox(char contour_l, char contour_h, char Fill, int l, int h, int posX, int posY)
{
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(j == 0 || j == h-1)
                map[posY+j][posX+i] = contour_l;

            else if(i == 0 || i == l-1)
                map[posY+j][posX+i] = contour_h;

            else
                map[posY+j][posX+i] = Fill;
        }
    }
}


void Console::affQTourJoueur()
{
    question = TOUR_JOUEUR;
    vector<string> v;
    v.push_back("Debut de tour, que voulez-vous faire ?");
    v.push_back(" ");
    v.push_back("1) Acheter une unite");
    v.push_back("2) Passer son tour");
    Console::afficherQuestion(v);
}

void Console::affQAcheterUnite()
{
    question = BUY_UNIT;
    vector<string> v;
    v.push_back("Quelle unite voulez-vous acheter ?");
    v.push_back(" ");
    v.push_back("1) Fantassin");
    v.push_back("2) Archer");
    v.push_back("3) Catapulte");
    v.push_back("4) Passer son tour");
    Console::afficherQuestion(v);
}

bool Console::choixJoueur(Terrain &t)
{
//    int choix = y - (DEB_QUEST_Y);
//
//    if(question == TOUR_JOUEUR)
//    {
//        if(choix == 1)
//        {
//            acheterUnite();
//        }
//        else
//            return false;
//    }
//    else if(question == BUY_UNIT)
//    {
//        //achat du fantassin
//        if(choix == 1)
//        {
//            Fantassin *f = new;
//            f->SetcampA(false);
//            f->setSuper(true);
//
//            t.ajouterUnite(f);
//            updateUnites(t.gettab());
//        }
//        //achat de l'arche
//        else if(choix == 2)
//        {
//            Archer *a;
//            a->SetcampA(false);
//
//            t.ajouterUnite(a);
//            Console::updateUnites(t.gettab());
//        }
//        //achat de la catapulte
//        else if(choix == 3)
//        {
//            Catapulte *c;
//            c->SetcampA(true);
//
//            t.ajouterUnite(c);
//            Console::updateUnites(t.gettab());
//        }
//        else if(choix == 4)
//        {
//            //on passe
//        }
//        else
//            return false;
//
//        tourJoueur();
//    }
//    else
//        return false;

    //reposition du curseur
    x = 32;
    y = 34;
    Move(0,0);
    return true;
}

/** \brief
 *
 * \param blocQuestion : liste composee d'une question et de au moins 1 choix
 * \param
 * \return
 *
 */
void Console::afficherQuestion(vector<string> blocQuestion)
{
    unsigned int pos=0;
    int maxX = blocQuestion[pos].size()+TAB;
    int maxY = blocQuestion.size()+TAB;

    for (unsigned int i = 0; i < blocQuestion.size(); i++)
    {
        if(blocQuestion[i].size() > blocQuestion[pos].size())
            pos = i;
    }
     drawBox('~', '|', ' ', maxX, maxY, DEB_QUEST_X-TAB/2, DEB_QUEST_Y-1);

    for (unsigned int i = 0; i < blocQuestion.size(); i++)
    {
        if(i==0)
        {
            afficherText(blocQuestion[i], DEB_QUEST_X, DEB_QUEST_Y);
        }
        else
            afficherText(blocQuestion[i], DEB_QUEST_X+TAB, DEB_QUEST_Y+i);
    }
    positionnerCuseur(DEB_QUEST_X + 4, DEB_QUEST_Y+2);
}

void Console::infoPartie(int tour, int nbMob, bool joueurA, int phase)
{
    string nom = "B";
    if(joueurA)
        nom = "A";

    vector<string> infoPertie;
    infoPertie.push_back("info Partie:");
    infoPertie.push_back("____________");
    infoPertie.push_back(" ");

    string s = "Tour:   "+intToString(tour);
    infoPertie.push_back(s);

    s = "nb mob: "+intToString(nbMob);
    infoPertie.push_back(s);

    s = "Joueur: "+nom;
    infoPertie.push_back(s);

    s = "Phase:  "+intToString(phase);
    infoPertie.push_back(s);

    affTextBox(infoPertie, TOUR_VALUE_X, TOUR_VALUE_Y);
}

void Console::afficherText(string Result, int posX, int posY)
{
    int u=0;
    int v=0;

    for (unsigned int i=0; i<Result.size(); i++)
    {
        if(Result[i] == '\n')
        {
            u++;
            v=0;
        }
        else
        {
            map[posY+u][posX+v] = Result[i];
            v++;
        }
    }
}

string Console::intToString(int x)
{
    string Result;
    stringstream convert1;
    convert1 << x;
    Result = convert1.str();
    return Result;
}

void Console::modeSpectateur()
{
    vector<string> v;
    v.push_back("*** Vous etes en mode spectateur. ***");
    v.push_back(" ");
    v.push_back("1) continuer");
    v.push_back("2) quitter ce mode");
    Console::afficherQuestion(v);
}
