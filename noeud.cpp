#include "noeud.h"
#include <iostream>

Noeud::Noeud(){
    fg = nullptr;
    fd = nullptr;
    couleur = 'R';
}

Noeud::~Noeud(){
    fg = nullptr;
    fd = nullptr;
    info = 0;
    couleur = ' ';
}

Noeud::Noeud(const Element &e){
    fg = nullptr;
    fd = nullptr;
    info = e;
    couleur = 'R';
}