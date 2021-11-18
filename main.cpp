#include "ARN.h"
#include <iostream>

using namespace std;

int main(){

    ARN arbre;

    for(int i=0 ; i<20 ; i++){
        cout << endl << endl << "Insertion de " << i << endl;
        arbre.insertion(i);
        arbre.affichage();
    }

    cout << "------------------------------------------------------------" << endl;
/*
    ARN test;
    test.insertion(30);
    test.affichage();
    test.insertion(10);
    test.affichage();
    test.insertion(7);
    test.affichage();   
    test.insertion(4);
    test.affichage();
    test.insertion(3);
    test.affichage();
    test.insertion(1);
    test.affichage();
    test.insertion(6);
    test.affichage();
    test.insertion(9);
    test.affichage();
    test.insertion(40);
    test.affichage();
    test.insertion(60);
    test.affichage();
*/
    return 0;
}