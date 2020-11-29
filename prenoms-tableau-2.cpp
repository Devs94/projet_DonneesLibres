#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
#include "tableau-lecture.h"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    string prenom;
    vector<vector<string>> tab_fichier = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> tab_naissances = conversionInt(colonne(tab_fichier, 3));
    cout << "Entrez un prénom : ";
    cin >> prenom;
    vector<vector<string>> tab_prenom = selectLignes(tab_fichier, 2, prenom);
    vector<vector<string>> tab_prenom_M = selectLignes(tab_prenom, 0, "M");
    vector<vector<string>> tab_prenom_F = selectLignes(tab_prenom, 0, "F");
    int indice_annee_max = indiceMax(conversionInt(colonne(tab_prenom, 3)));
    vector<string> annees = colonne(tab_prenom, 1);
    string annee_max = annees[indice_annee_max];
    vector<int> nombres_prenom_max = conversionInt(colonne(tab_prenom, 3));
    int prenom_enfants_max = nombres_prenom_max[indice_annee_max];

    cout << "Nombre total de naissances : " << somme(tab_naissances) << endl;
    if (tab_prenom_M == tab_prenom) {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom, 3))) << " garçons entre 2004 et 2019" << endl;
    } else if (tab_prenom_F == tab_prenom) {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom, 3))) << " filles entre 2004 et 2019" << endl;
    } else {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom_M, 3))) << " garçons entre 2004 et 2019" << endl;
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom_F, 3))) << " filles entre 2004 et 2019" << endl;
    }
    cout << "L'année la plus forte est " << annee_max << " avec " << prenom_enfants_max << " enfants" << endl;
    
    
    return 0;
}
