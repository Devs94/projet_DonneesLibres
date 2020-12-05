#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-lecture.h"
#include "tableau-donnees.h"
#include "tableau-donnees-avance.h"
using namespace std;


/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> naissances_M_F = groupBy(data, {"M", "F"}, 0, 3);
     cout << "Naissances homme : " << naissances_M_F[0] << endl;
    
    return 0;
}
