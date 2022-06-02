//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_PROFESOR_H
#define MAIN_CPP_PROFESOR_H


#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include "Exceptie.h"

class Profesor {
protected:
    std::string nume;
    std::vector<int>grupe;
    int salar{};
public:
    Profesor(std::string nume, std::vector<int>grupe, int salar);
    Profesor(const Profesor &other);
    Profesor(std::string nume, std::vector<int> grupe):nume(std::move(nume)), grupe(std::move(grupe)) {}
    Profesor() = default;

    explicit Profesor(std::string nume);

    virtual ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const;
    [[nodiscard]] std::vector<int> get_grupe() const;

    [[nodiscard]] virtual double get_salar() const;

    void marire_salar(int bonus);

    bool operator==(const Profesor &other);

    void sortare_grupe();

    void leave_group(int grupa);
    virtual void add_group(int grupa);

    Profesor &operator=(const Profesor &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
    void check_nr_grupe() {
        std::cout << "AM AJUNS AICI\n";
        if(this -> grupe.size() < 2)
            throw eroare_profesor("");
        std::cout << "Numarul de grupe" << '\n' << this -> grupe.size();
    }
};

class Laborant:public Profesor {
    std::string materie;
    double salar{};
public:

    Laborant(std::string nume, std::vector<int>grupe, std::string materie, int salar);
    Laborant(std::string nume, std::vector<int>grupe, int salar);

    std::string get_materie();
    [[nodiscard]] double get_salar() const override;

    void marire_salar(double bonus) ;

    void schimbare_materie(std::string materie_noua);
    void add_group(int grupa) override;
    friend std::ostream &operator<<(std::ostream &os, const Laborant &lab);
    ~Laborant() override = default;
};


#endif //MAIN_CPP_PROFESOR_H
