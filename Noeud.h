#ifndef _NOEUD
#define _NOEUD
#include <iostream>
typedef int Element;

class Noeud{
    public:
        Noeud* fg;      //elmt plus petit
        Noeud* fd;      //elmt plus grand
        char couleur;        //"N" ou "R"
        Element info;

        /**
         * @brief Constructeur par défaut du module Noeud.
         * Initialise fg et fd a nullptr et la couleur en rouge.
         */
        Noeud();

        /**
         * @brief Constructeur du module Noeud.
         * Construit un noeud a partir d'un Element passe en parametre.
         * @param e (Element) Element stocke dans le noeud.
         */
        Noeud(const Element &e);

        /**
         * @brief Destructeur du module Noeud.
         */
        ~Noeud();
};

#endif