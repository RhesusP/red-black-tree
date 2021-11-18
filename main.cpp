#include "ARN.h"
#include "ABR.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cstdio>

using namespace std;

int main(){

    int nbC = 100;          //nombre de collection
    int nbE = 20000;         //nombre d'element


    chrono::time_point<chrono::system_clock> startARN, endARN;
    startARN = chrono::system_clock::now();
    for(int i=0; i<nbC ; i++){
        ARN arbreRougeNoir;
        for(int j=0 ; j<nbE ; j++){
            int random = rand()%1000;
            arbreRougeNoir.insertion(random);
        }
        //cout << "Arbre rouge noir " << i << " :" << endl;
        //arbreRougeNoir.affichage();
    }
    endARN = chrono::system_clock::now();
    int elapsedTimeARN = chrono::duration_cast<chrono::microseconds>(endARN-startARN).count(); 
    float moyenneARN = elapsedTimeARN/nbC;
    cout << "[ARN] Temps moyen pour une insertion de " << nbE << " elements : " << moyenneARN << " microsecondes." << endl;



    chrono::time_point<chrono::system_clock> startABR, endABR;
    startABR = chrono::system_clock::now();
    for(int i=0; i<nbC ; i++){
        ABR arbreRougeNoir;
        for(int j=0 ; j<nbE ; j++){
            int random = rand()%1000;
            arbreRougeNoir.insertion(random);
        }
        //cout << "Arbre rouge noir " << i << " :" << endl;
        //arbreRougeNoir.affichage();
    }
    endABR = chrono::system_clock::now();
    int elapsedTimeABR = chrono::duration_cast<chrono::microseconds>(endABR-startABR).count(); 
    float moyenneABR = elapsedTimeABR/nbC;
    cout << "[ABR] Temps moyen pour une insertion de " << nbE << " elements : " << moyenneABR << " microsecondes." << endl;


    return 0;
}