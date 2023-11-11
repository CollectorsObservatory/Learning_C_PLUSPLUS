#include <iostream>
#include "class_rev.h"
using namespace std; 


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
  





int main(){
    Salarie emp1("john", "technicien", 40000);
    Salarie emp2("Marie", "technicien", 35000);
    emp1.comparerSalaire(emp1, emp2);
    cout << emp1.getNom() << endl;
    emp1.calculerPrime() ;

    return 0;
}