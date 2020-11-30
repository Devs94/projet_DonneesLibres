#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.h"

int chercheIndice(vector<string> t, string valeur) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == valeur) {
            return i;
        }
    }
    return -1;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> tab_dist;
    
    for (int i = 0; i < data[i].size(); i++) {
        if (chercheIndice(tab_dist, data[i][j]) == -1) {
            tab_dist.push_back(data[i][j]);
        }
    }
    
    return tab_dist;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> resultat = vector<double>(t.size());
    for (int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    
    return resultat;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction groupByInt non implantée ligne 24");
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction groupByDouble non implantée ligne 29");
}

template<class T>
vector<T> conversion(vector<string> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction conversion non implantée ligne 35");
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction groupBy non implantée ligne 41");
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
