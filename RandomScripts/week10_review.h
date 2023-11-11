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



#endif