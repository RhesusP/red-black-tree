//Arbre Binaire de Recherche
#ifndef _ABR
#define _ABR

#include "noeud.h"

class ABR{
    public:
        Noeud* racine;

        /**
         * @brief Constructeur par défaut du module Arbre Binaire de Recherche.
         */
        ABR();

        /**
         * @brief Destructeur de l'Arbre Binaire de Recherche.
         * Fait appel à la procedure récursive `vider()` lorsque l'arbre n'est pas vide.
         */
        ~ABR();

        /**
         * @brief Insere un element dans un ABR. 
         * Fait appel à la procedure recursive `insertionRec` à partir de la racine.
         * @param e (Element) L'element a inserer.
         */
        void insertion(const Element &e);

        /**
         * @brief Recherche un element dans un ABR.
         * Fonction récursive parcourant l'arbre grace a un Noeud* voyageur a partir de la racine. 
         * Si l'element parcouru < element recherche : appel recursif sur le fils droit
         * Si l'element parcouru > element recherche : appel recursif sur le fils gauche
         * Cas d'arret : l'element parcouru est l'element recherche.
         * @param e (Element) L'element a rechercher.
         * @return Noeud* de l'element correspondant. nullptr si introuvable.
         */
        Noeud* rechercherElement(const Element &e);

        /**
         * @brief Affiche l'ABR.
         * Fait appel à la procedure recursive `affichageRec()`.
         */
        void affichage();

    private:

        /**
         * @brief Procedure recursive affichant les noeud un par un.
         * Affiche les noeuds de l'arbre grace a un parcours infixe. Les noeuds sont decalés en fonction de leur profondeur 
         * dans l'arbre.
         * @param n (Noeud*) Noeud a partir d'ou afficher.
         * @param prof (int) Profondeur du noeud
         */
        void affichageRec(Noeud* n, int prof);

        /**
         * @brief Procedure recursive inserant un element 
         * Parcourt l'arbre depuis un noeud donné et regarde si l'element est plus grand ou plus 
         * petit afin de faire un appel recursif sur le fils droit ou le fils gauche. S'arrete lorsque
         * l'on est a une extremite de l'arbre afin d'inserer l'element en feuille.
         * @param node (Noeud*) Noeud a partir d'ou debute l'insertion
         * @param e (Element) L'element a insere
         */
        void insertionRec(Noeud *&node, const Element &e);

        /**
         * @brief Libere l'espace memoire occupe par l'arbre.
         * Effectue un parcours infixe et libere l'espace memoire des feuilles une a une.
         * @param node (Noeud*) Le noeud a partir duquel realiser le parcours.
         */
        void vider(Noeud* node);
};

#endif