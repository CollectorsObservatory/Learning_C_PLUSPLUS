# include <iostream> 
# include <array>


using namespace std ; 

void display_pc_prices(void){

    cout << "1-MacBook" << endl;
    cout << "Prix: 1000 CAD" << endl;
    cout<< " " << endl; 
    cout << "2-ThinkPad" << endl;
    cout << "Prix: 500 CAD" << endl;
    cout<< " " << endl; 
    cout << "3-Thinkbook" << endl;
    cout << "Prix: 200 CAD" << endl;
    cout<< " " << endl; 
}

void display_smartphones_prices(void){

    cout << "1-Iphone 15" << endl;
    cout<< "Prix: 1500 CAD" << endl;
    cout<< " " << endl; 
    cout<< "2-Iphone 11 used " << endl; 
    cout<< "Prix: 200 CAD " << endl;  
    cout<< " " << endl; 
}


int main(void){

    cout << " " << endl;
    cout << " " << endl;
    cout << "** Bonjour , Bienvenue à notre boutique en ligne **" << endl;
    cout<< " " << endl; 
    cout << "** Je suis Cindy , ton assitance virtuelle , comment puis je vous aider aujourd'hui: **" << endl; 
    cout << " " << endl;

    array <string, 2 > options = {"1-Ordinateurs Portables", "2-iphones"};

    for(string option: options){
        cout << option << endl;
    } 
    cout << " " << endl;

    while (true){

        cout << "Choisi un nombre pour procéder:  " << endl; 
        int choice ;
        cin >> choice ; 

        if (choice == 1){

             display_pc_prices();

             while(true){

                cout << "Choisi une option parmis notre séléction: " <<endl;
                int choice ;
                cin >> choice ;
             
               if (choice == 1){
                cout << "Est ce que tu confirme ton achat?(oui/non)" << endl ;
                string choix_2;
                cin >> choix_2 ;
                if (choix_2 =="oui"){
                    cout<< "ACHAT DÉBITÉ DE VOTRE CARTE VISA ! MERCI" << endl;
                    break;
        break; 

                }else if(choix_2 == "non") {
                     cout<< "Achat retiré , merci passe une excellente journée" << endl;
                    break; 

                }
        break; 

               }else if(choice ==2){
                 cout << "Est ce que tu confirme ton achat?(oui/non)" << endl ;
                 string choix_2;
                 cin >> choix_2 ;
                 if (choix_2 =="oui"){
                     cout<< "ACHAT DÉBITÉ DE VOTRE CARTE VISA ! MERCI" << endl;
                     break;
                }else if(choix_2 == "non") {
                     cout<< "Achat retiré , merci passe une excellente journée" << endl;
                    break; 

                }
                break; 
 
               }else if(choice ==3){
                 cout << "Est ce que tu confirme ton achat?(oui/non)" << endl ;
                 string choix_2;
                 cin >> choix_2 ;
                 if (choix_2 =="oui"){
                    cout<< "ACHAT DÉBITÉ DE VOTRE CARTE VISA ! MERCI" << endl;
                    break;
                }else if(choix_2 == "non") {
                     cout<< "Achat retiré , merci passe une excellente journée" << endl;
                    break; 

                }
                break; 

               }else{
                 cout << "Option invalide , refais ton choix stp" <<endl;
                 continue;
              }
             };
             


        }else if(choice == 2){
             display_smartphones_prices();
             cout << "Est ce que tu confirme ton achat?(oui/non)" << endl ;
                 string choix_2;
                 cin >> choix_2 ;
                 if (choix_2 =="oui"){
                    cout<< "ACHAT DÉBITÉ DE VOTRE CARTE VISA ! MERCI" << endl;
                    break;
                }else if(choix_2 == "non") {
                     cout<< "Achat retiré , merci passe une excellente journée" << endl;
                    break; 

                }
         }else {
              cout << "Option invalide , refais ton choix stp" <<endl;
        continue;
    }
    }

}



