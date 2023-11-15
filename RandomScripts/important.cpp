#include <iostream>
#include <vector>
using namespace std;
/*A COMPRENDRE POUR L EXAMEN FINAL- IL Y AURA UN EXEMPLE SIMILAIRE*/
class Base
{
  public:

    Base(int p_B):m_B(p_B){};

    virtual void afficher(){cout << "m_B = " << m_B <<endl;}
  private:

    int m_B;};

class Derivee1 : public Base
{

  public:
    Derivee1(int p_B, int p_D1): Base(p_B), m_D1(p_D1){};

    void afficher(){cout << "m_D1 = " << m_D1 << endl;} 

    /*mettre virtual ici c'est optionnel mais c'est bien pour la lisibilité*/

  private:

    int m_D1;};

 

class Derivee2 : public Base
{

  public:
    Derivee2(int p_B, int p_D2): Base(p_B), m_D2(p_D2){}; 

    void afficher(){cout << "m_D2 = " << m_D2 << endl;} 

    /*mettre virtual ici c'est optionnel mais c'est bien pour la lisibilité*/

  private:

    int m_D2;};
    
int main()

{

    vector<Base*> vBase;
    Base b(0); vBase.push_back(&b);
    Derivee1 d1(1,1); vBase.push_back(&d1);
    Derivee2 d2(2,2); vBase.push_back(&d2);

    for (unsigned int i =0; i<vBase.size(); i++)
    {
       vBase[i]->afficher(); 
    }
    return 0;

}
