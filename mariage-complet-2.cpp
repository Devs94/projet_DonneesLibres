#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "tableau-donnees.h"
#include "tableau-lecture.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> annees = {"2010", "2011", "2012", "2013", "2014", "2015"};
vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> creeTableauAnnee(vector<vector<string>> data) {
    vector<int> tab_annees;
    tab_annees = vector<int>(annees.size());
    vector<vector<string>> data_annee_choisi;
        
    for (int i = 0; i < tab_annees.size(); i++) {
        data_annee_choisi = selectLignes(data, 0, annees[i]);
        tab_annees[i] += somme(conversionInt(colonne(data_annee_choisi, 2)));
    }
    
    return tab_annees;
}

/** Test de la fonction CreeTableauAnnee **/
void testCreeTableauAnnee() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauAnnee(data);
    ASSERT(t[0] == 9195); // Nombre de mariages en 2010
    ASSERT(t[3] == 9443); // Nombre de mariages en 2013
    ASSERT(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractères contenant un jour de la semaine (première lettre en majuscule)
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

/** Construction du tableau des mariages à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * suivi d'un jour, puis d'un nombre de mariages
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> creeTableauJours(vector<vector<string>> data) {
    vector<int> tab_jours;
    tab_jours = vector<int>(jours.size());
    vector<vector<string>> data_jour_choisi;
    
    for (int i = 0; i < tab_jours.size(); i++) {
        data_jour_choisi = selectLignes(data, 1, jours[i]);
        tab_jours[i] += somme(conversionInt(colonne(data_jour_choisi, 2)));
    }
    
    
    return tab_jours;
}

/** Test de la fonction litTableauJours **/
void testCreeTableauJours() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauJours(data);
    ASSERT(t[0] == 4171); // Nombre de mariages le lundi
    ASSERT(t[3] == 4393); // Nombre de mariages le jeudi
    ASSERT(t[6] == 2); // Nombre de mariages le dimanche
}


/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    testCreeTableauAnnee();
    testCreeTableauJours();
    vector<vector<string>> tableau_fichier = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> annees_nbres = creeTableauAnnee(tableau_fichier);
    int annee_max = indiceMax(annees_nbres);
    vector<int> jours_nbres = creeTableauJours(tableau_fichier);
    int jour_max = indiceMax(jours_nbres);
    double prctg_samedi = 100.0 * jours_nbres[indiceJour("Samedi")]/somme(conversionInt(colonne(tableau_fichier, 2)));
    
    cout << "Le nombre total de mariages entre 2010 et 2015 est : " << somme(conversionInt(colonne(tableau_fichier, 2))) << endl;
    cout << "Il y a en moyenne " << moyenne(conversionInt(colonne(tableau_fichier, 2))) << " mariages célébrés par an" << endl;
    cout << "L'année où l'on a célébré le plus de mariages est " << annees[annee_max] << " avec " << annees_nbres[annee_max] << " mariages" << endl;
    cout << "Le jour où on célèbre le plus de mariages est le " << jours[jour_max] << " avec " << jours_nbres[jour_max] << " mariages" << endl;
    cout << "Le pourcentage de mariages célébrés un samedi est " << prctg_samedi << "%" << endl;
    
    
    return 0;
}
