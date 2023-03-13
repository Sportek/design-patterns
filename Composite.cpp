#include <iostream>
#include <vector>
using namespace std;
/*
 * Création d'une classe abstraite permettant
 * de générer facilement des classes qui auront
 * les attributs qui reviennent pour chaque composants.
 * */
class Composant {
public:
    virtual void operation() = 0;
    virtual ~Composant() = default;
};

/*
 * Première classe de base
 * */
class Feuille : public Composant {
public:
    void operation() override {
        cout << "Opération de feuille" << endl;
    }
};

/*
 * Classe qui contient d'autres Composants
 * et ce à l'infini.
 * */
class Composite : public Composant {
public:
    void ajouterComposant(Composant* composant) {
        composants_.push_back(composant);
    }
    /*
     * Lorsqu'on fait une opération, on l'effectue pour
     * l'ensemble des éléments. On pourrait donc ainsi
     * déplacer l'ensemble des éléments en même temps.
     * */
    void operation() override {
        cout << "Opération de composite" << endl;
        for (auto& composant: composants_) {
            composant->operation();
        }
    }
private:
    vector<Composant*> composants_;
};

int main() {
    Composite composite;
    Feuille feuille1;
    Feuille feuille2;
    composite.ajouterComposant(&feuille1);
    composite.ajouterComposant(&feuille2);
    composite.operation();
}

// Valeurs de retour en console :
// Opération de composite
// Opération de feuille
// Opération de feuille
