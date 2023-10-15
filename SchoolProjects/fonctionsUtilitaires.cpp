/**
 * \file fonctionsUtilitaires.cpp
 * \brief
 * \author Thierry Eude
 */
#include <iostream>
#include "fonctionsUtilitaires.h"
# include <array>
using namespace std;

/**
 * \brief tri à bulle du tableau d'entiers passé en paramètre
 * \param[in] int tabDonnees un tableau d'entiers à trier
 */
void triBulle (array<int, MAX_VALEURS>& tabDonnee)
{
  bool echange = true;
  int i, j, temp;
  for (i = 0; (i < MAX_VALEURS) && echange; i++)
    {
      echange = false;
      for (j = 0; j < (MAX_VALEURS - 1); j++)
        {
          if (tabDonnee[j + 1] > tabDonnee[j])
            {
              temp = tabDonnee[j];
              tabDonnee[j] = tabDonnee[j + 1];
              tabDonnee[j + 1] = temp;
              echange = true;
            }
        }
    }
}


/**
 * \brief tri à bulle du tableau 2d d'entiers passé en paramètre
 * \param[in] tabDonnees[][MAX_VALEURS] un tableau d'entiers à trier
 *  
 */
void tri2d(array<array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees)
{
  int p_nombreLignes = p_tabDonnees.size();
  
  for (int i = 0; i < p_nombreLignes; i++)
    {
      triBulle (p_tabDonnees[i]);
    }
}


/**
 * \brief retourne le nombre de nombres plus grand que la valeur passée en paramètre
 * \param[in] int tabDonnees[][MAX_VALEURS] le tableau de valeurs à traiter
 * \pre chaque ligne du tableau doit être trié en ordre décroissant
 * \param[in]  p_valeur la valeur seuil
 * \pre p_valeur existe dans le tableau
 * \return le nombre de nombres plus grand que la valeur passée en paramètre
 */
float occurencesPlusGrand(const array<array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees, int p_nombreLignes,
                         int p_valeur)
{
    float nombreOccurencesPlusGrand = 0; 
    for (int i = 0; i < p_nombreLignes; ++i)
    {
        int j = 0;
        while (j < MAX_VALEURS && p_tabDonnees[i][j] > p_valeur)
        {
            nombreOccurencesPlusGrand++;
            j++;
        }
    }

    return nombreOccurencesPlusGrand;
}

/**
 * \brief affiche le contenu du tableau
 * \param[in] p_tabDonnees le tableau à afficher
 * \param[in] p_nombreLignes le nombre de lignes que contient le tableau
 */
void afficherTableau (const array<array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees, int p_nombreLignes)
{
  for (int i = 0; i < p_nombreLignes; i++)
    {
      cout << "Ligne " << i + 1 << " : ";
      for (int j = 0; j < MAX_VALEURS; j++)
        {
          cout << "  " << p_tabDonnees[i][j];
        }
      cout << endl;
    }

}
