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
    
    while (fichier) { 
        for (int i = 0; i < nb_colonnes; i++) {
            if (getline(fichier, element, ';')) {
                if (i % nb_colonnes == 0) {
                    tableau2D.push_back({});
                }
                tableau2D[tableau2D.size() - 1].push_back(element);
            }
        }
    }

    
    
    return tableau2D;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    ifstream fichier(nom_fichier);
    string ligne, element;
    vector<vector<string>> tableau2D;
    
    while (getline(fichier, ligne)) {
        tableau2D.push_back({});
        while (getline(fichier, element, ';')) {
            tableau2D[tableau2D.size()-1].push_back(element);
        }
    }
    
    return tableau2D;
}



