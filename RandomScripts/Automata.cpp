#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cctype>

using namespace std ;
//NOTE : STILL HAS SOME ISSUES TO FIX - FIXED ON FILE CALLED NEW AUTO.CPP SAME DIRECTORY

/**
 * /brief function for a^nb^n language 
 */


string pushdown_automaton(string word)
{
    string t = "true"; 
    string f = "false";

    
    if (word[0] != 'a') {
        return f;
    }
    
    
    vector<string> stack ; 
    
    for (int i = 0 ; i<word.size() ; i++){
        if (!(isalpha(word[i]))){return f; }
        if (word [i] != 'a' && word [i] != 'b') {cout << "gotcha" << endl; return f; }
        if (word[i] == 'a') {stack.push_back("a");}
        if (word[i] == 'b'){stack.pop_back();}
        if(stack.empty()) {return f; }
       
    }
    if (stack.size() != 0) {return f;}
    return t; 
    

}


/**
 * /brief function for a^nb^nc^n language 
 * basically simulating a TM with a double stacked pushdown automaton 
 */

string double_stack_automaton(string word){
    
    string t = "true"; 
    string f = "false";
    
    vector<string> stack_alpha ; 
    vector<string> stack_beta ; 
     
    stack_alpha.push_back("#");
    stack_beta.push_back("#");
     
    if (word[0] != 'a') {
        return f;
    }


    
    for (int i = 0 ; i<word.size() ; i++){
         
        if (!(isalpha(word[i]))){return f; }
        
        if (word[i] == 'a'){
            stack_alpha.push_back("a");
            stack_beta.push_back("c");
        }

        
        if (word[i] == 'b'){stack_alpha.pop_back();}
        
        if (stack_alpha.empty()){cout<<"Not equal number a and b" <<endl;return f;}

        else if (stack_alpha.size() == 1) {
            if (word[i] == 'c'){stack_beta.pop_back();}
        }


        if (stack_beta.empty()) {cout<<"Not equal number a and c" <<endl;return f;}}

       
      
    
    if (stack_alpha.size() != 1 && stack_beta.size() != 1) {return f;}

    return t; 
     
    
}

/**
 * /brief function for a^n$a^n language  
 */

string another_pushdown_automaton(string word) {

    string f = "false" ; 
    string t = "true"; 
    vector <string> stack ; 

    if(word.size() /2 != 0) {return f;}
    

    if(word[word.size()/2] != '$') {
        return f; 
    }

    for(int i = 0; i < word.size()/2 ; i++) {
        if (!(isalpha(word[i]))) {return f;}
        if(word[i] != 'a') {return f;}
        if (word[i] == 'a') {
            stack.push_back("a");
        }
    }

    for(int i = word.size()/2 ; i < word.size(); i++){
        if (word[i] == 'a'){
            if (stack.empty()) {return f;}
            stack.pop_back();
        }


    }
    if (!(stack.empty())) {return f; }

    return t;
   

}



int main() {


    while(true){

        string word; 
        cout << "Enter word(X to exit):  " << endl; 
        cin >> word; 
        if(word[word.size()-1] == 'c') {cout<< double_stack_automaton(word)<<endl; cout << "ok" <<endl;}
        if(word[word.size()/2] == '$'){ cout <<another_pushdown_automaton(word)<<endl;}
        if(word[word.size()-1] == 'b'){cout << pushdown_automaton(word) << endl;}
        if(word == "X" || word == "x" ){break;}
        }




    return 0;
}
