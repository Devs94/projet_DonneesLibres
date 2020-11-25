#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre de mariages un samedi entre 2010 et 2015 **/
int main() {
    int somme = 0;
    int annee, nombre;
    string jour;
    
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    
    while (fichier >> annee >> jour >> nombre) {
        if (jour == "Samedi") {
            somme += nombre;
        }
    }
    fichier.close();
    
    cout << "Nombre total de mariages entre 2010 et 2015 : " << somme << endl;

    return 0;
}
