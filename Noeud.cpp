#include "Noeud.h"
#include <iostream>

Noeud::Noeud(){
    fg = nullptr;
    fd = nullptr;
    couleur = 'R';
}

Noeud::Noeud(const Element &e){
    fg = nullptr;
    fd = nullptr;
    info = e;
    couleur = 'R';
}

Noeud::~Noeud(){
    fg = nullptr;
    fd = nullptr;
    info = 0;
    couleur = ' ';
}