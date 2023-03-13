#include <iostream>
#include <vector>
using namespace std;
/*
 * Cette classe abstraite permet surtout de définir une base commune pour tous
 * les itérateurs, non seulement pour les itérateurs de vecteurs. Ainsi, il est
 * plus simple de créer d'autres itérateurs.
 * */
class Iterator {
public:
    virtual void next() = 0;
    virtual bool end() const = 0;
    virtual int value() const = 0;
    virtual ~Iterator() = default;
};
/*
 * Classe spécifique à ce qu'on souhaite itérer.
 * Permet une spécialisation de la classe Iterator.
 * */
class IteratorVector : public Iterator {
public:
    IteratorVector(const vector<int>& vector): vector_(vector), index_(0) {};
    void next() override {
        this->index_++;
    }
    bool end() const override {
        return this->index_ == this->vector_.size();
    }
    int value() const override {
        return this->vector_[this->index_];
    }

private:
    const vector<int>& vector_;
    int index_;
};

/*
 * Classe dans laquelle on souhaite itérer, peut être
 * sensiblement n'importe quoi.
 * */
class ClassToIterate {
public:
    void add(int value) {
        this->vector_.push_back(value);
    }
    Iterator* createIterator() {
        return new IteratorVector(this->vector_);
    }
private:
    vector<int> vector_;
};

int main() {
    ClassToIterate classToIterate;
    classToIterate.add(1);
    classToIterate.add(2);
    classToIterate.add(3);

    Iterator* iterator = classToIterate.createIterator();

    while(!iterator->end()) {
        cout << iterator->value() << endl;
        iterator->next();
    }
    delete iterator;
}

// Valeurs de retour en console :
// 1
// 2
// 3