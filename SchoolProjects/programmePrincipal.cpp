/**
 * \file programmePrincipal.cpp
 * \brief  Programme ...
 * \author Thierry Eude
 * \version 0.1
 */


#include <iostream>
# include <array>
#include "fonctionsUtilitaires.h"


using namespace std;



int main ()
{
  array<array<int, MAX_VALEURS>, MAX_CAS> tabValeurs;
  cout << "Saisissez des nombres séparés par des entrées " << endl;

  int register1;
  for (int i = 0; i < MAX_CAS; ++i)
    {
      for (int j = 0; j < MAX_VALEURS; ++j)
        {
          cin >> register1;
          tabValeurs[i][j] = register1;
        }
      cout << endl;
    }

  cout << "nombres saisis :" << endl;
  afficherTableau (tabValeurs, MAX_CAS);
  tri2d (tabValeurs);
  cout << "nouveau contenu du tableau :" << endl;
  afficherTableau (tabValeurs, MAX_CAS);
  cout << "saisir la valeur seuil :" << endl;
  int seuil;
  cin >> seuil;
  float taux;
  int cardinalite = MAX_VALEURS * MAX_CAS;
  
  taux = (occurencesPlusGrand(tabValeurs, MAX_CAS, seuil) / cardinalite) * 100;


  cout << "il y a " << taux << " pourcent de nombres plus grands que "
          << seuil << " dans le tableau de valeurs" << endl;

  //ceci est un test
  //	seuil = seuil * taux;
  //	cout << seuil << endl;

  return 0;
}

