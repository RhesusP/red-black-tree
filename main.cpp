#include "ARN.h"
#include <iostream>

using namespace std;

int main(){
    ARN arbre;
    for(int i=0 ; i<20 ; i++){
        arbre.insertion(i);
    }
    arbre.affichage();

    ARN test;
    test.insertion(10);
    test.insertion(15);
    test.insertion(5);
    test.insertion(20);
    test.insertion(12);
    test.insertion(0);
    test.insertion(7);
    test.affichage();

    cout << endl;

    test.rechercherElement(7);
    Noeud* a = test.getNoeudParent(20);
    cout << "Pere de 20 : ";
    a->affichageNoeud();
    cout << endl;

    Noeud* b = test.getNoeudOncle(7);
    cout << "Oncle de 0 : ";
    b->affichageNoeud();
    cout << endl;

}