//Arbre Rouge et Noir
#include "ARN.h"
#include "noeud.h"

using namespace std;

ARN::ARN(){
    racine = NULL;
    hauteurNoire = 0;
}

ARN::~ARN(){
    cout << "Destruction ARN." << endl;     //TODO destructeur
}

Noeud* ARN::rechercherElement(const Element &e){
    Noeud * recherche = this->racine;
    while(recherche){
        if(recherche->info == e){
            cout << "L'element : " << e << "  a été trouvé." <<endl;
            return recherche;       //retourne un pointeur sur le noeud trouvé
        }
        else if(recherche->info < e){
            recherche = recherche->fd;
        }
        else{
            recherche = recherche->fg;
        }   
    }
    cout << "L'element " << e << "  n'est pas dans l'arbre." << endl;
    return nullptr;                 //retourne un pointeur sur nullptr si non trouvé
}

void ARN::insertionRec(Noeud *&node, const Element &e){             //void ARN::insertionRec(Noeud *&node, const Element &e){
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
    Noeud* node = rechercherElement(e);
    cout << "elmt inséré : " << node << endl;
    if(e == 2){
        cout << "fd = " << this->racine->fd->fd->info << endl;
    }
    equilibrage(node);
    //this->racine->couleur = 'N';
}

void ARN::equilibrage(Noeud* node){
    Noeud* pere = getNoeudParent(node);
    Noeud* oncle = getNoeudOncle(node);
    if(pere == nullptr){                //on tombe sur la racine (cas 1)
        cout << "***** Cas de la racine ******" << endl;
        node->couleur = 'N';
    }
    else if(pere->couleur == 'N'){                              //(cas 2)
        cout << "***** Cas equilibré de l'ARN ******" << endl;
        return;
    }
    else if(oncle != nullptr and oncle->couleur == 'R'){     //oncle rouge : recoloration oncle et pere en noir et gd-pere en rouge     //(cas 3)
        cout << "****** cas de l'oncle rouge ******" << endl;
        cas1(node);
    }
    else{
        Noeud* gdPere = getNoeudGrandParent(node);
        cout << ";;;;;;;;;;; papi : " << gdPere->info << endl;
 
        if(gdPere->fg != nullptr && gdPere->fg->fd != nullptr && node == gdPere->fg->fd){                     //insertion 2 : on ne rentre pas ici
            cout << "[DEBUG] : pere = " << pere << endl;
            rotationGauche(pere);
            node = node->fg;
        }
 
        else if(gdPere->fd != nullptr && gdPere->fd->fg != nullptr && node == gdPere->fd->fg){
            rotationDroite(pere);
            node = node->fd;
        }
        cas2(node);
        
    }
}

void ARN::cas1(Noeud* node){
    Noeud* pere = getNoeudParent(node);
    Noeud* gdPere = getNoeudGrandParent(node);
    Noeud* oncle = getNoeudOncle(node);
    pere->couleur = 'N';
    cout << "coloration " << pere->info << "en noir" << endl;
    oncle->couleur = 'N';
    cout << "coloration " << oncle->info << "en noir" << endl;
    gdPere->couleur = 'R';
    cout << "coloration " << gdPere->info << "en rouge" << endl;
    equilibrage(gdPere);
}

void ARN::cas2(Noeud* node){
    cout << "cas 2 ??????" << endl;
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

void ARN::rotationGauche(Noeud* node){          // x = node
    cout << "****** Cas de la rotation gauche ******" << endl;

    Noeud* temp = node->fd;
    Noeud* pereFgTemp = nullptr;
    if(temp->fg != nullptr){
        pereFgTemp = getNoeudParent(temp->fg);
    }
    Noeud* pereNode = getNoeudParent(node);
    Noeud* pereTemp = getNoeudParent(temp);
    
    node->fd = temp->fg;
    if(temp->fg == nullptr){
        pereFgTemp = node;
    }
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
    


/*  TENTATIVE 1
    Noeud* temp = node->fd;                     // y = temp
    Noeud* pere = getNoeudParent(node);
    node->fd = temp->fg;
    if(pere == nullptr){
        node = temp;
    }
    else if(node == pere->fg){
        pere->fg = temp;
    }
    else{
        pere->fd = temp;
    }
    temp->fg = node;
*/  
}

void ARN::rotationDroite(Noeud* node){
    cout << "****** Cas de la rotation droite ******" << endl;

    Noeud* temp = node->fg;
    Noeud* pereFdTemp = nullptr;
    if(temp->fd != nullptr){
        pereFdTemp = getNoeudParent(temp->fd);
    }
    Noeud* pereNode = getNoeudParent(node);
    Noeud* pereTemp = getNoeudParent(temp);
    
    node->fg = temp->fd;
    if(temp->fd == nullptr){
        pereFdTemp = node;
    }
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


/*      TENTATIVE 1
    Noeud* temp = node->fg;
    Noeud* pere = getNoeudParent(node);
    node->fg = temp->fd;
    if(pere == nullptr){
        node = temp;
    }
    else if(node == pere->fd){
        pere->fd= temp;
    }
    else{
        pere->fg = temp;
    }
    temp->fd = node;
    */
}

Noeud* ARN::getNoeudParent(const Noeud* node){
    Noeud* recherche = this->racine;
    Noeud* parent = nullptr;
    Element e = node->info;
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


Noeud* ARN::getNoeudGrandParent(const Noeud* node){
    Noeud* grandParent = nullptr;
    Noeud* parent = getNoeudParent(node);
    if(parent != nullptr){
        grandParent = getNoeudParent(parent);
    }
    return grandParent;
}

Noeud* ARN::getNoeudArriereGrandParent(const Noeud* node){
    Noeud* arGdParent = nullptr;
    Noeud * gdParent = getNoeudGrandParent(node);
    if(gdParent != nullptr){
        arGdParent = getNoeudParent(gdParent);
    }
    return arGdParent;
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
    //cout << "Hauteur noire : " << this->hauteurNoire << endl << endl;
    cout << endl;
    affichageRec(this->racine, 0);
}