/**
 * Bionic BankManager - Elevate Your Banking Experience
 * 
 * @file BionicBankManager.cpp
 * 
 * @brief 
 *    Bionic BankManager is a premium digital banking assistant designed to offer
 *    a seamless, efficient, and elegant interface for managing bank accounts.
 *    Engineered with cutting-edge technology and user-centric design, 
 *    Bionic BankManager offers an innovative approach to traditional banking,
 *    making every interaction a delightful experience.
 *
 * Features:
 *    - Account Creation: Craft a new beginning with personalized account options.
 *    - Deposit & Withdrawal: Amplify and access your wealth with ease and security.
 *    - Account Insights: Get a detailed view of your financial portfolio anytime.
 *    - Incognito Viewing: Explore your financial data with privacy and discretion.
 *    - Data Access: Dive into a comprehensive data lake of your financial history.
 *
 * @author CollectorsObservatory
 *
 * @date 2023-10-15
 *
 * Bionic BankManager - Uniting technology and finance, transforming every transaction
 * into an experience of efficiency, security, and elegance. Every feature is designed
 * to empower users, providing intuitive tools to manage and explore their financial
 * landscape. Step into a world where technology meets finance, and discover the future
 * of banking with Bionic BankManager.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;


// Maps to hold client information and account balances

map <string , long long > clientinfo;
map <long long, double > accountbalance;
// Variables to hold user inputs during runtime

string choice; 
string holdername;
string gender; 
double balance; 
double amount ; 

/**
 * @brief Generates a random 12-digit number to be used as a bank account number.
 * @return A random 12-digit number.
 */

long long random_number() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_first(1, 9);
    uniform_int_distribution<> dist_rest(0, 9);

    long long randomCode = dist_first(gen);
    for (int i = 1; i < 12; ++i) {
        randomCode = randomCode * 10 + dist_rest(gen);
    }
    return randomCode;
}


/**
 * @brief Confirms the creation of a bank account and displays the account details.
 * @param holdername The name of the account holder.
 * @param gender The gender of the account holder.
 * @param balance The initial deposit amount.
 */

void account_confirmation_message(string holdername, string gender, double balance){
    cout << " " << endl;
    cout << "Crafting a world of endless possibilities..." << endl;
    cout << " " << endl;
    cout << "Success! Your account, a gateway to financial freedom, is ready." << endl;
    cout << " " << endl;
    clientinfo[holdername] = random_number();
    accountbalance[clientinfo[holdername]] = balance ;
    long long number = clientinfo[holdername];
    if (gender == "m" || gender == "M") {
        cout << " " << endl;
        cout << "Mr " << holdername << " has successfully created his bank account" << endl;
        cout << " " << endl;
        cout << "account balance is " << balance << "$" <<endl;
        cout << " " << endl;
        cout << "account number is: " << number;
        cout << " " << endl;
    } else if (gender == "f" || gender == "F") {
        cout << " " << endl;
        cout << "Ms " << holdername << " has successfully created her bank account" << endl;
        cout << " " << endl;
        cout << "account balance is " << balance << "$" <<endl;
        cout << " " << endl;
        cout << "account number is: " << number;
        cout << " " << endl;
    }
    
}


/**
 * @brief Displays all account information of all clients.
 */

void show_info(){
    for (const auto&pair : clientinfo){
        cout << " " << endl;
        cout <<pair.first << ":" << pair.second << endl;
        cout << " " << endl;
    }
    for (const auto&pair : accountbalance){
        cout << " " << endl;
        cout <<pair.first << ":" << pair.second << endl;
        cout << " " << endl;
    }
}

/**
 * @brief Displays specific account information given a holder name.
 * @param holdername The name of the account holder.
 */

void special_info_display1(string holderame){

   cout << " " << endl;
   cout << "Bionic BankManager Has successfully found the account" << endl;
   cout << "Unlocking the vault... A detailed glance at your empire of wealth." << endl;

   auto it = clientinfo.find(holdername);
    if (it != clientinfo.end()){
        cout << " " << endl;
        cout << "Full Holder name is: "<< holderame <<endl ;
        cout << " " << endl;
        cout << "Bank Account number is: "<< clientinfo[holderame] << endl ;
        cout << " " << endl;
        cout << "Current balance is: "<< accountbalance[clientinfo[holdername]] <<"$"<< endl; 
        cout << " " << endl;
    }else {
        cout << " " << endl;
        cout << "Oops! Seems like a mystery option. Let's try again, shall we?" << endl;
        cout << " " << endl;

    }
   

}

/**
 * @brief Displays specific account information given an account number.
 * @param number The account number.
 */
void special_info_display2(long long number){
   cout << " " << endl;
   cout << "Bionic BankManager Has successfully found the account" << endl;
   cout << "Unlocking the vault... A detailed glance at your empire of wealth." << endl;

   // to look if the account number exists in the map
   auto it = accountbalance.find(number);
    if (it != accountbalance.end()){
        cout << "Bank Account number is: "<< number << endl ;
        cout << " " << endl;
        cout << "Current balance is: "<< accountbalance[number] <<"$"<< endl; 
        cout << " " << endl;
    }else {
        cout << " " << endl;
        cout << "Oops! Seems like a mystery option. Let's try again, shall we?" << endl;
        cout << " " << endl;

    }
   

}

void deposit_money(string holdername, double amount){
    auto it = clientinfo.find(holdername);
    if (it != clientinfo.end()){
        double new_amount = accountbalance[clientinfo[holdername]] + amount;
        accountbalance[clientinfo[holdername]] = new_amount ;
        cout << "Deposit Successful - Your Balance Just Got a Boost!" << endl;
        cout << " " << endl;
        cout << "Current Account Number is "<< clientinfo[holdername] << endl ;
        cout << " " << endl;
        cout << "Current balance is " << accountbalance[clientinfo[holdername]] <<"$"<< endl; 
        cout << " " << endl;
        cout << "New Balance is " << new_amount<< "$" << endl ;
        cout << " " << endl;
    }else {
        cout << "Oops! Seems like a mystery option. Let's try again, shall we?" << endl;
    }
}


void withdraw_money(string holdername, double amount){
    auto it = clientinfo.find(holdername);
    if (it != clientinfo.end()) {
        if(amount <= accountbalance[clientinfo[holdername]]) {
            double new_amount = accountbalance[clientinfo[holdername]] - amount;
            cout << " " << endl;
            cout << "Bionic BankManager Has successfully found the account" << endl;
            cout << " " << endl;
            cout << "Current Account Number is "<< clientinfo[holdername] << endl ;
            cout << " " << endl;
            cout << "Current balance is " << accountbalance[clientinfo[holdername]] <<"$"<< endl; 
            cout << " " << endl;
            accountbalance[clientinfo[holdername]] = new_amount ;
            cout << " " << endl;
            cout << "Withdrawal Successful - Empowering Your Financial Movements!" << endl;
            cout << " " << endl;
            cout << "New Balance is " << new_amount<< "$" << endl ;
            cout << " " << endl;
        } else if (amount > accountbalance[clientinfo[holdername]]) {
            cout << "Sorry you can not withdraw more than your balance that is: " << accountbalance[clientinfo[holdername]] << "$" <<endl;
        }
    } else {
        cout << "Oops! Seems like a mystery option. Let's try again, shall we?" << endl;
    }
}

void add_account_to_file(string holderName, double balance, long long accountNumber) {
    ofstream file;
    file.open("accounts.txt", ios::app); // Open file in append mode

    if (file.is_open()) {
        file << holderName << " | " << balance << " | " << accountNumber << "\n";
        file.close();
        cout << " " << endl;
        cout << "Account added to file successfully!" << endl;
        cout << " " << endl;
    } else {
        cerr << "Unable to open the file." << endl;
    }
}

void access_account_from_file(long long accountNumber) {
    ifstream file;
    file.open("accounts.txt");

    if (file.is_open()) {
        string line;
        bool accountFound = false;

        while (getline(file, line)) {
            // Skip empty lines or lines with less than expected data
            if (line.empty() || count(line.begin(), line.end(), '|') < 2) {
                continue;
            }

            stringstream ss(line);
            string holderName, balance, accNumStr;
            getline(ss, holderName, '|');
            getline(ss, balance, '|');
            getline(ss, accNumStr);

            try {
                long long accNum = stoll(accNumStr); 

                if (accNum == accountNumber) {
                    cout << "Account found: " << line << endl;
                    accountFound = true;
                    break;
                }
            } catch (const invalid_argument& ia) {
                continue;
            }
        }

        if (!accountFound) {
            cout << "Account not found." << endl;
        }

        file.close();
    } else {
        cerr << "Unable to open the file." << endl;
    }
}

int main(void){
        cout << " " << endl;
       cout << "Welcome to Bionic BankManager - Elevate Your Banking Experience." << endl;
        cout << " " << endl;
        cout << "Choose an option " << endl;
        cout << " " << endl;
        cout << "C. Create Account " << endl;
        cout << " " << endl;
        cout << "D. Deposit Money" << endl;
        cout << " " << endl;
        cout << "W. Withdraw Money" << endl;
        cout << " " << endl;
        cout << "I. View Full Account Information" << endl;
        cout << " " << endl;
        cout << "P. Extract from the Banking DataBase" << endl;
        cout << " " << endl;
        cout << "J. View Information In Incognito Mode" << endl;
        cout << " " << endl;
        cout << "X. Exit Bionic BankManager" << endl;
        cout << " " << endl;  
        while (true){

        cout <<"Enter your chosen option in this field: " ;
        cin >> choice ;

        if (choice == "c" || choice == "C"){
            cout << " " << endl;
            cout << "Enter your full name: " << endl;
            cout << " " << endl;
            cin.ignore();
            getline(cin, holdername);
            cout << " " << endl;
            cout << "Enter the client's gender: " << endl;
            cout << " " << endl;
            cin >> gender; 
            cin.ignore();
            cout << " " << endl;
            cout << "Enter the initial deposit" << endl;
            cout << " " << endl;
            cin >> balance;
            cout << " " << endl;
            account_confirmation_message(holdername, gender, balance);
            add_account_to_file(holdername, balance, clientinfo[holdername]);



            
        }else if (choice == "d" || choice == "D"){
            cout << " " << endl;
            cout << "Enter your full name: " << endl;
            cout << " " << endl;
            cin.ignore();
            getline(cin, holdername);
            cout << " " << endl;
            cout << "Enter the amount to deposit in this bank account" << endl; 
            cout << " " << endl;
            cin >> amount;
            deposit_money(holdername, amount);
            show_info();

         

            
        }else if (choice == "w" || choice == "W"){
            cout << " " << endl;
            cout << "Enter your full name: " << endl;
            cout << " " << endl;
            cin.ignore();
            getline(cin, holdername);
            cout << " " << endl;
            cout << "Enter the amount to withdraw from this bank account" << endl; 
            cout << " " << endl;
            cin >> amount;
            withdraw_money(holdername, amount);
            show_info();
        
        }else if (choice == "i" || choice == "I"){
            cout << " " << endl;
            cout << "Enter your full name: " << endl;
            cout << " " << endl;
            cin.ignore();
            getline(cin, holdername);
            special_info_display1(holdername);
              
         }else if (choice == "j" || choice == "J"){
            long long number;
            cout << " " << endl;
            cout << "Enter the bank account number: " << endl;
            cout << " " << endl;
            cin >> number;
            special_info_display2(number);

              
        }else if (choice == "p" || choice == "P"){
            long long number;
            cout << " " << endl;
            cout << "Enter the bank account number: " << endl;
            cout << " " << endl;
            cin >> number;
            access_account_from_file(number);

              
        
        }else if (choice == "x" || choice == "X"){
            cout << "Closing Bionic BankManager..." << endl;
            for (int i=0 ; i < 10 ; i++){
                cout << "........" <<endl;
            }
            cout << "Farewell, till we meet again. Your financial companion, Bionic BankManager, will always await your return." << endl;
            break;
    }
        else {
            cout << "Invalid choice please try again" <<endl;
            continue ;
        }
        }

    return 0;
    }