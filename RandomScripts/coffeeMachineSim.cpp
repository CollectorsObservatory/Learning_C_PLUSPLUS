#include <iostream>
#include <memory>
#include<string>
#include <map>


using namespace std; 

class CoffeeMachine{

    private : 
    map<char, pair<string, int> > catalog;  // -> (category id) (coffee type, price)
    map<char,int> stock;
    double balance;

    public : 
    CoffeeMachine() : balance(0) {
        catalog.insert(make_pair('a', make_pair("expresso", 2)));
        catalog.insert(make_pair('b', make_pair("cappuccino", 3)));
        catalog.insert(make_pair('c', make_pair("warm water", 1)));
        stock['a'] = 5;
        stock['b'] = 5;
        stock['c'] = 5;
    }
    void InsertCoin(double amount){
        balance += amount;
        cout <<"Current Balance is: " << balance <<endl;
    }
    void SelectCoffee(char CatalogID){
        if(catalog.find(CatalogID) == catalog.end()){
            cout <<"Not found , Select again" <<endl;
            return;
        }
        if(stock[CatalogID] <= 0){
            cout<<"out of coffee" <<endl;
        }

        int coffeePrice = catalog[CatalogID].second;
        if (balance<coffeePrice) {
            int difference = balance - coffeePrice;
            
            cout <<"Insufficient balance." << endl;
            cout <<"insert: "<<difference <<endl;
        }
        balance -= coffeePrice; 
        stock[CatalogID] --;
        cout <<catalog[CatalogID].first<<" is ready!" <<endl;
        if(balance>0) {
            cout <<"Change is: " << balance <<endl;
        }
    }
    void showCatalog() const{
        for (const auto& coffee:catalog) {
            cout << coffee.second.first  <<" Price: " << coffee.second.second<<endl;
    
        }
    }



};



int main() {
    CoffeeMachine machine;
    machine.showCatalog();
    machine.InsertCoin(3) ;
    machine.SelectCoffee('b');

    
    return 0;
}



