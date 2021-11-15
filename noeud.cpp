#include "noeud.h"
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

void Noeud::affichageNoeud(){
    std::cout << this->info;
}