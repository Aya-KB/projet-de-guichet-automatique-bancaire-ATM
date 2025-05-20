#include <iostream>
#include "gab.h"
#include <iomanip>
void afficherBanniere(const string& message) {
    cout << "\n==========================================" << endl;
    cout << "           " << message << endl;
    cout << "==========================================" << endl;
}

void afficherSeparateur() {
    cout << "\n------------------------------------------" << endl;
}

int main() {

    CompteBancaire compte1(5000);
    
    Client client1("HIBA", "MLK", "1234", &compte1);

    // Création du guichet automatique
    GuichetAutomatique gab("1234", &compte1);

    afficherBanniere("Bienvenue au Guichet Automatique");

    string pin;
    cout << "\n Veuillez entrer votre code PIN : ";
    cin >> pin;

    if (!gab.authentifierUtilisateur(pin)) {
        cout << "\n Accès refusé. Merci de réessayer plus tard." << endl;
        return 0;
    }

    afficherSeparateur();
    cout << " Authentification réussie ! Accès autorisé." << endl;

    int choix;
    do {
        afficherBanniere("Menu Principal");
        gab.afficherMenu();

        cout << "[??] Votre choix : ";
        cin >> choix;

        afficherSeparateur();

        switch (choix) {
        case 1:
            cout << "Consultation du solde en cours...\n";
            gab.consulterSolde();
            break;

        case 2: {
            double montant;
            cout << "Montant à déposer : ";
            cin >> montant;
            gab.effectuerDepot(montant);
            cout << " Dépôt effectué avec succès." << endl;
            break;
        }

        case 3: {
            double montant;
            cout << "Montant à retirer : ";
            cin >> montant;
            if (gab.effectuerRetrait(montant)) {
                cout << " Retrait effectué avec succès." << endl;
            } else {
                cout << " Retrait échoué. Fonds insuffisants." << endl;
            }
            break;
        }

        case 4:
            afficherSeparateur();
            cout << " Merci d'avoir utilisé notre service. À bientôt !" << endl;
            break;

        default:
            cout << " Choix invalide. Veuillez réessayer." << endl;
        }

        afficherSeparateur();
        gab.pauseAvecAnimation("Retour au menu principal", 2);

    } while (choix != 4);

    return 0;
}



