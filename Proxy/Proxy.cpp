#include <iostream>
#include <string>

using namespace std;
class President {
public:
    virtual void request() = 0;
    virtual ~President() = default;
};

class PresidentReal : public President {
public:
    void request() override {
        cout << "Vrai président : gestion en cours de la requête." << endl;
    }
};

class Proxy : public President {
public:
    Proxy(President* president) : president_(president){}
    void request() override {
        if(check()) {
            president_->request();
        }
    }
private:
    President* president_;
    bool check() {
        cout << "Proxy: vérification effectuée." << endl;
        /*
         * Normalement, on ferait une vérification de permission
         * pour vraiment donner un intérêt à l'utilisation d'un proxy.
         * */
        return true;
    }
};

int main() {
    // Création de l'objet à protéger
    auto* presidentReal = new PresidentReal();

    // Création du protecteur
    auto* proxy = new Proxy(presidentReal);

    // Effectuer la requête avec le protecteur
    proxy->request();

    delete proxy;
    delete presidentReal;
}

// Valeurs de retour en console :
// Proxy: vérification effectuée.
// Vrai président : gestion en cours de la requête.