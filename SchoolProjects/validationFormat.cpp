#include <iostream>
#include "validationFormat.h"
using namespace std;

// pour vérifer si un charatère donné est un entier entre 0 et 9
bool isdigit(char d) {

    if (d == '0' || d == '1' || d == '2' || d == '3' || d == '4' ||
        d == '5' || d == '6' || d == '7' || d == '8' || d == '9') {
        return true;
    } else {
        return false;
    }
}

// pour vérifer si un charatère donné est une lettre dans l'alphabet

bool isalpha(char c) {

    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}


bool validerFormatTelephone(const string& p_telephone) {
    // Validation de la longueur du numéro de téléphone
    if (p_telephone.length() != LONGUEUR_NUM_TELEPHONE) {
        return false;
    }

    // Vérification de la présence des tirets aux positions correctes
    if (p_telephone[3] != '-' || p_telephone[7] != '-') {
        return false;
    }

    // Vérification que les autres caractères sont des chiffres
    for (int i = 0; i < LONGUEUR_NUM_TELEPHONE; ++i) {
        if (i != 3 and i != 7 and !isdigit(p_telephone[i])) {
            return false;
        }
    }

    //Extraire le code régionial
   string codeRegional = p_telephone.substr(0, 3);

    // Vérification des codes de services payants (ceux qui commencent par 9)
    if (codeRegional[0] == '9') {
        return true;
    }


    // Vérification des codes régionaux canadiens valides
    array<string, NOMBRE_CODES_REGIONAUX> codesRegionaux = {
        "403", "780", "604", "236", "250", "778", "902", "204", "431", "506",
        "905", "519", "289", "705", "613", "807", "416", "647", "438", "514",
        "450", "579", "418", "581", "819", "873", "306", "709", "867", "800",
          "866" , "877" , "888", "855", "900", "976" ,"966" };

   bool codeValide = false;
    for (const string& code : codesRegionaux) {
        if (codeRegional == code) {
            codeValide = true;
            break;
        }
    }
    // finalement le retour de la fonction de valisation
    return codeValide;
}


bool validerFormatNumRAMQ(const string& p_numero, const string& p_nom, const string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex) {

    // Enlever les espaces du numéro pour éviter certaines erreures dans le code
    string numero;
    for(char c : p_numero) {
        if(!isspace(c)) numero += c;
    }
    // Vérification du sexe et son validité

    if (!(p_sex == 'M' || p_sex == 'm' || p_sex == 'F' || p_sex == 'f')) {
 
        return false;
    }
    // Pour s'assurer de la bonne longeur du numéro du RAMQ
    if (numero.length() != 12) {
        return false;
    }
    // Construction du numéro RAMQ à partir du nom et prénom
    string expectedStart = "";
    expectedStart += toupper(p_nom[0]);  // convertir les lettres en majuscules aussi pour éviter les erreurs
    expectedStart += toupper(p_nom[1]);
    expectedStart += toupper(p_nom[2]);
    expectedStart += toupper(p_prenom[0]);
  
    if (numero.substr(0, 4) != expectedStart) {  // Vérification si le début du numéro correspond au format attendu 
        return false;
    }
    //Ajouter 50 au mois de naissances des femmes pour valider la condition du RAMQ

    if (p_sex == 'F' || p_sex == 'f') {
        p_moisNaissance += 50;
    }

    char buffer[7];
    // pour formater la date de naissance pour la comparaison 
    sprintf(buffer, "%02d%02d%02d", p_anneeNaissance % 100, p_moisNaissance, p_jourNaissance);
    string dateNaissance(buffer);
    // validation de la date de naissance
    if (numero.substr(4, 6) != dateNaissance) {
        return false;
    }
    // valider que les deux derniers chiffres sont des entiers
     for (int i = 10; i < 12; ++i) {
        if (!isdigit(numero[i])) {
            return false;
        }
    }

    return true;
}
