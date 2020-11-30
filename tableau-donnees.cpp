#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.h"

void afficheTableau(vector<vector<string>> tableau) {
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau[i].size(); j++) {
            cout << tableau[i][j] << " ";
        }
        cout << endl;
    }
}

int moyenne(vector<int> t) {
   return somme(t)/t.size();
}

int somme(vector<int> t) {
    int total = 0;
    for (int x: t) {
        total += x;
    }
    
        return total;
}


int indiceMax(vector<int> t) {
    if (t.size() == 0) {
        return -1;
    }
    
    int i_max = 0;
    for (int i = 1; i < t.size(); i++) {
        if (t[i_max] < t[i]) {
            i_max = i;
        }
    }
    
    return i_max;
}

vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> j;
    j = vector<string>(t.size());
    for (int ligne = 0; ligne < j.size(); ligne++) {
        j[ligne] = t[ligne][i];
    }
    
    return j;
}


vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for (int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tableau;
    vector<string> col = colonne(t, j);
    for (int i = 0; i < col.size(); i++) {
        if (col[i] == valeur) {
            tableau.push_back(t[i]);
        }
    }
    return tableau;
}
