#include <iostream>
#include <cctype>

static const int WITHDRAW_FEES_C = 5; // Withdrawal fees for checking accounts
static const int WITHDRAW_FEES_E = 8; // Withdrawal fees for savings accounts
static const int ADVANCE_FUNDS = 10;  // Cash advance fees for credit accounts
static const int VISA_FEES = 20;      // Fees for credit card
using namespace std;

/**
 * @brief Base class for demonstration
 */
class Base {
private: 
    int a;

public:
    Base(int x) : a(x) {};
    void showBase() { cout << "Base value is " << a << endl; }
    ~Base() {
        cout << "Base object destroyed" << endl;
    }
};

/**
 * @brief Derived class from Base
 */
class Derived1 : public Base {
private:
    int b;

public:
    Derived1(int x, int y) : Base(x), b(y) {};
    void showDerived1() {
        Base::showBase(); 
        cout << "Derived1 value is " << b << endl;
    }
    ~Derived1() {
        cout << "Derived1 object destroyed" << endl;
    }
};

/**
 * @brief Bank account class
 */
class Bank {
protected:
    string holderName;
    double balance;

public:
    Bank(string c_holderName, double c_balance) : holderName(c_holderName), balance(c_balance) {};

    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    void setHolderName(string n_holderName) { holderName = n_holderName; }
    void setBalance(double n_balance) { balance = n_balance; }

    void displayInfo() { cout << "Account holder: " << holderName << " with a balance of " << balance << endl; }

    void deposit(double amount) {
        balance += amount;
        cout << "New balance is " << balance << endl;
    }
    void withdraw(double amount) {
        balance -= (amount + WITHDRAW_FEES_C);
        cout << "New balance with $5 withdrawal fee is " << balance << endl;
    }

    static void compareTwoAccounts(const Bank& account1, const Bank& account2) {
        if (account1.getBalance() > account2.getBalance()) {
            double difference = account1.getBalance() - account2.getBalance();
            cout << account1.getHolderName() << " has more money than " << account2.getHolderName() << " by " << difference << endl;
        } else if (account2.getBalance() > account1.getBalance()) {
            double difference = account2.getBalance() - account1.getBalance();
            cout << account2.getHolderName() << " has more money than " << account1.getHolderName() << " by " << difference << endl;
        }
    }
    ~Bank() {
        cout << "Bank objects destroyed" << endl;
    }
};

/**
 * @brief Savings account class derived from Bank
 */
class SavingsAccount : public Bank {
private:
    double interest;

public:
    SavingsAccount(string holder, double balance) : Bank(holder, balance) {};

    void calculateInterest() {
        interest = getBalance() * 0.05;
        cout << "Interest for account belonging to " << getHolderName() << " is " << interest << endl;
    }

    void withdraw(double amount) {
        balance -= (amount + WITHDRAW_FEES_E);
        cout << "New balance with $8 withdrawal fee is " << balance << endl;
    }

    double getInterest() { return interest; }
    ~SavingsAccount() {
        cout << "Savings account objects destroyed" << endl;
    }
};

/**
 * @brief Credit account class derived from Bank
 */
class CreditAccount : public Bank {
    
protected:
    int creditLimit;

public:
    CreditAccount(string holder, double balance) : Bank(holder, balance) {};

    void setCreditLimit() {
        if (getBalance() < 10000) {
            creditLimit = 2000;
        } else {
            creditLimit = 5000;
        }
        cout << "Credit limit for " << getHolderName() << " is " << creditLimit << endl;
    }

    double setNewBalance() {
        balance -= VISA_FEES;
        cout << "Fees for credit card are " << VISA_FEES << ". New balance is " << balance << endl;
        return balance;
    }

    void withdraw(double amount) {
        balance -= (amount + ADVANCE_FUNDS);
        cout << "New balance with $10 cash advance fee is " << balance << endl;
    }

    ~CreditAccount() {
        cout << "Credit account objects destroyed" << endl;
    }
};

int main() {
    SavingsAccount person1("Aymen", 2000.5);
    SavingsAccount person2("Fares", 10);

    CreditAccount person3("Fares", 2000);

    person3.withdraw(2);
    person3.setNewBalance();
    person3.setCreditLimit();
    
    person1.displayInfo();
    person2.displayInfo();

    person1.calculateInterest();
    person2.calculateInterest();

    Bank::compareTwoAccounts(person1, person2);
    person1.deposit(9000);
    Bank::compareTwoAccounts(person1, person2);

    person2.withdraw(1000);
    Bank::compareTwoAccounts(person1, person2);

    return 0;
}
