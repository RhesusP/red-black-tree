//Arbre Rouge et Noir
#include "ARN.h"
#include "noeud.h"

using namespace std;

ARN::ARN(){
    racine = NULL;
    hauteurNoire = 0;
}

ARN::~ARN(){
    cout << "       ▄      ▄    " << endl;
    cout << "      ▐▒▀▄▄▄▄▀▒▌   " << endl;
    cout << "    ▄▀▒▒▒▒▒▒▒▒▓▀▄  " << endl;
    cout << "  ▄▀░█░░░░█░░▒▒▒▐  " << endl;
    cout << "  ▌░░░░░░░░░░░▒▒▐  " << endl;
    cout << " ▐▒░██▒▒░░░░░░░▒▐  " << endl;
    cout << " ▐▒░▓▓▒▒▒░░░░░░▄▀  " << endl;
    cout << "  ▀▄░▀▀▀▀░░░░▄▀    " << endl;
    cout << "    ▀▀▄▄▄▄▄▀▀       " << endl;
}

bool ARN::rechercherElement(const Element &e){
    Noeud * recherche = this->racine;
    while(recherche){
        if(recherche->info == e){
            cout << "L'element : " << e << "  a été trouvé." <<endl;
            return true;
        }
        else if(recherche->info < e){
            recherche = recherche->fd;
        }
        else{
            recherche = recherche->fg;
        }   
    }
    cout << "L'element " << e << "  n'est pas dans l'arbre." << endl;
    return false;
}

void ARN::insertionRec(Noeud *&node, const Element &e){
    if(node == NULL){
        node = new Noeud(e);
        node->couleur = 'R';
    }
    else if(e == node->info){
        cout << "Impossible d'ajouter l'element " << e << " (doublons non autorisés)." << endl;
    }
    else{
        if(e > node->info){
            insertionRec(node->fd, e);
        }
        else{
            insertionRec(node->fg, e);
        }
    }
}

void ARN::insertion(const Element &e){
    insertionRec(this->racine, e);
    this->racine->couleur = 'N';

}



Noeud* ARN::getNoeudParent(const Element &e){
    Noeud* parent = new Noeud;
    Noeud* recherche = this->racine;
    while(recherche){
        if(recherche->info == e){
            return parent;
        }
        else if(recherche->info < e){
            parent = recherche;
            recherche = recherche->fd;
        }
        else{
            parent = recherche;
            recherche = recherche->fg;
        }   
    }
}

Noeud* ARN::getNoeudOncle(const Element &e){
    Noeud* oncle;
    Noeud* parent = getNoeudParent(e);
    Noeud* grandParent = getNoeudParent(parent->info);
    if(grandParent->fd == parent){
        oncle = grandParent->fg;
    } 
    else{
        oncle = grandParent->fd;
    }
    return oncle;
}




void ARN::affichageRec(Noeud* n, int prof){
    if(n != nullptr){
        affichageRec(n->fd, prof+1);
        for(int i=0 ; i<prof ; i++){
            cout << "       ";
        }
        cout << n->info << " (" << n->couleur << ")" << endl;
        affichageRec(n->fg, prof+1);
    }
}

void ARN::affichage(){
    cout << "Hauteur noire : " << this->hauteurNoire << endl << endl;
    affichageRec(this->racine, 0);
}