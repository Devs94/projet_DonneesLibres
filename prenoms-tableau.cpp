#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau) {
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau[i].size(); j++) {
            cout << tableau[i][j] << " ";
        }
        cout << endl;
    }
}

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/
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

/** Test de la fonction litTableau **/
void testLitTableau() {
    ASSERT(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    ASSERT(t.size() == 20453);
    ASSERT(t[0][0] == "M");
    ASSERT(t[5][2] == "Aboubacar");
    ASSERT(t[6][3] == "7");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/
vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> j;
    j = vector<string>(t.size());
    for (int ligne = 0; ligne < j.size(); ligne++) {
        j[ligne] = t[ligne][i];
    }
    
    return j;
}

/** Test de la fonction colonne **/
void testColonne() {
    ASSERT(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    ASSERT(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    ASSERT(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    ASSERT(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    ASSERT(conversionInt({}) == vector<int>({}));
    ASSERT(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int total = 0;
    for (int x: t) {
        total += x;
    }
    
        return total;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
   return somme(t)/t.size();
}

/** copier la fonction indiceMax déjà écrite **/
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

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/
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

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    ASSERT(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    ASSERT(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"},
                                                                           { "F", "2011", "Babouche", "7"},
                                                                           { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    //testAfficheTableau();
    testLitTableau();
    testColonne();
    testConversionInt();
    testSelectLignes();
    
    string prenom;
    vector<vector<string>> tab_fichier = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> tab_naissances = conversionInt(colonne(tab_fichier, 3));
    cout << "Entrez un prénom : ";
    cin >> prenom;
    vector<vector<string>> tab_prenom = selectLignes(tab_fichier, 2, prenom);
    vector<vector<string>> tab_prenom_M = selectLignes(tab_prenom, 0, "M");
    vector<vector<string>> tab_prenom_F = selectLignes(tab_prenom, 0, "F");
    int indice_annee_max = indiceMax(conversionInt(colonne(tab_prenom, 3)));
    vector<string> annees = colonne(tab_prenom, 1);
    string annee_max = annees[indice_annee_max];
    vector<int> nombres_prenom_max = conversionInt(colonne(tab_prenom, 3));
    int prenom_enfants_max = nombres_prenom_max[indice_annee_max];

    cout << "Nombre total de naissances : " << somme(tab_naissances) << endl;
    if (tab_prenom_M == tab_prenom) {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom, 3))) << " garçons entre 2004 et 2019" << endl;
    } else if (tab_prenom_F == tab_prenom) {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom, 3))) << " filles entre 2004 et 2019" << endl;
    } else {
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom_M, 3))) << " garçons entre 2004 et 2019" << endl;
        cout << "Le prénom " << prenom << " a été donné à " << somme(conversionInt(colonne(tab_prenom_F, 3))) << " filles entre 2004 et 2019" << endl;
    }
    cout << "L'année la plus forte est " << annee_max << " avec " << prenom_enfants_max << " enfants" << endl;
    
    
    return 0;
}
