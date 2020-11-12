#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivi d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> litTableauAnnee(string nom_fichier) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauAnnee non implantée ligne 24");
}

/** Test de la fonction litTableauAnnee **/
void testLitTableauAnnee() {
    vector<int> t = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    ASSERT(t[0] == 9195); // Nombre de mariages en 2010
    ASSERT(t[3] == 9443); // Nombre de mariages en 2013
    ASSERT(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractère contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    ASSERT(indiceJour("Lundi") == 0);
    ASSERT(indiceJour("Samedi") == 5);
    ASSERT(indiceJour("Dimanche") == 6);
    ASSERT(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages par jour
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivie d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> litTableauJours(string nom_fichier) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauJours non implantée ligne 65");
}

/** Test de la fonction litTableauJours **/
void testLitTableauJours() {
    vector<int> t = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    ASSERT(t[0] == 4171); // Nombre de mariages le lundi
    ASSERT(t[3] == 4393); // Nombre de mariages le jeudi
    ASSERT(t[6] == 2); // Nombre de mariages le dimanche
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs du tableau
 **/
int somme(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction somme non implantée ligne 82");
}

/** Test de la fonction somme **/
void testSomme() {
    ASSERT(somme({1,2,3}) == 6);
    ASSERT(somme({}) == 0);
    ASSERT(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 * (on arrondit à l'entier inférieur)
 **/
int moyenne(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction moyenne non implantée ligne 99");
}

/** Test de la fonction moyenne **/
void testMoyenne() {
    ASSERT(moyenne({1,2,3}) == 2);
    ASSERT(moyenne({1}) == 1);
    ASSERT(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction indiceMax non implantée ligne 116");
}

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    ASSERT(indiceMax({}) == -1);
    ASSERT(indiceMax({1,2,3}) == 2);
    ASSERT(indiceMax({1,3,2}) == 1);
    ASSERT(indiceMax({1}) == 0);
    ASSERT(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction main non implantée ligne 137");
}
