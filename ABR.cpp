//Arbre Binaire de Recherche
#include "ABR.h"
#include "noeud.h"

using namespace std;

ABR::ABR(){
    racine = NULL;
}

ABR::~ABR(){
    if(racine != NULL){
        vider(racine);
    }
}

void ABR::vider(Noeud* node){
    if(node->fg != nullptr){
        vider(node->fg);
    }
    if(node->fd != nullptr){
        vider(node->fd);
    }
    //cout << "noeud " << node->info << " supprimé" << endl;
    delete node;
}   

void ABR::insertion(const Element &e){
    insertionRec(this->racine, e);
}

void ABR::insertionRec(Noeud *&node, const Element &e){
    if(node == NULL){
        node = new Noeud(e);
    }
    else if(e == node->info){
        //cout << "Impossible d'ajouter l'element " << e << " (doublons non autorisés)." << endl;
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

Noeud* ABR::rechercherElement(const Element &e){
    Noeud * recherche = this->racine;
    while(recherche){
        if(recherche->info == e){
            //cout << "L'element : " << e << "  a été trouvé." <<endl;
            return recherche;
        }
        else if(recherche->info < e){
            recherche = recherche->fd;
        }
        else{
            recherche = recherche->fg;
        }   
    }
    //cout << "L'element " << e << "  n'est pas dans l'arbre." << endl;
    return nullptr;
}

void ABR::affichageRec(Noeud* n, int prof){
    if(n != nullptr){
        affichageRec(n->fd, prof+1);
        for(int i=0 ; i<prof ; i++){
            cout << "       ";
        }
        cout << "─────┤" << n->info << endl;
        affichageRec(n->fg, prof+1);
    }
}

void ABR::affichage(){
    cout << endl;
    affichageRec(this->racine, 0);
}