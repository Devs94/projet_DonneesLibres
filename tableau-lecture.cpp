#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.h"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    string element;
    vector<vector<string>> tableau_fichier;
    ifstream fichier;
    fichier.open(nom_fichier);
    
    while (fichier) {
        for (int j = 0; j < nb_colonnes; j++) {
            if (fichier >> element) {
                if (j % nb_colonnes == 0) {
                    tableau_fichier.push_back({});
                }
                tableau_fichier[tableau_fichier.size() - 1].push_back(element);
            }
            
        }
    }
    
    fichier.close();
    
    return tableau_fichier;
}
