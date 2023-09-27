# include <iostream>
# include <array>
# include <vector>
using namespace std;


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



// calling them in main not to leave it empty
int main(void){

    infinite_vector();
    myfirstvector();
    pointer();
    operations_array();

}



