#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.h"

int chercheIndice(vector<string> t, string valeur) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction chercheIndice non implantée ligne 9");
}

vector<string> distinct(vector<vector<string>> data, int j) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction distinct non implantée ligne 14");
}

vector<double> conversionDouble(vector<string> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction conversionDouble non implantée ligne 19");
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
