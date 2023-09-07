#include <iostream>  
// iostream is for input and output abilities in the console
using namespace std;
// to avoid adding std each time
int main()  // one main function that returns an int
{
  string name;  // declare a name variable
  cout<< "please Enter your name: " ;
  cin >> name;  // name is an input that takes a string

  if (name == "fares") {
    cout <<"Welcome back "<<name<<endl;
    int age;
    cout <<"please Enter your age: ";
    cin >> age;
    if (age == 20){
      cout <<"My first C++ program is successful"<<endl;
    }else {
      cout <<"My program still works"<<endl;
    }
  }else{
    cout <<"My program still works"<<endl;
  }
   return 0;
}
// my very first program , slightly modified after learning about conditions



