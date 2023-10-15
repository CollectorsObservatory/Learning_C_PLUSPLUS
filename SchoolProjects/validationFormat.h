/**
 * @file validationFormat.h
 * @author CollectorsObservatory
 * @date 2023-10-15
 *
 * @brief Ce fichier d'en-tête déclare des fonctions pour la validation des formats de numéros de téléphone et RAMQ.
 *
 * Il déclare des fonctions qui aident à vérifier la validité des formats de numéros en se basant sur des règles
 * spécifiques. Les règles comprennent la longueur correcte, les caractères autorisés et le format général des numéros.
 * Les constantes nécessaires pour la validation, telles que la longueur et le nombre de codes régionaux, sont également définies.
 *
 */
#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <string>
#include <array>

static const int LONGUEUR_NUM_TELEPHONE = 12;
static const int NOMBRE_CODES_REGIONAUX = 40;
static const int LONGUEUR_NUM_RAMQ = 12;

bool validerFormatTelephone(const std::string& p_telephone);

bool validerFormatNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);

bool isdigit(char d);

bool isalpha(char c);

#endif /* VALIDATION_H_ */
