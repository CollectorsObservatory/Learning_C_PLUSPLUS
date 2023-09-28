# include <iostream>
# include <map>
# include <random>
# include <array>
using namespace std; 


// used to show the maps in bank class 
template <typename Container>
void printElements(const Container& container) {
    for (const auto& element : container) {
        cout << element << endl;
    }
}

// A bank account number generator using Mersenne Twister engine


    // Method to add account - Holder name 
    // Method to display details
    // display all accounts
    //close an account 


class BankAccount{

    private:

    int account_number;
    string holder_name;
    double balance;
    map < int , double> display_balance;
    int account_number_generator() {
        mt19937 mt(static_cast<long unsigned int>(std::time(nullptr)));
        uniform_int_distribution<int> dist(100000000000, 999999999999);
        return dist(mt);
    }

    public:

    BankAccount(int an, string hn, double b){
        account_number = account_number_generator();
        holder_name = hn;
        balance = b;
        
    }
    int account_number_generator(string holder_name){
        mt19937 mt(static_cast<long unsigned int>(std::time(nullptr)));
        uniform_int_distribution<int> dist(100000000000, 999999999999);
        int account_number = dist(mt);
        return account_number;
    }
    void add_acount(){
        cout <<"Holder has the following name"<< holder_name ;
        cout <<holder_name << "'s account's number is" ;
        cout << account_number_generator(holder_name);
    }

    

    double deposit_money(double amount){

        double new_balance = balance + amount;
        return new_balance;
        cout << "We confirm a deposit of " << amount << endl;
    }

    double withdraw_money(double wamount){
        if (wamount > balance){
            cout << "you can only withdraw a maximum of"<< balance;
            return 0;
        }else{
            double new_balance = balance - wamount;
            return new_balance;
            cout << "We confirm a withdrawl of " << wamount << endl;
        }
        
    }

};




int main(void){
    string choice; 
    cout<<" "<<endl;
    cout << "Welcome to iBankManager" << endl;
    cout << " "<< endl;
    cout << "How can i help you today?" << endl;
    cout << " "<< endl;
    cout << "Choose the letter and type it in the terminal" << endl;
    cout << " "<< endl;
    cout << "n - TO OPEN A NEW ACCOUNT" << endl; 
    cout << " "<< endl;
    cout << "d - TO DEPOSIT IN AN ACCOUNT" << endl; 
    cout << " "<< endl;
    cout << "w - TO WITHDRAW MONEY " << endl; 
    cout << " "<< endl;
    cout << "s - TO SHOW ACCOUNT DETAILS" << endl;
    cout << " "<< endl;
    cout << "c - TO CLOSE ACCOUNT" << endl;
    cout << " "<< endl;
    cout << "e - TO EXIT iBankManager" << endl;
    cout << " "<< endl;
    
    while (true){
        cout<<"ENTER YOUR CHOICE: ";
        cin>> choice ;

        if (choice == "n"){
            // add new account

        }else if(choice == "d"){
            // deposit money

        }else if(choice == "w"){
            // withdraw money
            
        }else if(choice == "s"){
            // show account details
            
        }else if(choice == "c"){
            // close an account
            
        }else if(choice == "e"){
             cout << " " << endl; 
            cout << "We hope you had a refined experience , see you soon"<<endl;
            cout << "Closing iBankManger" <<endl; 
            break;
        }else{
            cout << " " << endl; 
            cout << "Sorry , you might have entered a wrong letter , please try again"<<endl;
            cout << " " << endl; 
            cout << "Here are the possible entries " << endl; 
            array <string,6> possible_operations = {"n" ,"d" ,"w" ,"s" ,"c" ,"e"};
            printElements(possible_operations);
            cout << " " << endl; 
            continue;
        }


    }


}
