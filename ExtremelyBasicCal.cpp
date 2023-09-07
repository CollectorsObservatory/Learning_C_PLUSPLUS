#include <iostream>
using namespace std;

int main() {
    
    float number_1;
    float number_2;
    string operation;
    float result;

    cout << "Enter number: ";
    cin >> number_1;

    cout << "Enter number: ";
    cin >> number_2;

    cout << "Choose operation (+ or -): ";
    cin >> operation;

    result = (operation == "+") ? number_1 + number_2 : number_1 - number_2;

    cout << "Result is " << result << endl;

    return 0;
}
