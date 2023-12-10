#include <iostream>
#include <stdexcept>

using namespace std; 

// exemple d'examen

void error(int p_val){
   
    switch ((p_val))
    {
    case 0 : throw 1 ;break;
    case 1 : throw 1.1f; break;
    case 2 : throw "abc" ; break; 
    
    default: cout<<"OK" << endl; break;
    }

}

void divide(int a, int b){
    if (b == 0){
        throw runtime_error("Divisio by zero error !");
    }else {
        cout << a / b << endl;
    }
}





int main () {
    try {error(3);}
    
    catch(int e) {cout<<"Error int"<<endl;}
    catch(float e) {cout<<"Error float"<<endl;}
    catch(...) {cout<<"Error str"<<endl;}

    try {divide(10,0);}
    catch(const runtime_error&e) {cout <<e.what()<<" Error caught!"<<endl;}




    return 0; 
}
