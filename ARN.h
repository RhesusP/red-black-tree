//Arbre Rouge et Noir
#ifndef _ARN
#define _ARN
#include "Noeud.h"

class ARN{
    public:
        Noeud* racine;

        /**
         * @brief Constructeur par defaut du module Arbre Noir Rouge.
         * Initialise la racine a NULL.
         */
        ARN();  

        /**
         * @brief Destructeur du module Arbre Noir Rouge.
         * Fait appel a la procedure recursive `vider()` afin de detruire tous les 
         * noeuds de l'arbre depuis la racine.
         */
        ~ARN();
        
        /**
         * @brief Insere un element dans un ARN
         * Fait appel a la procedure recursive `insertionRec` pour inserer l'element 
         * au niveau des feuilles de l'arbre puis appelle la procedure `equilibrage()`
         * pour equilibrer l'arbre. 
         * @param e (Element) L'element a inserer.
         */
        void insertion(const Element &e);

        /**
         * @brief Recherche un element dans un ARN.
         * Fait appel a la fonction recursive `rechercherElement()` afin d'afficher 
         * si l'element est present ou non dans l'arbre en fonction de la valeur de retour 
         * de `rechercherElement`.
         * @param e (Element) L'element recherche.
         */
        void recherche(const Element &e);

        /**
         * @brief Afficher l'ARN
         * Fait appel à la procedure recursive `affichageRec()`.
         */
        void affichage();
        
    
    private:

        /**
         * @brief Accesseur au Noeud parent d'un Noeud
         * Fait appel a la fonction recursive `recherche()` afin de trouver l'element passe en 
         * parametre et son parent.
         * @param node (Noeud*) Le Noeud dont on recherche le parent. 
         * @return Noeud* le noeud parent ou nullptr si le noeud n'a pas de parent. 
         */
        Noeud* getNoeudParent(const Noeud* node);

        /**
         * @brief Accesseur au Noeud grand-parent d'un Noeud.
         * Fait appel a `getNoeudParent()` afin de trouver le grand-parent du Noeud passe en 
         * parametre.
         * @param node (Noeud*) Le Noeud dont on recherche le grand-parent. 
         * @return Noeud* le noeud grand-parent ou nullptr si le noeud n'a pas de grand-parent.
         */
        Noeud* getNoeudGrandParent(const Noeud* node);

        /**
         * @brief Accesseur au Noeud oncle d'un Noeud.
         * Fait appel a `getNoeudOncle()` afin de trouver l'oncle du Noeud passe en parametre.
         * @param node (Noeud*) Le Noeud dont on recherche l'oncle. 
         * @return Noeud* le noeud oncle ou nullptr si le noeud n'a pas d'oncle.
         */
        Noeud* getNoeudOncle(const Noeud* node);

        /**
         * @brief Insere un element dans un ARN.
         * Distingue quatre cas lors de l'insertion d'un element. 
         * 1) L'arbre est vide, l'element est alors insere comme etant la racine (rouge).
         * 2) L'element ajoute est deja present dans l'arbre. Aucune action n'est effectuee.
         * 3) Si l'element est superieur a l'element du noeud passe en parametre, alors on fait un appel recursif 
         * sur le fils droit du Noeud en parametre.
         * 4) Si l'element est inferieur a l'element du noeud passe en parametre, alors on fait un appel recursif 
         * sur le fils gauche du Noeud en parametre. 
         * @param node (Noeud*) Noeud a partir duquel inserer l'element.
         * @param e (Element) l'element a inserer.
         */
        void insertionRec(Noeud *&node, const Element &e);

        /**
         * @brief Equilibre l'ARN suite a une insertion.
         * Gere les differents cas possibles selon la situation du noeud passe en parametre :
         * 1) Le noeud n'a pas de pere (= racine), le noeud est donc colore en noir.
         * 2) Le pere du noeud est noir, l'arbre est donc equilibre et l'on sort de la procedure.
         * 3) Si l'oncle du noeud est rouge, alors on fait appel a la procedure `cas1(node)` qui recolorie les noeuds selon la regle
         * de l'oncle rouge et appelle `equilibrage(grandPere)` afin de verifier l'equilibre de l'arbre au niveau des ancetres.
         * 4) a) Si le noeud est le fils droit de son pere, qui est le fils gauche du grand pere, alors 
         * on fait une rotation gauche sur le pere.
         *    b) Si le noeud est le fils gauche du pere, qui est lui-meme le fils droit du grand-pere, alors on fait
         * une rotation droite sur le pere.
         * Les etapes 4 a) et 4 b) permettent d'aligner les noeud grand-pere, pere et fils a droite ou a gauche.
         * Ensuite, on appelle la procedure `NoeudAlignes(node)` afin de faire la rotation adequate sur les noeuds alignes et de 
         * retrouver l'equilibre de l'arbre.
         * @param node (Noeud*) Le noeud insere.
         */
        void equilibrage(Noeud* node);

        /**
         * @brief Colore les noeuds oncle et pere en noir et le grand-pere en rouge.
         * Colorie les noeuds puis re-appelle la procedure `equilibrage()` sur le grand-pere afin de verifier si l'arbre 
         * est equilibre au niveau des ancetres.
         * @param node (Noeud*) Le noeud insere.
         */
        void casOncleRouge(Noeud* node);

        /**
         * @brief Effectue une rotation droite ou gauche sur des noeuds alignes.
         * Cette procédure est appellée uniquement lorsque le noeud passe en parametre, son pere et son grand-pere sont tous
         * alignes a gauche ou a droite.
         * Suite a l'appel a la rotation adequate, l'arbre est equilibre.
         * @param node (Noeud*) Le noeud sur lequel faire la rotation.
         */
        void NoeudAlignes(Noeud* node);

        /**
         * @brief Effectue une rotation gauche sur un noeud.
         * @param node (Noeud*) Le noeud sur lequel faire la rotation.
         */
        void rotationGauche(Noeud* node);

        /**
         * @brief Effectue une rotation droite sur un noeud.
         * @param node (Noeud*) Le noeud sur lequel faire la rotation.
         */
        void rotationDroite(Noeud* node);

        /**
         * @brief 
         * 
         * @param e 
         * @return Noeud* 
         */
        Noeud* rechercherElement(const Element &e);

        /**
         * @brief Procedure recursive affichant les noeud un par un.
         * Affiche les noeuds de l'arbre grace a un parcours infixe. Les noeuds sont decalés en fonction de leur profondeur 
         * dans l'arbre et son surlignes en fonction de leur couleur.
         * @param n (Noeud*) Noeud a partir d'ou afficher.
         * @param prof (int) Profondeur du noeud
         */
        void affichageRec(Noeud* n, int prof);

        /**
         * @brief Libere l'espace memoire occupe par l'arbre.
         * Effectue un parcours infixe et libere l'espace memoire des feuilles une a une.
         * @param node (Noeud*) Le noeud a partir duquel realiser le parcours.
         */
        void vider(Noeud* node);
};

#endif