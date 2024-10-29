#include <iostream>
#include <deque>

using namespace std;

class livre {
public:
    int m_id;
    string m_titre;
    string m_auteur;
    bool m_estEmprunte;

    livre(int p_id, const string& p_titre, const string& p_auteur, bool estEmprunte = false)
        : m_id(p_id), m_titre(p_titre), m_auteur(p_auteur), m_estEmprunte(estEmprunte) {}

    void afficher() const {
        cout << "ID: " << m_id << endl;
        cout << "TITRE: " << m_titre << endl;
        cout << "AUTEUR: " << m_auteur << endl;
        if (m_estEmprunte) {
            cout << "EST EMPRUNTE" << endl;
        } else {
            cout << "Disponible" << endl;
        }
    }

    void emprunter() {
        m_estEmprunte = true;
    }

    void retourner() {
        m_estEmprunte = false;
    }
};

// False = Livre disponible
// True = Livre emprunte
// estEmprunte = false = livre disponible
class utilisateur {
public:
    int m_id;
    string m_nom;
    deque<livre*> livreEmprunte;

    utilisateur(int p_id, const string& p_nom) : m_id(p_id), m_nom(p_nom) {}

    void emprunterLivre(livre* p_livre) {
        if (p_livre->m_estEmprunte) {
            cout << "Livre est déjà Emprunte" << endl;
        } else {
            p_livre->m_estEmprunte = true;
            livreEmprunte.push_back(p_livre);
            cout << "Livre emprunté avec succès" << endl;
        }
    }

    void retournerLivre(livre* p_livre) {
        if (p_livre->m_estEmprunte) {
            auto it = find(livreEmprunte.begin(), livreEmprunte.end(), p_livre);
            if (it != livreEmprunte.end()) {
                livreEmprunte.erase(it);
            }
            p_livre->m_estEmprunte = false;
        } else {
            cout << "Livre non emprunté" << endl;
        }
    }

    void afficher() {
        for (auto livre : livreEmprunte) {
            cout << livre->m_titre << " ";
        }
        cout << endl;
    }
};

class Bibliotheque {
public:
    deque<livre*> livreDisponible;
    deque<utilisateur*> utilisateurs;

    Bibliotheque() {};

    void ajouterLivre(livre* p_livre) {
        livreDisponible.push_back(p_livre);
    }

    void ajouterUtilisateur(utilisateur* p_utilisateur) {
        utilisateurs.push_back(p_utilisateur);
    }

    void afficherDispo() {
        for (auto livre : livreDisponible) {
            livre->afficher();
        }
    }

    void emprunterLivre(int idUtilisateur, int idLivre) {
        utilisateur* targetUser = nullptr;
        livre* targetLivre = nullptr;

        // Recherche de l'utilisateur par ID
        for (auto& user : utilisateurs) {
            if (user->m_id == idUtilisateur) {
                targetUser = user;
                break;
            }
        }

        // Recherche du livre par ID
        for (auto& book : livreDisponible) {
            if (book->m_id == idLivre) {
                targetLivre = book;
                break;
            }
        }

        // Emprunter le livre si utilisateur et livre sont trouvés
        if (targetUser && targetLivre) {
            targetUser->emprunterLivre(targetLivre);
        } else {
            cout << "Utilisateur ou livre non trouvé." << endl;
        }
    }

    void retournerLivre(int idUtilisateur, int idLivre) {
        utilisateur* targetUser = nullptr;
        livre* targetLivre = nullptr;

        // Recherche de l'utilisateur par ID
        for (auto& user : utilisateurs) {
            if (user->m_id == idUtilisateur) {
                targetUser = user;
                break;
            }
        }

        // Si l'utilisateur existe, recherche du livre dans livreEmprunte
        if (targetUser) {
            for (auto& book : targetUser->livreEmprunte) {
                if (book->m_id == idLivre) {
                    targetLivre = book;
                    break;
                }
            }

            // Retourner le livre si trouvé dans la liste d'emprunt de l'utilisateur
            if (targetLivre) {
                targetUser->retournerLivre(targetLivre);
                cout << "Livre retourné avec succès." << endl;
            } else {
                cout << "Livre non trouvé dans les emprunts de l'utilisateur." << endl;
            }
        } else {
            cout << "Utilisateur non trouvé." << endl;
        }
    }
};

int main() {
    Bibliotheque biblio;

    // Ajout de livres
    livre* livre1 = new livre(1, "Les Misérables", "Victor Hugo");
    livre* livre2 = new livre(2, "1984", "George Orwell");
    biblio.ajouterLivre(livre1);
    biblio.ajouterLivre(livre2);

    // Ajout d'utilisateurs
    utilisateur* user1 = new utilisateur(1, "Alice");
    utilisateur* user2 = new utilisateur(2, "Bob");
    biblio.ajouterUtilisateur(user1);
    biblio.ajouterUtilisateur(user2);

    // Emprunt de livres
    biblio.emprunterLivre(1, 1); // Alice emprunte "Les Misérables"

    // Affichage des livres disponibles
    cout << "Livres disponibles : " << endl;
    biblio.afficherDispo();

    // Retour du livre
    biblio.retournerLivre(1, 1); // Alice retourne "Les Misérables"

    // Libération de la mémoire
    delete livre1;
    delete livre2;
    delete user1;
    delete user2;

    return 0;
}
