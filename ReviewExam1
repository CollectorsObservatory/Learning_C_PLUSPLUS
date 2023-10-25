# include <iostream>
# include <cctype>
using namespace std;


void révision_pointeur(){
    int a = 2;
    int c = 3 ;
    int* ptr_a= &a;
    int* ptr_c = &c;
    int *ptr_test = &a;
    int temp = *ptr_a;
    *ptr_a = *ptr_c; // le contenu de c est mis dans a
    *ptr_c = temp ;  // le contenu de temp qui est *ptr a est mis dans c
}

 void pointeur_deeper_review(){
    int x = 17;
    int *p = &x;
    cout << p << endl; // adresse mémoire ou x est stockée
    cout << *p <<endl; // valeur de l,adresse mémoire = valeur de x
    cout << &p <<endl; // adresse mém ou le pointeur est stocké
    cout << &x <<endl; // adresse mémoire  ou x est stockée
    cout << x << endl; // valeur de x
}
   

// Révision Tableau 2d
 array<array<int,3>,3> tableau_2d = {{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }};  
    
void fillArray(int arr[3][3]) {
    // fonction qui remplie un tableau 2d
    cout << "Please enter 9 integers for the 3x3 array:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter value for position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void affichage(int x){
    for (int i=-x ; i <= x ; i++){
        if (i < 0){
            cout << "Valeur Négative: " <<i <<endl;
        } else if (i == 0) {
            cout << "Valeur Nulle" << endl;
        }else {
            if (i % 2 == 0){
                cout << "Nombre Pair: " << i << endl;
            }else{
                cout << "Nombre Impair: " << i << endl;
            }
        }
        
         
    }
}

bool validerFormatcours(string input){
    // fonction qui valide les format suivant FFF-XXXX
    if (input.size() !=8 or input[3] != '-') return false;
    return isalpha(input[0]) and isalpha(input[1]) and isalpha(input[2]) 
    && isdigit(input[4]) && isdigit(input[5])
    && isdigit(input[6]) && isdigit(input[7]) ;

}

bool validerFormatFinal(string input){
    // fonction qui valide le format A12345 avec une boucle interne 

    if (input.size()!= 6) return false; 

    if (!isalpha(input[0])) return false; 

    for (int i=1; i<input.size(); i++) {
        if(!isdigit(input[i])) return false;
    }
    return true;

}
bool valider_format_code_série(string input){
    // fonction qui accepte le format 12a345s67d89fgjbk
    if(input.size() != 17) return false ;
    return isdigit(input[0]) && isdigit(input[1]) && isalpha(input[2]) && isdigit(input[3]) &&
    isdigit(input[4]) && isdigit(input[5]) && isalpha(input[6]) && isdigit(input[7]) && isdigit(input[8])
    && isalpha(input[9])  && isdigit(input[10]) && isdigit(input[11]) && isalpha(input[12])&& isalpha(input[13])
    && isalpha(input[14])&& isalpha(input[15])&& isalpha(input[16]);

}

bool validerformatcours_b(string input){

    if (input.size() !=8 || input[3] != '-') return false;

    for (int i=0; i<3; i++){
        if (!isalpha(input[i]) || !isupper(input[i])) return false;

    }for (int j=4; j<input.size(); j++){

        if(!isdigit(input[j])) return false ;
        ;}
    return true;
}

void test_valider_format() {
    string name; 
    cout << "enter name to check(format: FFF-XXXX): " << endl;
    cin >> name ;
    if (validerformatcours_b(name)) cout << "format valide"<< endl ;
    else cout << "format invalide" << endl ;

}
class Banque{

    // révision constructueur, this , destructeur , la méthode static qui peut etre appelé indepemndamment des objets

    private :

    double balance ;
    string name ;

    public :
    Banque (double balance, string name){
        this->balance = balance;
        this->name = name ;
    }
    int static add(int a, int b){
        return a + b;
    }

    void create_account(double balance, string name){
        cout <<"Account created" << endl;
        cout << "Balance is " << balance << endl;
        cout<<"HolderName is" << name <<endl;
    }
     ~Banque() {
        cout <<"Account Deleted" <<endl ;
     }


};

void test_banque(){
    double balance; 
    string name ;
    cout << "Enter Holdername" << endl;
    getline(cin,name);
    cout <<"Enter balance" <<endl;
    cin >> balance ;
    Banque compte(balance, name);
    compte.create_account(balance,name);

}

int main(void){

    test_banque();
    test_valider_format();



    return 0;
}


