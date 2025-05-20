//gab.h
#include "gab.h"
#include <iostream>
#include <unistd.h>  // Pour sleep() sous Linux
using namespace std;

// Constructeurs
CompteBancaire::CompteBancaire() : solde(25000) {}
CompteBancaire::CompteBancaire(double sol) : solde(sol) {}
CompteBancaire::CompteBancaire(const CompteBancaire& c) : solde(c.solde) {}

bool CompteBancaire::effectuerRetrait(double montant) {
    if (montant > solde) {
        cout << "Fonds insuffisants !" << endl;
        return false;
    }
    solde -= montant;
    return true;
}

void CompteBancaire::effectuerDepot(double montant) {
    solde += montant;
}

double CompteBancaire::consulterSolde() const {
    return solde;
}

void CompteBancaire::modifierSolde(double nouveauSolde) {
    solde = nouveauSolde;
}

Client::Client() : nom("MLK"), prenom("HIBA"), idClient("23454"), compte() {}

Client::Client(string n, string p, string id, CompteBancaire* cpt)
    : nom(n), prenom(p), idClient(id), compte(cpt) {}

void Client::afficherInfos() const {
    cout << "Nom: " << nom << ", Prénom: " << prenom << ", ID Client: " << idClient << endl;
    if (compte != NULL) {
        cout << "Solde du compte: " << compte->consulterSolde() << " DIRHAM" << endl;
    } else {
        cout << "Aucun compte associé." << endl;
    }
}

void Client::effectuerDepot(double montant) {
    if (compte != NULL) {
        compte->effectuerDepot(montant);
    } else {
        cout << "Aucun compte associé pour effectuer un dépôt." << endl;
    }
}

void Client::effectuerRetrait(double montant) {
    if (compte != NULL) {
        if (!compte->effectuerRetrait(montant)) {
            cout << "Retrait échoué. Fonds insuffisants." << endl;
        }
    } else {
        cout << "Aucun compte associé pour effectuer un retrait." << endl;
    }
}

void Client::associerCompte(CompteBancaire* cpt) {
    compte = cpt;
}

GuichetAutomatique::GuichetAutomatique(string pinInitial, CompteBancaire* cpt)
    : codePin(pinInitial), compte(cpt), tentatives(0) {}

bool GuichetAutomatique::authentifierUtilisateur(const string& pinSaisi) {
    if (pinSaisi == codePin) {
        tentatives = 0;
        return true;
    } else {
        tentatives++;
        cout << "Code PIN incorrect ! Tentatives restantes : " << 3 - tentatives << endl;
        return false;
    }
}

bool GuichetAutomatique::changerCodePin(const string& ancienPin, const string& nouveauPin) {
    if (ancienPin == codePin) {
        codePin = nouveauPin;
        cout << "Code PIN changé avec succès !" << endl;
        return true;
    } else {
        cout << "Échec : Ancien code PIN incorrect." << endl;
        return false;
    }
}

void GuichetAutomatique::afficherMenu() {
    cout << "\n=== MENU DU GUICHET AUTOMATIQUE ===" << endl;
    cout << "1. Consulter le solde" << endl;
    cout << "2. Effectuer un dépôt" << endl;
    cout << "3. Effectuer un retrait" << endl;
    cout << "4. Quitter" << endl;
}

void GuichetAutomatique::consulterSolde() const {
    if (compte != NULL) {
        cout << "Votre solde est : " << compte->consulterSolde() << " DIRHAM" << endl;
    } else {
        cout << "Aucun compte associé." << endl;
    }
}

bool GuichetAutomatique::effectuerRetrait(double montant) {
    if (compte != NULL) {
        return compte->effectuerRetrait(montant);
    } else {
        cout << "Aucun compte associé pour effectuer un retrait." << endl;
        return false;
    }
}

void GuichetAutomatique::effectuerDepot(double montant) {
    if (compte != NULL) {
        compte->effectuerDepot(montant);
    } else {
        cout << "Aucun compte associé pour effectuer un dépôt." << endl;
    }
}

void GuichetAutomatique::pauseAvecAnimation(const string& message, int secondes) const {
    Animation::pauseAvecAnimation(message, secondes);
}

// Implementation de l'interface utilisateur
 void InterfaceATM::afficherBanniere(const string& titre) {
    cout << "\n======================================" << endl;
    cout << setw(20) << titre << endl;
    cout << "======================================\n" << endl;
}

void InterfaceATM::afficherMenuPrincipal() {
    afficherBanniere("MENU PRINCIPAL");
    cout << "1. Consulter le solde" << endl;
    cout << "2. Effectuer un dépôt" << endl;
    cout << "3. Effectuer un retrait" << endl;
    cout << "4. Quitter" << endl;
    cout << "======================================\n" << endl;
    cout << "Votre choix : ";
}


