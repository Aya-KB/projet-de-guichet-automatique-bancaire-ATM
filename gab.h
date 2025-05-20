//gab.h
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // Pour Sleep sous Windows

using namespace std;

class CompteBancaire {
private:
    double solde;

public:
    // Constructeurs
    CompteBancaire();
    CompteBancaire(double sol);
    CompteBancaire(const CompteBancaire& c);

    // Méthodes
    bool effectuerRetrait(double montant);
    void effectuerDepot(double montant);
    double consulterSolde() const;
    void modifierSolde(double nouveauSolde);
};

class Client {
private:
    string nom;
    string prenom;
    string idClient;
    CompteBancaire* compte;

public:
    // Constructeurs
    Client();
    Client(string n, string p, string id, CompteBancaire* cpt);

    // Méthodes
    void afficherInfos() const;
    void effectuerDepot(double montant);
    void effectuerRetrait(double montant);
    void associerCompte(CompteBancaire* cpt);
};

class GuichetAutomatique {
private:
    string codePin;
    CompteBancaire* compte;
    int tentatives;

public:
    // Constructeur
    GuichetAutomatique(string pinInitial, CompteBancaire* cpt);

    // Méthodes
    bool authentifierUtilisateur(const string& pinSaisi);
    bool changerCodePin(const string& ancienPin, const string& nouveauPin);
    void afficherMenu();
    void consulterSolde() const;
    bool effectuerRetrait(double montant);
    void effectuerDepot(double montant);

    // Méthode pour afficher l'animation
    void pauseAvecAnimation(const string& message, int secondes) const;
};

class Animation {
public:
    // Méthode pour afficher une animation avec pause
    static void pauseAvecAnimation(const string& message, int secondes) {
        cout << message;
        for (int i = 0; i < secondes; ++i) {
            cout << " .";
            cout.flush();
                      Sleep(1000); 
        }
        cout << endl;
    }
};

class InterfaceATM {
public:
    static void afficherBanniere(const string& titre);
    static void afficherMenuPrincipal();
	} ;


