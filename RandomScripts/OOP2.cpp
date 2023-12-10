#include <iostream> 
#include <sstream>
#include <memory>


using namespace std;

/* Messing Around with operators , ostringstream and getters */
class Company{
    
    private:

    double m_salary; 
    string m_name;

    public:

    Company(double p_salary, string p_name) : 
    m_name(p_name), m_salary(p_salary) {} ; 

    void reqInfo() const {cout<<m_name << "'s salary is " << m_salary <<endl; }

    string reqName() const {return m_name;}
    double reqSalary() const {return m_salary;}

    bool operator>(const Company& another_employee){return m_salary > another_employee.m_salary;}
    
    bool operator==(const Company& another_employee){return m_salary == another_employee.m_salary;}

    string reqCompanyFormat() const{ 
        ostringstream sortie;
        sortie <<"Employee Information Form" <<endl;
        sortie <<" " << endl;
        sortie <<"Name      :"   << reqName() << endl;
        sortie <<"Salary    :"   << reqSalary() <<endl;
        return sortie.str();
    }


};

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

int incremenet(int& x){
    return x+=1;

}
// Messing around with the rule of three 

class mammal{

    private : 

    // trying to mess around with standard variable and a pointer for practise

    int* m_number_of_legs; 
    string m_name; 

    public:
    // Standard constructor 

    mammal(int p_number_of_legs, string p_name): m_name(p_name), m_number_of_legs(new int(p_number_of_legs))
    {cout<<"mammal was created using default constructor "<<endl;}

    // Copy Constructor 

    mammal(const mammal& other) : m_name(other.m_name), m_number_of_legs(new int(*(other.m_number_of_legs)))
    {cout<<"Copy constructor was called  "<<endl;}

    // Destructor

    ~mammal() {delete m_number_of_legs; cout <<"mammal objecte was destroyed"<<endl;}

    // Assign operator 

    mammal& operator=(const mammal& other){
        if(this!=&other){
            m_name = other.m_name;
            delete m_number_of_legs; // For better management apparently
            m_number_of_legs = new int(*other.m_number_of_legs);
        }
        return *this; 
    }



};

// Messing around with smart pointers , copies and virtual destructors
class animal{

    public :

    animal() {cout <<"An animal is created" <<endl;}
    virtual unique_ptr<animal> clone () const = 0;
    virtual ~animal () {cout <<"Animal object destroyed" <<endl;}
    virtual void walking() {cout <<"Animal is walking" <<endl;}

};
class cat : public animal{

    public: 
    cat() {cout <<"Cat is created" << endl;}

    unique_ptr<animal> clone() const override{
        return  unique_ptr<animal>(new cat(*this));
    }

    void walking() {cout<<"Cat is walking"<<endl;}

    ~cat() {cout<<"Cat objet dead"<<endl;}


};

class Personne{




};





int main() {
    // Messing around with refrences
    int a = 1;
    int b = 2;
    int tempVar; 
    int & pa = a; 
    tempVar = a ;
    int &pb = b; 
    pa = pb; 
    pb = tempVar;

    int z= 0;
    incremenet(z);

    //cout << &z << endl; //& = adress of

    int x = 1 ;
    int y = 2; 
    int tempVar2; 
    int* px = &x; // Pointer that points towards the adress of x
    int* py = &y;
    tempVar2 = *px ; // *px is x , it's telling the pointeur to read the content of the adress
    *px = *py; 
    *py = tempVar2;
    //cout << *px << endl;
    //cout << *py << endl; 

    // Messing Around with overloading of operators


    Company e1(20, "fares");
    Company e2(30, "test");
    e1.operator==(e2); // returned 0 - false
    e1.reqCompanyFormat(); // displayed the right format 

    // Messing around with stack and heap now 

    int e = 5 ; 
    int* pe = &e ;  // classic pointeur
    int* he = new int ;  // reserving a place for an int in the heap
    *he = e;  // putting the value of e in the heap 
    cout << he << endl; // memeory adress in the heap where  e is
    cout << pe << endl; // memory adress of the stack where e is
    cout << *he<< endl; // value of e in the heap

    animal* object(new cat());
    delete object;
    cout << object << endl;

    unique_ptr<animal> smartanimal(new cat());
    smartanimal->walking();

    mammal dog(4, "Dog");

    mammal cat(4, "Cat");

    mammal dog2 = dog;

    dog = cat ; 



    return 0;
}







