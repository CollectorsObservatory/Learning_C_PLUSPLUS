#include <iostream>
#include <string>

using namespace std;

// trying to use destructors and the key word this

class Name {
private:
    string name;

public:
    Name(string name) {
        this->name = name;
        int length = name.size() - 1;
        cout << "The length of your name is " << length << endl;
    }

    
    void setName(string name) {
        this->name = name; // name here has the name var name as the var name
        // in the private section but it has different use
    }

    void printName() {
        cout << "New Name is: " << name << endl;
    }

    ~Name() {
        cout << "Object Destroyed" << endl;
    }
};
// applying this and testing const in methods for safe reading
class Cryptowallet{

    private :
    double balance ; 

    public:

    Cryptowallet(double balance){ // conlict between variable and constructor name - using this
        this->balance = balance ;
    }

    void obtainbalance() const{
        // using const will prevent obtainbalance from changing
        cout << "Wallet confirmed, Balance is" << endl;
        cout<< balance<< endl;
    }

    void depositamount(double amount){
        balance += amount;
        cout << amount << " has been deposited" << endl; 
        cout << balance << " New balance" << endl;

    }

};


// testing static , that is a function that can be called
// without the creation of an object inside a class
class Math{

    public:

    void static add(int a, int b){
        cout << a + b << endl;
    }

};

void testing_math(){
    
      Math::add(1,2);

};
void testing_class_name(void){

    string userName;
    cout << "Enter your name: " << endl;
    getline(cin, userName);
    Name user(userName);

    user.setName("Test Test");
    user.printName();
};


void testing_crypto(){

    double balance ;
    string choice;

    cout << "Enter balance to create wallet: " << endl;
    cin >> balance ; 

    Cryptowallet new_wallet(balance);
    new_wallet.obtainbalance();

    cout << "Do you want to deposit more money?" << endl ;
    cin >> choice ;

    if (choice == "yes"){

        double deposit ; 
        cout << "Enter the amount " << endl;
        cin >> deposit ; 
        new_wallet.depositamount(deposit);

    }else if (choice == "no"){

        cout << "existing program" << endl;}

}

int main(void) {

    testing_class_name();
    testing_crypto();
    testing_math();
   
}
