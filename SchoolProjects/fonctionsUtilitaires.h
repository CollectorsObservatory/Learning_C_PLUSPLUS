/**
 * \file fonctionsUtilitaires.h
 * \brief
 * \author Thierry Eude
 */

#ifndef FONCTIONSUTILITAIRES_H_
#define FONCTIONSUTILITAIRES_H_

#include <array> 

#define MAX_CAS 4
static const int MAX_VALEURS = 4;

void triBulle (std::array<int, MAX_VALEURS>& tabDonnee);
void tri2d(std::array<std::array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees);
float occurencesPlusGrand (const std::array<std::array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees, int p_nombreLignes, int p_valeur);
void afficherTableau (const std::array<std::array<int, MAX_VALEURS>, MAX_CAS>& p_tabDonnees, int p_nombreLignes);


            

#endif /* FONCTIONSUTILITAIRES_H_ */
