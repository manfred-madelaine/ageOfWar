#include "Partie.hpp"

Partie::Partie() :
    m_terrain(12), m_joueurA(NULL), m_joueurB(NULL), m_tour(0), phase(), isA(true)
{

}

Partie::~Partie()
{
    //dtor
}

bool gamerunning = false;
bool menuB = false;


bool Partie::play()
{
//    init();
    modeSpect();
    Console::ecranAccueil();
    Console::drawBox('#', '#', ' ', MAX_X-1, MAX_Y, 0, 0);
    menu();
//    Console::intiMap();
    boucle();
    return true;
}

bool Partie::init()
{
    string rep("");
    string enumeration[2];
    enumeration[0] = "1";
    enumeration[1] = "2";
    while (Affichage::repIncorrecte(rep, enumeration, 2))
    {
        if(rep != "")
            Affichage::reponseIncorecte();
        Affichage::mode();
        getline(cin,rep);
    }
    if (rep == enumeration[0])
    {
        modeSpect();

        return true;
    }

    Affichage::playerVSia();
    rep = "";
    enumeration[0] = "A";
    enumeration[1] = "B";
    while (Affichage::repIncorrecte(rep, enumeration, 2))
    {
        if(rep != "")
            Affichage::reponseIncorecte();
        Affichage::camp();
        getline(cin,rep);
    }

    Affichage::campX(rep);
    if(rep == enumeration[0]){
        Player* plyr = new Player(m_terrain.GetbaseA());
        Ia* ia2= new Ia(m_terrain.GetbaseB());
        m_joueurA = plyr;
        m_joueurB = ia2;
    }
    else{
        Player* plyr = new Player(m_terrain.GetbaseA());
        Ia* ia2 = new Ia(m_terrain.GetbaseB());
        m_joueurB = plyr;
        m_joueurA = ia2;
    }
    return true;
}

void Partie::modeSpect()
{
//    Affichage::iaVSia();
    Ia* ia1= new Ia(m_terrain.GetbaseA());
    Ia* ia2= new Ia(m_terrain.GetbaseB());
    m_joueurA = ia1;
    m_joueurB = ia2;
    modeSpec = true;
}

bool Partie::endGame()
{
    if(m_terrain.GetbaseA().Getpv() < 1 || m_terrain.GetbaseB().Getpv() < 1)
    {
        return true;
    }
    return false;
}


/** \brief enchaine les tours de jeu  d'une partie jusqu'a ce que le jeu se termine.
 *
 * \return true si l'un des joueurs n'a plus de base,
 *          false si plus aucun joueur ne peut joueur.
 *
 */
bool Partie::boucle()
{
    while (nextTour())
    {
        if (!tourJoueur(*m_joueurA) || !tourJoueur(*m_joueurB))
            return true;
    }
    return false;
}


/** \brief
 *
 * \param
 * \param
 * \return true si la partie peut continuer, false si non
 *
 */
bool Partie::tourJoueur(Joueur& j)
{
    j.action1(m_terrain);
    update();
    if(m_terrain.GetbaseA().Getpv()<=0){
        Affichage::vainqueur(false);
    }
    else if(m_terrain.GetbaseB().Getpv()<=0){
        Affichage::vainqueur(true);
    }

    j.action2(m_terrain);
    update();

    j.action3(m_terrain);
    update();
    if(m_terrain.GetbaseA().Getpv()<=0){
        Affichage::vainqueur(false);
    }
    else if(m_terrain.GetbaseB().Getpv()<=0){
        Affichage::vainqueur(true);
    }

    for(unsigned int i=0;i<m_terrain.gettab().size();i++){
        m_terrain.getUniteTab(i).setOkAction1(false);
    }
    j.newUnite(m_terrain);
    update();

    if(endGame())
        return false;
    return true;
}

void Partie::update()
{
    nextPhase();
    Console::updateTerrain(m_terrain, m_tour, isA, phase, modeSpec);
}

bool Partie::nextTour()
{
    if(m_tour < MAX_TOUR)
    {
        m_tour++;
//        if(m_tour > 1)
//            Console::addGold();
        m_terrain.newTour();
        return true;
    }
    return false;
}


void Partie::nextPhase()
{
    phase++;
    if(phase > 4){
        phase=1;
        nextJoueur();
    }
}

void Partie::nextJoueur()
{
    isA = !isA;
}


void Partie::menu()
{
    menuB = true;
    Console::menu();

    /*while (menuB)
    {
        system("clear");
        Console::affTerrain();
        while(!attendreAction()){}
    }*/
}


bool Partie::attendreAction()
{
    getchar();

/*
    system("pause>nul");

    //gestion des touches
    if(GetAsyncKeyState(VK_UP)){
        if(!Console::Move(-1,0)){
            Affichage::moveIncorecte();
            return false;
        }
        Console::update();
    }
    else if(GetAsyncKeyState(VK_DOWN)){
        if(!Console::Move(1,0)){
            Affichage::moveIncorecte();
            return false;
        }
        Console::update();
    }
    else if(GetAsyncKeyState(VK_LEFT)){
        if(!Console::Move(0, -1)){
            Affichage::moveIncorecte();
            return false;
            }
        Console::update();
    }
    else if(GetAsyncKeyState(VK_RIGHT)){
        if(!Console::Move(0, 1)){
            Affichage::moveIncorecte();
            return false;
        }
        Console::update();
    }

    //gestion de la partie
    else if(GetAsyncKeyState(VK_CLEAR) || GetAsyncKeyState(KEY_R))
    {
        m_terrain.gettab().clear();
        Console::intiMap();
    }
    else if(GetAsyncKeyState(VK_RETURN))
    {
        if(gamerunning)
        {
            if(!Console::choixJoueur(m_terrain))
            {
                Affichage::fonctIndisponible();
                return false;
            }
        }
        else
        {
            int choix = y - C_MENU_Y;
            if (choix==0)
            {
                Console::intiMap();
                menuB = false;
                gamerunning = true;
            }
            else if (choix == 2)
            {
                exit(EXIT_SUCCESS);
            }
            else
            {
                Affichage::fonctIndisponible();
                return false;
            }
        }

    }

    else if(GetAsyncKeyState(VK_ESCAPE))
        gamerunning = false;

    //gestion des unites
    else if(GetAsyncKeyState(KEY_F))
    {
        Fantassin f;
        f.SetcampA(true);
        f.setSuper(true);

        //t.ajouterUnite(f);
        //Console::updateUnites(t.gettab());
    }
    else if(GetAsyncKeyState(KEY_C))
    {
        Catapulte c;
        c.SetcampA(true);

        //t.ajouterUnite(c);
        //Console::updateUnites(t.gettab());
    }
    else if(GetAsyncKeyState(KEY_A))
    {
        Archer a;
        a.SetcampA(true);

        //t.ajouterUnite(a);
        //Console::updateUnites(t.gettab());
    }

    //deplacement des unites
    else if(GetAsyncKeyState(KEY_Q))
    {
        //t.gettab()[0].moveU(false,t.gettab());
        //Console::updateUnites(t.gettab());
    }
    else if(GetAsyncKeyState(KEY_D))
    {
        //t.gettab()[0].moveU(true,t.gettab());
        //Console::updateUnites(t.gettab());
    }

    else{
        Affichage::toucheIncorecte();
        return false;
    }
*/
    menuB = false;
    return false;
}
