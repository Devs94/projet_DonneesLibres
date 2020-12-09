#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.h"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream fichier(nom_fichier);
    string ligne, element;
    vector<vector<string>> tableau2D;
    
    while (getline(fichier, ligne)) {
        tableau2D.push_back({});
        for (int i = 0; i < (nb_colonnes - 1); i++) {
            tableau2D[tableau2D.size() - 1].push_back(element);
        }
    }

    
    
    return tableau2D;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    ifstream fichier(nom_fichier);
    string ligne, element;
    vector<vector<string>> tableau2D;
    

    
    return tableau2D;
}



