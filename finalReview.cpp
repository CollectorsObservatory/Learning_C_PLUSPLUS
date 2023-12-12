#include<iostream> 
#include <sstream>
#include <memory>


using namespace std;
class Company{
    
    private:

    double m_salary; 
    int * m_experience; 
    string m_name;

    public:

    Company(const double& p_salary,const string& p_name,const int& p_experience) : 
    m_name(p_name), m_salary(p_salary),m_experience(new int (p_experience)) {cout<<m_name<<" Employee Created"<<endl;} 

    Company(const Company&other) : m_name(other.m_name), m_salary(other.m_salary),m_experience(new int(*(other.m_experience)))
    {cout<<"Copy Constructor was called for "<< other.m_name<<endl;}

    void reqInfo() const {cout<<m_name << "'s salary is " << m_salary <<endl; }

    string reqName() const {return m_name;}
    double reqSalary() const {return m_salary;}
    int* reqExperience() const{return m_experience;}


    bool operator>(const Company& another_employee){return m_salary > another_employee.m_salary;}
    
    bool operator==(const Company& another_employee){return m_salary == another_employee.m_salary;}

    string reqCompanyFormat() const{ 
        ostringstream sortie;
        sortie <<"Employee Information Form" <<endl;
        sortie <<" " << endl;
        sortie <<"Name      :"   << reqName() << endl;
        sortie <<"Salary    :"   << reqSalary() <<endl;
        return sortie.str();
    
    
    

    }
    Company& operator=(const Company&other){
        if(this !=&other){
            m_name = other.m_name;
            m_salary = other.m_salary;
            m_experience = new int(*other.m_experience);
        }
        cout<<"Operator = was Called"<<endl;
        return *this;
    }
     ~Company() {delete m_experience;cout<<"Employee Object Destroyed "<<m_name<<endl;}

 

};
int main() {
    unique_ptr<Company> employe1 (new Company(200, "Paul Allen", 1));
    unique_ptr<Company> employe2 (new Company(200, "John", 2));
    
    shared_ptr<Company> employe3 = make_shared<Company>(400, "Patrick",3);
    unique_ptr<Company> employe4 (new Company(200, "Beta",4));
    employe1 ->reqCompanyFormat();
    Company employe5(600, "alpha", 4);
    Company employe6 = employe5;
    Company employe7(800, "Gama", 9);
    employe5 = employe7;



   


    

    








    //Company * employee_2 = new Company(300,"aymen");
    //Company employe3(500, "momo");
    //Company* pointeur = &employe3;
   // cout << employe3.reqCompanyFormat() << endl;
    
    //cout << employee_2 -> reqCompanyFormat();
    //cout << employe -> reqCompanyFormat();

   // delete employee_2;
}