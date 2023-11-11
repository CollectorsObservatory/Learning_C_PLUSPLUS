#ifndef week10_review_H
#define week10_review_H

#include <string>
using namespace std;



class Point {
    private:
    double x;
    double y;
    public:
    Point(double w, double z);
    void afficher();
    void deplacer(double dx, double dy);

};



class CompteBancaire{
    private : 
    double solde; 
    string titulaire; 
    public :
    CompteBancaire(double s, string t);
    void deposerArgent(double montant);
    void retirerArgent(double montant);
    void afficherSolde();
    

};

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
class Human{
    
    private:
    string name; 
    string gender; 
    double height;
    double weight ;
    
    public:
    Human(string n, string g, double h, double w);
    string getName() const;
    string getGender() const;
    double getHeight() const;
    double getWeight() const;
    void setName(string new_name);
    void setWeight(double new_weight);
    void displayInfo();
    void compareHeights(const Human& human1, Human& human2);
    void Speed() const;
    bool checkFormat();


};

#endif