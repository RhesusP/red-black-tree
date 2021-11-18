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

        Noeud();
        ~Noeud();
        Noeud(const Element &e);
};

#endif