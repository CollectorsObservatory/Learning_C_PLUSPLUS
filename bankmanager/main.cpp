#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

int random_number() {
        long long randomCode = 1 + rand() % 9; // Generate the first digit (1-9)
    for (int i = 1; i < 12; ++i) {
        randomCode = randomCode * 10 + rand() % 10; // Generate the remaining digits (0-9)
    }
    return randomCode;
}

class BankAccount {

private:

    string holdername;
    string gender;
    double balance;
    

    

public:
    int number;
    // initializing the BankAccount constructor
    BankAccount(string hn, double b, int n, string g) {
        holdername = hn;
        balance = b;
        number = random_number();
        gender = g;
    }

    void create_account(string holdername, string gender) {
        if (gender == "m" || gender == "M") {
            cout << " " << endl;
            cout << "Mr " << holdername << " has successfully created his bank account" << endl;
            cout << " " << endl;
            cout << "account balance is 0$" << endl;
            cout << " " << endl;
            cout << "account number is: " << number;
            cout << " " << endl;
        } else if (gender == "f" || gender == "F") {
            cout << "Ms " << holdername << " has successfully created her bank account" << endl;
            cout << " " << endl;
            cout << "account balance is 0$" << endl;
            cout << " " << endl;
            cout << "account number is: " << number;
            cout << " " << endl;
        }
    }
    void deposit_money(double amount){
        if (amount == 0){
            cout << " " << endl;
            cout << "Sorry you can not deposit 0 or less!"<<endl;
        }else{
            double new_balance = balance + amount;
            cout << " " << endl;
            cout << amount << "Has been deposited successfully to account number: " << number << endl;
            cout << " " << endl;
            cout <<"New account balance is: " << new_balance << "$" <<endl; 
            cout << " " << endl;
        }
    }
    void withdraw_money(double amount){
        if (amount > balance){
            cout << "Sorry you can not withdraw more than your balance that is: " << balance << "$" <<endl;
        }else{
            double new_balance = balance - amount;
            cout << "You succesfully withdrawed " << amount << "$" <<endl;
            cout<< "Your new balance is: "<< new_balance << "$" << endl;
        }
    }
    void view_information(int number){
        cout << "Account number: " << number <<endl;
        cout << "Belong to:  " << holdername << endl;
    }
};

class UniversalBankInfo {
    private:

    int account_number ;
    string holder_name; 
    double balance; 

    public:

    UniversalBankInfo(int ac, string hn, double b){
        account_number = ac;
        holder_name = hn; 
        balance = b;
    }
    void display_info(){
        cout << account_number << endl;
        cout << holder_name << endl;
        cout << balance <<endl;
    }
    void special_display(int number){
        cout << holder_name <<endl;
        cout << balance << endl;
    }

};



int main() {
        cout << " " << endl;
        cout <<"Welcome to iBankManager - Your Digital Banking Assistant" <<endl;
        cout << " " << endl;
        cout << "Choose an option " << endl;
        cout << " " << endl;
        cout << "C. Create Account " << endl;
        cout << " " << endl;
        cout << "D. Deposit Money" << endl;
        cout << " " << endl;
        cout << "W. Withdraw Money" << endl;
        cout << " " << endl;
        cout << "I. View Account Information" << endl;
        cout << " " << endl;
        cout << "X. Exit " << endl;
        cout << " " << endl;  

        string choice; 
        string fullname;
        string gender; 
        BankAccount new_account(fullname, 0, random_number(), gender);
        UniversalBankInfo new_account_i(random_number(), fullname, 0.0);

    while (true){

        cout <<"Enter your chosen option in this field: " ;
        cin >> choice ;

        if (choice == "c" || choice == "C"){
            
            cout << "Enter your full name: " ;
            cin.ignore();
            getline(cin, fullname);
            cout << "Enter the client's gender: " ;
            cin >> gender; 

           
            new_account_i.display_info();
            new_account.create_account(fullname, gender);
            cout << " " <<endl;
            

        }else if (choice == "d" || choice == "D"){
            int number; 
            cout<< "Enter account number: " ; 
            cin >> number; 
            new_account_i.special_display(number);

            
        }else if (choice == "w" || choice == "W"){
        
        }else if (choice == "i" || choice == "I"){
        
        }else if (choice == "x" || choice == "X"){
            cout << "Closing the program..." << endl;
            cout << "See you soon" << endl;
            break;
    }
        }

    return 0;}
