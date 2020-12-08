#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
int main() {
    ifstream fichier("donnees/liste_des_prenoms.csv");
    string ligne;
    string entete;
    getline(fichier, entete);
    
    int annee_utilisateur;
    string nombre, sexe, annee, prenom, max_prenom, nombre_cumul;
    char sexe_;
    int nombre_, annee_, nombre_cumul_;
    int prenom_max_occ = 0;
    int total = 0;

    
    cout << "En-tête : " << entete << endl;
    cout << "Entrer une année entre 2014 et 2019 : ";
    cin >> annee_utilisateur;
    
    while (getline(fichier, ligne)) {
        getline(fichier, nombre, ';');
        getline(fichier, sexe, ';');
        getline(fichier, annee, ';');
        getline(fichier, prenom, ';');
        getline(fichier, nombre_cumul, ';');
        
        istringstream(nombre) >> nombre_;
        istringstream(sexe) >> sexe_;
        istringstream(annee) >> annee_;
        istringstream(nombre_cumul) >> nombre_cumul_;
        
        if (annee_ == annee_utilisateur) {
            total += nombre_;
            if (nombre_ > prenom_max_occ) {
                prenom_max_occ = nombre_;
                max_prenom = prenom;
            }
        }
        
    }
    
    cout << "En " << annee_utilisateur << ", il y a eu : " << total << " naissances."<< endl;
    cout << "Le prénom le plus donnée a été : " << max_prenom << " (donnée " << prenom_max_occ << " fois)" << endl;
    
    
    return 0;
}
