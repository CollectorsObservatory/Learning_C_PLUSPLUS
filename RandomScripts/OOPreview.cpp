#include <iostream>
#include <memory>

using namespace std ; 

class Vehicule{

    private : 

    string m_brand; 
    string m_color ; 

    public: 

    Vehicule(string p_brand,string p_color) : 
    m_brand(p_brand) , m_color(p_color) {};

    virtual void showInfo() {
        cout << "Vehicle brand is: " << m_brand << " color is " << m_color << endl; 
    }

    virtual unique_ptr <Vehicule> clone () const = 0; 

    virtual ~Vehicule() {cout <<"Vehicule Destroyed" <<endl;}
   

};

class Truck : public Vehicule{

    private : 
    int m_torque;

    public: 

    Truck(string p_brand,string p_color, int p_torque) : 
    Vehicule(p_brand, p_color), m_torque(p_torque) {} ; 

    void showTruckInfo(){
         Vehicule ::showInfo() ;
          cout << "Torque in NM is " << m_torque <<endl;
 
   }
   virtual unique_ptr <Vehicule> clone () const {
       return unique_ptr<Truck>(new Truck(*this));

   }
 
   ~Truck() {cout <<"Truck Destroyed" <<endl;}

};



int main() {
    Truck truck1("ford", "black", 1200);
    truck1.showTruckInfo();
    


    return 0;
}
