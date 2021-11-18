//Arbre Rouge et Noir
#ifndef _ARN
#define _ARN
#include "noeud.h"

class ARN{
    public:
        Noeud* racine;

        ARN();  
        ~ARN();
        void vider(Noeud* node);
        void insertion(const Element &e);
        Noeud* rechercherElement(const Element &e);
        void affichage();
        Noeud* getNoeudParent(const Noeud* node);
        Noeud* getNoeudGrandParent(const Noeud* node);
        Noeud* getNoeudArriereGrandParent(const Noeud* node);
        Noeud* getNoeudOncle(const Noeud* node);

        void equilibrage(Noeud* node);
        void cas1(Noeud* node);
        void cas2(Noeud* node);

        void rotationGauche(Noeud* node);
        void rotationDroite(Noeud* node);

        void insertionRec(Noeud *&node, const Element &e);
    
    private:
        void affichageRec(Noeud* n, int prof);
        
    };

#endif