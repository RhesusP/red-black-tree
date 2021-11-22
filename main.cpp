#include "ARN.h"
#include "ABR.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cstdio>
#include <fstream>

using namespace std;

int main(){
    ofstream flux("./perfs_insertion.txt");
    if(flux){
        flux << "# \"nb elmt\" \"Temps ABR (microsecondes)\" \"Temps ARN (microsecondes)\"" << endl;
        int nbC = 100;               //nombre de collection (arbre)
        int nbEMin = 0;              //nombre d'elements min / max
        int nbEMax = 25000;

        for(int i=nbEMin ; i<nbEMax+100 ; i+=1000){
            flux << i << " ";
            chrono::time_point<chrono::system_clock> startARN, endARN;
            startARN = chrono::system_clock::now();
            for(int j=0; j<nbC ; j++){
                ARN arbreRougeNoir;
                for(int k=0 ; k<i ; k++){
                    int random = rand()%1000;
                    arbreRougeNoir.insertion(random);
                }
                //arbreRougeNoir.affichage();
            }
            endARN = chrono::system_clock::now();
            int elapsedTimeARN = chrono::duration_cast<chrono::microseconds>(endARN-startARN).count(); 
            float moyenneARN = elapsedTimeARN/nbC;
            flux << moyenneARN << " ";
            cout << "[ARN] Temps moyen pour une insertion de " << i << " elements : " << moyenneARN << " microsecondes." << endl;

            chrono::time_point<chrono::system_clock> startABR, endABR;
            startABR = chrono::system_clock::now();
            for(int j=0; j<nbC ; j++){
                ABR arbreBinaire;
                for(int k=0 ; k<i ; k++){
                    int random = rand()%1000;
                    arbreBinaire.insertion(random);
                }
                //arbreBinaire.affichage();
            }
            endABR = chrono::system_clock::now();
            int elapsedTimeABR = chrono::duration_cast<chrono::microseconds>(endABR-startABR).count(); 
            float moyenneABR = elapsedTimeABR/nbC;
            flux << moyenneABR << endl;
            cout << "[ABR] Temps moyen pour une insertion de " << i << " elements : " << moyenneABR << " microsecondes." << endl;
            cout << "--------------------------------------------------------------------------------------------------" << endl;
        }
    }
    else{
        cout << "ERREUR : impossible d'ouvrir le fichier." << endl;
    }

    cout << endl << endl << "Detail insertion successive de 20 elements (de 0 à 19)" << endl << endl;
    ARN arbreBicolore;
    for(int i=0 ; i<20 ; i++){
        arbreBicolore.insertion(i);
        cout << endl << "Insertion de " << i << endl;
        arbreBicolore.affichage();
    }
    
    cout << endl << endl << "Comparaison du resultat avec un insertion dans un ABR" << endl << endl;
    ABR arbreBinaire;
    for(int i=0 ; i<20 ; i++){
        arbreBinaire.insertion(i);
    }
    arbreBinaire.affichage();

    cout << endl << "--------------------------------------------------------------------------------------------------" << endl;
    arbreBicolore.recherche(5);
    arbreBicolore.recherche(99);

    return 0;
}