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
    //insertion sans regarder les couleurs
    insertionRec(this->racine, e);
    //this->racine->couleur = 'N';        //TODO move to insertionRec()
    
    
    //Reequilibrage local
    Noeud* parent = getNoeudParent(e);
    Noeud* grandParent = getNoeudGrandParent(e);
    Noeud* oncle = getNoeudOncle(e);
    cout << "insertion " << e << " | pere : " << parent << " | gd-pere : " << grandParent << " | oncle : " << oncle << endl;        //TODO debug only
    if(parent != nullptr and grandParent != nullptr and oncle != nullptr){
        //TODO gestion recursive
        //reequilibrage local "si le noeud Q possede un oncle O rouge, alors on change la couleur de P et de Q qui deviennent noirs et PP devient rouge"
        if(oncle->couleur=='R'){
            cout << "yes" << endl;
            oncle->couleur = 'N';
            parent->couleur = 'N';
            grandParent->couleur = 'R';
        }

        
    }

    
    //TODO ne pas oublier de mettre la racine en noir à la fin de la fonction.
}

Noeud* ARN::getNoeudParent(const Element &e){
    Noeud* recherche = this->racine;
    Noeud* parent = nullptr;
    while(recherche && recherche->info != e){
/*
        cout << "elmt recherche : " << e << " | actuel : " << recherche->info << " | pere : ";
        if(parent == nullptr){
            cout << "nullptr" << endl;
        }
        else{
            cout << parent->info << endl;
        }
*/      
        if(recherche->info < e){
            parent = recherche;
            recherche = recherche->fd;
        }
        else{
            parent = recherche;
            recherche = recherche->fg;
        }
    }
    return parent;
}


Noeud* ARN::getNoeudGrandParent(const Element &e){
    Noeud* grandParent = nullptr;
    Noeud* parent = getNoeudParent(e);
    if(parent != nullptr){
        grandParent = getNoeudParent(parent->info);
    }
    return grandParent;
}

Noeud* ARN::getNoeudOncle(const Element &e){
    Noeud* oncle = nullptr;
    Noeud* parent = getNoeudParent(e);
    Noeud* grandParent = getNoeudGrandParent(e);
    if(grandParent !=nullptr){
        if(grandParent->fd == parent){
            oncle = grandParent->fg;
        }
        else{
            oncle = grandParent->fg;
        }
    }
    return oncle;
}



void ARN::affichageRec(Noeud* n, int prof){
    if(n != nullptr){
        affichageRec(n->fd, prof+1);
        for(int i=0 ; i<prof ; i++){
            cout << "       ";
        }
        cout << "─────┤" << n->info << " (" << n->couleur << ")" << endl;
        affichageRec(n->fg, prof+1);
    }
}

void ARN::affichage(){
    cout << "Hauteur noire : " << this->hauteurNoire << endl << endl;
    affichageRec(this->racine, 0);
}