#ifndef FINAL_REVIEW
#define FINAL_REVIEW
#include <memory>
#include <string>
#include <sstream>
#include <vector>

namespace finalreview {

    class Company{

        private: 

        double m_salary;
        int* m_experience; 
        std::string m_name;

        public: 
        Company(const double& p_salary, const std::string& p_name,const int& p_experience);
        Company(const Company&other);
        void reqInfo() const;

        std::string reqName() const; 
        double reqSalary() const; 
        int* reqExperience() const; 

        bool operator>(const Company& another_employee);

        bool operator==(const Company& another_employee);

        std::string reqCompanyFormat() const;

        Company& operator=(const Company&other);

         ~Company(); 


    };


}

namespace hockey {

    class Personne {
    public:
     
        Personne(const std::string& p_nom, const std::string& p_prenom, 
                const std::string& p_telephone);

     
        std::string reqNom() const;
        std::string reqPrenom() const;
       
        std::string reqTelephone() const;
        void asgTelephone(const std::string& p_telephone);

      
        bool operator==(const Personne& autrePersonne) const;

        virtual std::string reqPersonneFormate() const = 0; 
        virtual std::unique_ptr<Personne> clone() const = 0;  
      
        virtual ~Personne();


    protected:
        // Attributs
        std::string m_nom;
        std::string m_prenom;
        std::string m_telephone;
    private:
        void verifieInvariant() const;
    };

    class Annuaire {
      
    public:
      
        Annuaire(const std::string& p_nomClub);
        std::string reqNom() const;
        std::string reqAnnuaireFormate() const;
       
        

        Annuaire(const Annuaire& autre);
        Annuaire& operator=(const Annuaire& autre);
        void ajouterPersonne(const Personne& p_personne);
        void supprimerPersonne(const std::string& p_nom, const std::string& p_prenom);

        size_t reqNombrePersonnes() const;
        ~Annuaire() = default;

    private:
       
        std::string m_nomClub;
        std::vector<std::unique_ptr<Personne>> m_membres;
        bool PersonneEstDejaPresente(const Personne& p_personne) const ; 
        void verifieInvariant() const;
    };

} /* namespace hockey */

#endif 