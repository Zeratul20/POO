//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_PROFESOR_H
#define MAIN_CPP_PROFESOR_H


#include <string>

class Profesor {
    std::string nume;
    std::vector<int>grupe;
public:
    Profesor(std::string nume, std::vector<int>grupe);
    Profesor(const Profesor &other);
    Profesor() = default;

    explicit Profesor(std::string nume);

    ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const;
    [[nodiscard]] std::vector<int> get_grupe() const;

    bool operator==(const Profesor &other);

    void sortare_grupe();

    void prof_leave_group(int grupa);
    void prof_add_group(int grupa);
    virtual void prof_add_group() {
        this -> grupe.push_back(160);
        std::sort(this -> grupe.begin(), this -> grupe.end());
    }

    void prof_add_group2() {
        this -> grupe.push_back(170);
        std::sort(this -> grupe.begin(), this -> grupe.end());
    }

    Profesor &operator=(const Profesor &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};

class Laborant:public Profesor {
    std::string nume;
    std::vector<int>grupe;
    std::string materie;
public:
    Laborant(std::string nume, std::vector<int>grupe, std::string materie):nume(nume), grupe(grupe), materie(materie) {}
    Laborant(std::string nume, std::vector<int>grupe):nume(nume), grupe(grupe) {}
    Laborant(const Laborant &other) {
        this -> nume = other.nume;
        this -> grupe = other.grupe;
        this -> materie = other.materie;
    }

    std::string get_materie() {
        return materie;
    }

    void schimbare_materie(std::string materie_noua) {
        this -> materie = materie_noua;
    }
    void prof_add_group() {
        this -> grupe.push_back(161);
        std::sort(this -> grupe.begin(), this -> grupe.end());
    }
    void prof_add_group2() {
        this -> grupe.push_back(171);
        std::sort(this -> grupe.begin(), this -> grupe.end());
    }
    friend std::ostream &operator<<(std::ostream &os, const Laborant &lab);
};


#endif //MAIN_CPP_PROFESOR_H
