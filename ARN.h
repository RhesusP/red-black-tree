//Arbre Rouge et Noir
#ifndef _ARN
#define _ARN
#include "noeud.h"

class ARN{
    public:
        Noeud* racine;
        int hauteurNoire;

        ARN();
        //TODO destructeur de l'ARN
        ~ARN();
        void insertion(const Element &e);
        bool rechercherElement(const Element &e);
        void affichage();
        Noeud* getNoeudParent(const Element &e);
        Noeud* getNoeudOncle(const Element &e);
    
    private:
        void affichageRec(Noeud* n, int prof);
        void insertionRec(Noeud *&node, const Element &e);
    };

#endif