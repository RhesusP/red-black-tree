//Arbre Rouge et Noir
#include "ARN.h"
#include "Noeud.h"

using namespace std;

ARN::ARN(){
    racine = NULL;
}

ARN::~ARN(){
    if(racine != NULL){
        vider(racine);
    }
}

void ARN::insertion(const Element &e){
    insertionRec(this->racine, e);

    Noeud* node = rechercherElement(e);
    equilibrage(node);
}

void ARN::recherche(const Element &e){
    Noeud* result = rechercherElement(e);
    if(result == nullptr){
        cout << "L'element " << e << " n'est pas dans l'arbre." << endl;
    }
    else{
        cout << "L'element " << e << " a ete trouve." << endl;
    }
}

void ARN::affichage(){
    cout << endl;
    affichageRec(this->racine, 0);
}

/* ------------------------------------------------------------ */

Noeud* ARN::getNoeudParent(const Noeud* node){
    Noeud* recherche = this->racine;
    Noeud* parent = nullptr;
    Element e = node->info;
    while(recherche && recherche->info != e){
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

Noeud* ARN::getNoeudGrandParent(const Noeud* node){
    Noeud* grandParent = nullptr;
    Noeud* parent = getNoeudParent(node);
    if(parent != nullptr){
        grandParent = getNoeudParent(parent);
    }
    return grandParent;
}

Noeud* ARN::getNoeudOncle(const Noeud* node){
    Noeud* oncle = nullptr;
    Noeud* parent = getNoeudParent(node);
    Noeud* grandParent = getNoeudGrandParent(node);
    if(grandParent !=nullptr){
        if(grandParent->fd == parent){
            oncle = grandParent->fg;
        }
        else{
            oncle = grandParent->fd;
        }
    }
    return oncle;
}

void ARN::insertionRec(Noeud *&node, const Element &e){
    if(node == NULL){
        node = new Noeud(e);
        node->couleur = 'R';
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

void ARN::equilibrage(Noeud* node){
    Noeud* pere = getNoeudParent(node);
    Noeud* oncle = getNoeudOncle(node);
    if(pere == nullptr){
        //cout << "***** Cas de la racine ******" << endl;
        node->couleur = 'N';
    }
    else if(pere->couleur == 'N'){
        //cout << "***** Cas equilibré de l'ARN ******" << endl;
        return;
    }
    else if(oncle != nullptr and oncle->couleur == 'R'){
        //cout << "****** Cas de l'oncle rouge ******" << endl;
        casOncleRouge(node);
    }
    else{
        Noeud* gdPere = getNoeudGrandParent(node);
        Noeud* pere = getNoeudParent(node);
        if(gdPere->fg != nullptr && gdPere->fg->fd != nullptr && node == gdPere->fg->fd){
            //cout << "rotation gauche node = PP->fg->fd" << endl;
            rotationGauche(pere);
            node = node->fg;
        }
        else if(gdPere->fd != nullptr && gdPere->fd->fg != nullptr && node == gdPere->fd->fg){
            //cout << "rotation droite node = PP->fd->fg" << endl;
            rotationDroite(pere);
            node = node->fd;
        }
        NoeudAlignes(node);
    }
}

void ARN::casOncleRouge(Noeud* node){
    Noeud* pere = getNoeudParent(node);
    Noeud* gdPere = getNoeudGrandParent(node);
    Noeud* oncle = getNoeudOncle(node);
    pere->couleur = 'N';
    oncle->couleur = 'N';
    gdPere->couleur = 'R';
    equilibrage(gdPere);
}

void ARN::NoeudAlignes(Noeud* node){
    Noeud* pere = getNoeudParent(node);
    Noeud* gdPere = getNoeudGrandParent(node);
    if(node == pere->fg){
        rotationDroite(gdPere);
    }
    else{
        rotationGauche(gdPere);
    }
    pere->couleur = 'N';
    gdPere->couleur = 'R';
}


void ARN::rotationGauche(Noeud* node){
    //cout << "****** Cas de la rotation gauche ******" << endl;

    Noeud* temp = node->fd;
    Noeud* pereNode = getNoeudParent(node);
    Noeud* pereTemp = getNoeudParent(temp);
    
    node->fd = temp->fg;
    pereTemp = pereNode;
    if(pereTemp == nullptr){
        this->racine = temp;
    }
    else if(node == pereNode->fg){
        pereNode->fg = temp;
    }
    else{
        pereNode->fd = temp;
    }
    temp->fg = node;
    pereNode = temp;
}

void ARN::rotationDroite(Noeud* node){
    //cout << "****** Cas de la rotation droite ******" << endl;

    Noeud* temp = node->fg;
    Noeud* pereNode = getNoeudParent(node);
    Noeud* pereTemp = getNoeudParent(temp);
    
    node->fg = temp->fd;
    pereTemp = pereNode;
    if(pereTemp == nullptr){
        this->racine = temp;
    }
    else if(node == pereNode->fd){
        pereNode->fd = temp;
    }
    else{
        pereNode->fg = temp;
    }
    temp->fd = node;
    pereNode = temp;
}

Noeud* ARN::rechercherElement(const Element &e){
    Noeud * recherche = this->racine;
    while(recherche){
        if(recherche->info == e){
            return recherche;
        }
        else if(recherche->info < e){
            recherche = recherche->fd;
        }
        else{
            recherche = recherche->fg;
        }   
    }
    return nullptr;
}

void ARN::affichageRec(Noeud* n, int prof){
    if(n != nullptr){
        affichageRec(n->fd, prof+1);
        for(int i=0 ; i<prof ; i++){
            cout << "       ";
        }
        if(prof == 0){
            cout << " ──────┤";
            if(n->couleur == 'R'){
                cout << "\033[1;37;41m" << n->info << " (" << n->couleur << ")\033[0m" << endl;
            }
            else{
                cout << "\033[1;37;40m" << n->info << " (" << n->couleur << ")\033[0m" << endl;
            }
        }
        else{
            cout << "+──────┤";
            if(n->couleur == 'R'){
                cout << "\033[1;37;41m" << n->info << " (" << n->couleur << ")\033[0m" << endl;
            }
            else{
                cout << "\033[1;37;40m" << n->info << " (" << n->couleur << ")\033[0m" << endl;
            }
        }
        affichageRec(n->fg, prof+1);
    }
}

void ARN::vider(Noeud* node){
    if(node->fg != nullptr){
        vider(node->fg);
    }
    if(node->fd != nullptr){
        vider(node->fd);
    }
    //cout << "noeud " << node->info << " supprimé" << endl;
    delete node;
}