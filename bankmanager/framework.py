import random
import datetime

account_number_list = []
account_data = {}


class BankAccount:
    def __init__(self, holdername, holderfamname, balance):
        self.holdername = holdername
        self.holderfamname = holderfamname
        self.number = random.randint(111111111111, 999999999999)
        self.fullname = self.holdername + " " + self.holderfamname
        self.balance = balance

    def create_account(self):
        return f"{self.fullname} has the following account number {self.number} with a balance of {self.balance} $"

    def deposit_money(self, amount):
        self.balance += amount
        return f"A deposit of {amount} has been made in account number {self.number}. New balance is {self.balance} $"

    def withdraw_money(self, amount):
        if amount > self.balance:
            return f"Sorry, you cannot withdraw more than your balance, which is {self.balance} $"
        else:
            self.balance -= amount
            return f"New account balance is {self.balance} $"


def validate_name(name):
    return name.isalpha()


def main():
    print("Welcome to iBankManager – Your Digital Banking Assistant")

    while True:
        print("\nChoose an option:")
        print("C. Create Account")
        print("D. Deposit Money")
        print("W. Withdraw Money")
        print("I. View Account Information")
        print("X. Exit")

        choice = input("Enter your choice (C/D/W/I/X): ").upper()
        try :
            if choice == 'C':
                holdername = input("Enter your first name: ")
                holderfamname = input("Enter your last name: ")
                if validate_name(holdername) and validate_name(holderfamname):
                    balance = float(input("Enter initial balance in $: "))
                    account = BankAccount(holdername, holderfamname, balance)
                    account_number_list.append(account.number)
                    account_data[account.number] = account
                    print(account.create_account())
                else:
                    print("Invalid name or family name. Please use only alphabetic characters.")

            elif choice == 'D':
                number = int(input("Enter account number: "))
                amount = float(input("Enter the amount to deposit in $: "))
                account = account_data.get(number)
                if account:
                    print(account.deposit_money(amount))
                else:
                    print("Sorry, we cannot find the account. Please try again.")

            elif choice == 'W':
                number = int(input("Enter account number: "))
                amount = float(input("Enter the amount to withdraw: "))
                account = account_data.get(number)
                if account:
                    print(account.withdraw_money(amount))
                else:
                    print("Sorry, we cannot find the account. Please try again.")

            elif choice == 'I':
                number = int(input("Enter account number: "))
                account = account_data.get(number)
                if account:
                    print(f"Account Information: {account.create_account()}")
                else:
                    print("Sorry, we cannot find the account. Please try again.")

            elif choice == 'X':
                print("Thank you for using iBankManager. See you soon!")
                break

        except ValueError:
            print("Invalid choice. Please enter a valid option (C/D/W/I/X)")




if __name__ == "__main__":
    print(f"Current Date and Time: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    main()
