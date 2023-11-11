#include <iostream>
#include "week10_review.h"
using namespace std;

/**
 * This file serves to review what i may have missed after my bad performance in the mid-term. Mainly about .h files , certain
 *  elements of classes and OOP in c++ in general.
 * Points are how to divide a class in a cpp , and .h files , getters and setters and some more points
 */



Point:: Point(double w ,double z) : x(w), y(z){};
    void Point::afficher(){
        cout << x << y << endl;
    }
    void Point::deplacer(double dx, double dy){
        x += dx;
        y += dy;
    }


CompteBancaire :: CompteBancaire(double s, string t) : solde(s), titulaire(t){};
    void CompteBancaire::deposerArgent(double montant){
        solde += montant ;
    }
    void CompteBancaire::retirerArgent(double montant){
        if (montant <= solde) {
            solde -= montant ;
        }else {
            cout << "Tu ne peux pas avoir un solde négatif" <<endl;
        }
    }
    void CompteBancaire::afficherSolde(void){
        cout << "le solde du compte est "<< solde << endl;
    }

Salarie  :: Salarie (string n , string p, double s) : nom(n), poste(p), salaire(s) {};


    // déclaration des accesseurs
    string Salarie::getPoste() const{
        return poste;
    }
    string Salarie::getNom() const{
        return nom;
    }
    double Salarie::getSalaire() const{
        return salaire; 
    }

    // déclaration des mutateurs - Juste pour changer des postes

    void Salarie::setPoste(const string& nouveau_poste){
        poste = nouveau_poste;
    }

    // Méthode pour comparer deux salaires
    void Salarie::comparerSalaire(const Salarie& employe1, const Salarie& employe2){

        if(employe1.getSalaire() > employe2.getSalaire()){
            cout<< employe1.getNom() << " a un salaire plus élevé" << endl;

        }else if(employe2.getSalaire() > employe1.getSalaire()){
             cout<< employe2.getNom() << " a un salaire plus élevé" << endl;
        }else{
            cout << "Les deux employés ont le meme salaires" << endl;
        }
    }
    // Méthode qui calcule les primes en fonction du poste 
    void Salarie::calculerPrime() const{
        double prime = 0.0;
        if (poste == "technicien"){
            prime = salaire* 0.05;
            
        }else if(poste =="directeur"){
            prime = salaire * 0.10;
        }else{
            cout << "Poste inexistant" <<endl;
        }
        cout <<"Prime de " << nom << " est de " <<prime <<endl;

    }
  
Human::Human(string n, string g, double h, double w) : name(n), gender(g), height(h), weight(w) {};
    string Human::getName() const {return name;}
    string Human::getGender() const {return gender;}
    double Human::getHeight() const{return height;}
    double Human::getWeight() const {return weight;}
    void Human::setName(string new_name){name = new_name;}
    void Human::setWeight(double new_weight) { weight = new_weight;}
    void Human::displayInfo(){ cout << "This human is called "<< name << " is a " << gender << " and has a height and weight respectively of " << height << " " << weight <<endl;}

    void Human::compareHeights(const Human& human1, Human& human2){
        if (human1.getHeight() > human2.getHeight()){
            cout << "The tallest between the two is " << human1.getName() << endl;
        } else if(human2.getHeight() > human1.getHeight()){
            cout << "The tallest between the two is " << human2.getName() << endl;
        } else{
            cout <<"Probably same height" << endl;
        }
    }
    void Human::Speed() const{
        short int speed;
        if(gender == "male"){
            speed = 20;
            cout << "Speed of " << name <<" is " << speed << endl;
        }else if(gender == "female"){
            speed = 15; 
            cout << "Speed of " << name <<" is " << speed << endl;
        }else {
            cout <<"There are only two options , male or female" << endl;
        }

    }
     
    bool Human::checkFormat(){
        if (gender == "male" || gender == "female") return true;
        for (int i=0; i<name.size(); i++){
            if (! isalpha(name[i])) return false;
        }

        return true;

    }





int main(){
    CompteBancaire nouveau_compte(2000, "fares");
    nouveau_compte.afficherSolde();

    Salarie emp1("john", "technicien", 40000);
    Salarie emp2("Marie", "technicien", 35000);
    emp1.comparerSalaire(emp1, emp2);
    cout << emp1.getNom() << endl;
    emp1.calculerPrime() ;

    Human h1("fares", "male", 175, 65);
    Human h2("Julia", "female", 165, 55);
    h1.compareHeights(h1, h2);
    h1.Speed();
    h2.Speed();
    if(h1.checkFormat()) cout <<"Good job" << endl;
    if (! h1.checkFormat()) cout <<"Damn it" << endl;
    cout<< h1.getGender() << endl;



    return 0;
}