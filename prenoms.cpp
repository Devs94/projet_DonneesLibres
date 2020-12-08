#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là **/
int main() {
    int annee_utilisateur, annee, nombre;
    int total = 0;
    int prenom_max_occ = 0;
    char sexe;
    string prenom, max_prenom;
    
    cout << "Entrez une année entre 2014 et 2019 : " << endl;
    cin >> annee_utilisateur;
    
    ifstream fichier;
    fichier.open("donnees/liste_des_prenoms.txt");
    
    while (fichier >> sexe >> annee >> prenom >> nombre) {
        if (annee == annee_utilisateur) {
            total += nombre;
            if (nombre > prenom_max_occ) {
                prenom_max_occ = nombre;
                max_prenom = prenom;
            }
        }
        
    }
    
    
    cout << "En " << annee_utilisateur << ", il y a eu : " << total << " naissances."<< endl;
    cout << "Le prénom le plus donnée a été : " << max_prenom << " (donnée " << prenom_max_occ << " fois)" << endl;
    
    
    return 0;
}
