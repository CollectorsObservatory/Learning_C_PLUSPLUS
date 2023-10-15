/**
 * @file iBankManager.cpp
 * @author CollectorsObservatory
 * @date October 15th, 2023
 *
 * @brief This file contains the implementation of a procedural approach
 * to a Bank Management System using maps in C++.
 *
 * This implementation was chosen after a class-based approach seemed to 
 * complicate the work. The program provides various banking operations 
 * like creating an account, depositing money, withdrawing money, and 
 * displaying account information in various modes.
 */
#include <iostream>
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
   cout << "iBankManager Has successfully found the account" << endl;
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
        cout << "iBankManager Failed to find the account , please try again" << endl;
        cout << " " << endl;

    }
   

}

/**
 * @brief Displays specific account information given an account number.
 * @param number The account number.
 */
void special_info_display2(long long number){

   cout << " " << endl;
   cout << "iBankManager Has successfully found the account" << endl;
   // to look if the account number exists in the map
   auto it = accountbalance.find(number);
    if (it != accountbalance.end()){
        cout << "Bank Account number is: "<< number << endl ;
        cout << " " << endl;
        cout << "Current balance is: "<< accountbalance[number] <<"$"<< endl; 
        cout << " " << endl;
    }else {
        cout << " " << endl;
        cout << "iBankManager Failed to find the account , please try again" << endl;
        cout << " " << endl;

    }
   

}

void deposit_money(string holdername, double amount){
    auto it = clientinfo.find(holdername);
    double new_amount = accountbalance[clientinfo[holdername]] + amount;
    accountbalance[clientinfo[holdername]] = new_amount ;
    if (it != clientinfo.end()){
        cout << "iBankManager Has successfully found the account" << endl;
        cout << "Current Account Number is "<< clientinfo[holdername] << endl ;
        cout << "Current balance is " << accountbalance[clientinfo[holdername]] <<"$"<< endl; 
        cout << "New Balance is " << new_amount<< "$" << endl ;
    }else {
        cout << "Failed to find Bank account" << endl;
    }
}

void withdraw_money(string holdername, double amount){
    auto it = clientinfo.find(holdername);
    if (it != clientinfo.end()) {
        if(amount <= accountbalance[clientinfo[holdername]]) {
            double new_amount = accountbalance[clientinfo[holdername]] - amount;
            cout << " " << endl;
            cout << "iBankManager Has successfully found the account" << endl;
            cout << " " << endl;
            cout << "Current Account Number is "<< clientinfo[holdername] << endl ;
            cout << " " << endl;
            cout << "Current balance is " << accountbalance[clientinfo[holdername]] <<"$"<< endl; 
            cout << " " << endl;
            accountbalance[clientinfo[holdername]] = new_amount ;
            cout << " " << endl;
            cout << "New Balance is " << new_amount<< "$" << endl ;
            cout << " " << endl;
        } else if (amount > accountbalance[clientinfo[holdername]]) {
            cout << "Sorry you can not withdraw more than your balance that is: " << accountbalance[clientinfo[holdername]] << "$" <<endl;
        }
    } else {
        cout << "Failed to find Bank account" << endl;
    }
}


int main(void){
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
        cout << "I. View Full Account Information" << endl;
         cout << " " << endl;
        cout << "J. Information In Incognito Mode" << endl;
        cout << " " << endl;
        cout << "X. Exit iBankManger" << endl;
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
              
        
        }else if (choice == "x" || choice == "X"){
            cout << "Closing the program..." << endl;
            cout << "See you soon" << endl;
            break;
    }
        else {
            cout << "Invalid choice please try again" <<endl;
            continue ;
        }

    return 0;}