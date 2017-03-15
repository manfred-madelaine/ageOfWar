#include "Affichage.hpp"

Affichage::Affichage()
{
    //ctor
}

Affichage::~Affichage()
{
    //dtor
}

void Affichage::mode()
{
    cout << "Quel mode de jeu choisissez-vous ?" <<
    "\n(entrez le numero du mode de votre choix)" <<
    "\n\t1. IA versus IA." <<
    "\n\t2. Player versus IA." <<
    "\n>> ";
}

void Affichage::playerVSia()
{
    cout << "Vous affronterez donc un IA lors de cette partie!" << endl;
}
void Affichage::iaVSia()
{
    cout << "Vous regarderez donc l'ordinateur jouer contre lui meme lors de cette partie!" << endl;
}

void Affichage::camp()
{
    cout << "Quel camp choisissez-vous ?(A ou B)" <<
    "\n\t1. Camp A" <<
    "\n\t2. Camp B" <<
    "\n>> ";
}

void Affichage::campX(string nomCamp)
{
    cout << "Vous avez choisi le camp " << nomCamp << " !" << endl;
}


/** \brief verifie que la reponse fait bien partie des reponses autorisees
 *
 * \param rep : reponse a controler
 * \param enumeration[] : tableau des reponses autorise
 * \param l : longueur du tableau enumeration

 * \return true si la reponse est incorrecte (non comprise dans le tableau),
 *          false sinon.
 *
 */

bool Affichage::repIncorrecte(string rep, string enumeration[], int l)
{
    for(int i = 0; i < l; i++)
    {
        if (enumeration[i] == rep)
        {
            return false;
        }
    }
    return true;
}

void Affichage::fonctIndisponible()
{
    cout << "Cette fonctionnalite n'a pas encore ete implementee malheureusement. " << endl;
}

void Affichage::tour(int i)
{
    cout << "Tour " << i << endl;
}

void Affichage::phase1()
{
    cout << "Phase 1:" << endl;
}

void Affichage::phase2()
{
    cout << "Phase 2:" << endl;
}

void Affichage::phase3()
{
    cout << "Phase 3:" << endl;
}

void Affichage::acheter()
{
    cout << "Quelle unite voulez-vous acheter ? (1, 2 ou 3)" <<
    "\n\t1. Fantassin   => 10 gold." <<
    "\n\t2. Archer      => 12 gold." <<
    "\n\t3. Catapulte   => 20 gold." <<
    "\n>> ";
}

void unite(string nom, int p)
{
  cout << nom <<" => " << p << " gold." << endl;
}

void Affichage::goldsBase(int gold)
{
    cout << "Sa base possede " << gold << " gold !" << endl;
}

void Affichage::reponseIncorecte()
{
    cout << "Votre reponse est incorrecte, veuillez rentrer un reponse valide." << endl;
}

void Affichage::moveIncorecte()
{
    cout << "on ne passe pas !"<<endl;
}

void Affichage::toucheIncorecte()
{
    cout << "La touche n'est pas reconnue." << endl;
}

void Affichage::pasDeVainceur()
{
    cout << "Le jeu s'est termine et il n'y a pas eu de vainqueur!" << endl;
}

void Affichage::vainceur()
{
    cout << "Le grand vainqueur!" << endl;
}

void Affichage::vainqueur(bool campA){
    cout<<endl<<endl;
    if(campA){
        cout<<"Bravo le joueur A a gagne la partie"<<endl;
    }
    else cout<<"Bravo le joueur B a gagne la partie"<<endl;
    exit(EXIT_SUCCESS);
}
