#ifndef class_rev_H
#define class_rev_H
#include <string>
using namespace std;


class Salarie{
    private:
    string nom;
    string poste; 
    double salaire ;

    public:
    
    Salarie(string n , string p, double s);
    string getPoste() const;
    string getNom() const;
    double getSalaire() const;
    void setPoste(const string& nouveau_poste);
    void comparerSalaire(const Salarie& employe1, const Salarie& employe2);
    void calculerPrime() const;



};





#endif