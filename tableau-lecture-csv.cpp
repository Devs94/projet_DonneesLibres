#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.h"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    string element;
    vector<vector<string>> tableau2D;
    
    fichier.open(nom_fichier);
    
    while (fichier) {
        tableau2D.push_back({});
        for (int i = 0; i < nb_colonnes; i++) {
            getline(fichier, element, ";");
            tableau2D[tableau2D.size()-1].push_back(element);
        }
    }
    
    return tableau2D;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauCSV non implantée ligne 16");
}



