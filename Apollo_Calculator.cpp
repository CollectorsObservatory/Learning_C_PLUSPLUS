/**
 * \file Apollo_calculator.cpp
 * \brief This file implements a basic and scientific calculator named Apollo Calculator.
 *        The basic calculator supports addition, subtraction, multiplication, and division operations.
 *        The scientific calculator extends the functionalities to include trigonometric and exponential
 *        operations. Users interact with Apollo Calculator through a command-line interface, entering
 *        their choice of operation and inputs to perform calculations. The Calculator class encapsulates
 *        the core functionalities and operations, demonstrating an application of OOP concepts in C++.
 *        The application is user-friendly, offering a repeat operation feature and clear error messages 
 *        for better user experience.
 * \author Fares Majdoub
 */
# include <iostream>
# include <math.h>
# include <map>
using namespace std;

class Calculator{
    // Trying Classes in C++ , second week of learning it 
    // this class does basic calculations , could replace it with just the functions
    // but i want to test how a class works
    private:
    float num1;
    float num2;
    public:
    Calculator(float x, float y){  // activating the arguments
        num1 = x;
        num2 = y;
    } // presenting the basic methods it can use
    float add(){
        return num1 + num2;
    }

    float subs(){
        return num1 - num2;
    }

    float multiply(){
        return num1 * num2;
    }

    float divide(){
        if (num2 != 0){
            return num1 / num2;
        }else{
            cout << "Division by zero Error !"<< endl;
            return 0.0;
        }
    }

};

int main(void) {
    // i present the options , basic or scientific 
    int choice;
    cout << "Welcome to Apollo Calculator on C++" << endl;
    cout << " " << endl;
    cout << "Here are the available modes:" << endl;
    cout << " "<< endl;
    cout << "Press 1- For basic calculator" << endl;
    cout << " "<< endl;
    cout << "Press 2- for scientific calculations only" << endl;
    cout << " "<< endl;
    cout << "Please Enter your choice: ";
    cin >> choice ;
    if (choice == 1){
        cout << "Welcome to basic Apollo Calculator" <<endl;
        float numb1;
        float numb2;
        string operation;
        map <string , string> allowedops;  // this to show the user what symbols to use

        allowedops["Addition"] = "+";
        allowedops["Substraction"] = "-";
        allowedops["Multiplication"] = "*";
        allowedops["Division"] = "/";
    
        cout<< "Here are the allowed operations: " << endl;
        for (const std::pair<std::string, std::string>& pair : allowedops){
            cout << pair.first << ": " << pair.second << std::endl;
        }
        // initiating an endless loop
        while (true){
        cout << "Please Enter Number : ";
        cin >> numb1;
        cout << "Please Enter Number : ";
        cin >> numb2;
        cout << "Please Enter the operation: ";
        cin >> operation;

        Calculator new_calc(numb1, numb2);  // creating the object
        float result;

        if (operation == "+"){
            result = new_calc.add();
            cout << "Result is " << result<< endl;

        }else if (operation == "-"){
            result = new_calc.subs();
            cout << "Result is " << result<< endl;

        }else if (operation == "*"){
            result = new_calc.multiply();
            cout << "Result is " << result<< endl;

        }else if (operation == "/"){
            result = new_calc.divide();
            cout << "Result is " << result<< endl;

        }else{
            cout << "Operation Type Error!" ; 
            break;
        }
        string choice_2;  // the user can choose to continue or exit the program properly
        cout << "Press enter to continue , enter exit to quit basic calculator: ";
        cin.ignore();  // to register the enter key
        getline(cin, choice_2);
        if (choice_2.empty()){
            continue;
        }else if (choice_2 == "exit"){
            cout << "Closing Calculator...";
            break;
        }else{
            cout << "Value Error , try again!";
            break;
        }

        }

        
    }else if(choice == 2){
        // adding some random math.h builtins , to avoid repetition , just for testing purposes
        cout << " This mode allows you to calculate sin , cos , square and exp for a given number"<< endl;
        float scinum;
        float result;
        string sciop;
         while (true){
            cout << "Please Enter a number: " ;
            cin >> scinum;
            cout<< "Enter the operation:  ";
            cin >> sciop;
            if (sciop == "sin"){
                result = sin(scinum);
                cout<<" "<< result<< endl;


            }else if(sciop == "cos"){
                result = cos(scinum);
                cout<<" "<< result<< endl;


            }else if(sciop == "square"){
                result = sqrt(scinum);
                cout<<" "<< result<< endl;


            }else if(sciop == "exp"){
                result = exp(scinum);
                cout<<" "<< result<< endl;

            }else{
                cout << "Operation Error , try again";
            }
            string choice_2;  // the user can choose to continue or exit the program properly
            cout << "Press enter to continue , enter exit to quit scientific calculator: ";
            cin.ignore();  // to register the enter key
            getline(cin, choice_2);
            if (choice_2.empty()){
               continue;
            }else if (choice_2 == "exit"){
            cout << "Closing Calculator...";
                break;
            }else{
            cout << "Value Error , try again!";
                break;
        }

    };
    }else{
        cout<< "Value Error , Try again by Pressing either 1 or 2!"<<endl;
    }
    return 0;
}


