/**
 * \file main.cpp
 * \brief A comprehensive file demonstrating a variety of C++ concepts and practices including 
 *        the use of pointers, templates, vectors, arrays, and maps. Also included are examples 
 *        of infinite user input handling, dynamic vector creation, and basic array and vector 
 *        operations. This is a general review for weeks 3 and 4 of learning C++.
 * \author collectorsObservatory
 * \date 2023-10-01
 */

# include <iostream>
# include <array>
# include <vector>
# include <map>
using namespace std;
// Week 3 and week 4 general review 

template <typename Container>
void printElements(const Container& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
}
// template that displays each time while getting back to the line
template <typename Containe>
void printElementswlign(const Containe& container){
     for (const auto& element : container) {
        cout << element << endl;
    }
}
// Learning how to use the Basics of Pointers
void pointer(void)
{

    int x = 10;
    int y = 20;
    int* ptr_x = &x;
    int* ptr_y = &y;
    cout << "Value of X is " << *ptr_x << endl;
    cout << " "<< endl;
    cout << "Value of Y is " << *ptr_y << endl;
    int temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
    cout << "Value of X is " << *ptr_x << endl;
     cout << " "<< endl;
     cout << "Value of Y is " << *ptr_y << endl;
}

// trying to use for loop to create a dynamic vector
void myfirstvector(void){

    vector <int> myvector;
    int length;

    cout<< "Enter the length of the list: ";
    cin >> length;
    int number;

    for (int i = 0; i < length ; i++){
        cout << "Enter number ";
        cin >> number;
        myvector.push_back(number);
    }
    printElements(myvector);


}

// Infinite input Vector

void infinite_vector(void){

    vector <string> dynamic_vector;
    string elements;
    while (true){

        cout << "Enter first number(x to exit): ";
        cin >> elements ;

        if (elements == "x"){
            break;
        }else{
             dynamic_vector.push_back(elements);
        };
       
    }
    printElements(dynamic_vector);

}

// tring to declare and display arrays - could have optimized my calculator code 
// by using an array like this instead of a map that is harder to add elements to
// and to display elements from 
void operations_array(void){

    array <string, 5> operations = {"Addition = +," , "Multiplication = -"};

    printElements(operations);

}

void printing_vector(void){
        vector <int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        myVector.push_back(4);
        bool find = false; 
        int userInput ;
        cout << "Enter number: " ;
        cin >> userInput ;
        for(int i = 0; i < myVector.size() ; i++){
            if (myVector[i] == userInput){
            find= true;
        }
    }
        if (find){
            cout << userInput << " is found in vector" ;
    }   else {
            cout << userInput << " is not found in vector" ;
    }

}
void generate_random(void){
    int userinput;
    cout << "Enter Number: " ;
    cin >> userinput ; 
    for (int i = 0; i < userinput ; i++){
          for (int i = 0; i < 12; ++i) {
            int digit = rand() % 10; // Generate a random digit (0-9)
    }
    }
}
void console_input(void){
    // reviewing console in modes and switching between them 
    string fullname; 
    int age ; 
    cout << "Enter your full name: " << endl; 
    getline(cin, fullname);
    cout << "Enter your age: " << endl; 
    cin >>age;
    cout << "Full name is: " << fullname << endl;
    cout <<"Your age is: " << age << endl;
}

void array_printing(void){
     // trying an easy way to print vector and array items
    array <int, 3> numbers = {1,2,3} ; 
    for(int number : numbers){
        cout << number <<" ," ;
    }
}

void vector_printing(void){
    // printing vector one under the other 

    vector <string > names ; 
    names.push_back("mark");
    names.push_back("John");
    names.push_back("paul");
    for(string name: names){
        cout << name << " " <<endl;;
        cout <<" " << endl; 
    }
}

void map_printing(void){
    // we can use const auto&Var to ignore var type for more flexible use
    map < string , int > currency ; 
    currency["dollar"] = 100;
    currency["Dinar"] = 500;
    currency["Euro"] = 600;
    for (pair<string, int> pair: currency){
        cout << pair.first << ": " << pair.second << endl; 
        cout << " " << endl;
    }
}

void finding_item_vetor(void){
     vector <string > names ; 
    names.push_back("mark");
    names.push_back("John");
    names.push_back("paul");
    bool finding_name = false; 
    for (int i=0 ; i < names.size() ; i ++){
        if(names[i] == "mark"){
            finding_name =true ;
        }
    }
    if (finding_name){
        cout << "Success !" << endl ;
    }else{
        cout << "failed! " << endl;
    }
}

void table(void){
    // declaring a 2d table
     array<array<int, 3>, 5> myTable = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    }};
   
}


// calling them in main not to leave it empty
int main(void){
    infinite_vector();
    myfirstvector();
    pointer();
    operations_array();
    printing_vector();
    generate_random();
}



