//Arbre Binaire de Recherche
#ifndef _ABR
#define _ABR

#include "noeud.h"

class ABR{
    public:
        Noeud* racine;

        ABR();
        ~ABR();

        void insertion(const Element &e);
        Noeud* rechercherElement(const Element &e);
        void affichage();

    private:
        void affichageRec(Noeud* n, int prof);
        void insertionRec(Noeud *&node, const Element &e);
        void vider(Noeud* node);
};

#endif