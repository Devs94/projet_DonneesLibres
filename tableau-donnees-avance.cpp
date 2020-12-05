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
    vector<int> tab_grp_int = vector<int>(valeurs.size());
    int entier;
    
    for (int i = 0; i < valeurs.size(); i++) {
        for (int ligne = 0; ligne < data.size(); ligne++) {
            //j1 : colonne des critères
            if (data[ligne][j1] == valeurs[i]) {
                //j2 : colonne des valeurs à traiter
                istringstream(data[ligne][j2]) >> entier;
                tab_grp_int[i] += entier;
            }
        }
    }
    
    
    return tab_grp_int;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
vector<double> tab_grp_double = vector<double>(valeurs.size());
    double dbl;
    
    for (int i = 0; i < valeurs.size(); i++) {
        for (int ligne = 0; ligne < data.size(); ligne++) {
            //j1 : colonne des critères
            if (data[ligne][j1] == valeurs[i]) {
                //j2 : colonne des valeurs à traiter
                istringstream(data[ligne][j2]) >> dbl;
                tab_grp_double[i] += dbl;
            }
        }
    }
    
    
    return tab_grp_double;
}

template<class T>
vector<T> conversion(vector<string> t) {
    vector<T> resultat = vector<T>(t.size());
    for (int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    
    return resultat;
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<T> tab_grp_type = vector<T>(valeurs.size());
    T type_val;
    
    for (int i = 0; i < valeurs.size(); i++) {
        for (int ligne = 0; ligne < data.size(); ligne++) {
            //j1 : colonne des critères
            if (data[ligne][j1] == valeurs[i]) {
                //j2 : colonne des valeurs à traiter
                istringstream(data[ligne][j2]) >> type_val;
                tab_grp_type[i] += type_val;
            }
        }
    }
    
    
    return tab_grp_type;
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
