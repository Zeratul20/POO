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

class Profesor {
    std::string nume;
    std::vector<int>grupe;
    int salar{};
public:
    Profesor(std::string nume, std::vector<int>grupe, int salar);
    Profesor(const Profesor &other);
    Profesor() = default;

    explicit Profesor(std::string nume);

    virtual ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const;
    [[nodiscard]] std::vector<int> get_grupe() const;

    [[nodiscard]] virtual int get_salar() const;

    virtual void marire_salar(int bonus);

    bool operator==(const Profesor &other);

    void sortare_grupe();

    void prof_leave_group(int grupa);
    virtual void prof_add_group(int grupa);

    Profesor &operator=(const Profesor &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};

class Laborant:public Profesor {
    std::string nume;
    std::vector<int>grupe;
    std::string materie;
    int salar{};
public:
    Laborant(std::string nume, std::vector<int>grupe, std::string materie, int salar);
    Laborant(std::string nume, std::vector<int>grupe, int salar);
    Laborant(const Laborant &other);

    std::string get_materie();
    [[nodiscard]] int get_salar() const override;

    void marire_salar(int bonus) override;

    void schimbare_materie(std::string materie_noua);
    void prof_add_group(int grupa) override;
    friend std::ostream &operator<<(std::ostream &os, const Laborant &lab);
    ~Laborant() override = default;
    Laborant(Laborant &other)  : Profesor(other) {
        std::cout << "\nA intrat in copy and swap constructor!" << '\n';
        std::swap(this -> nume, other.nume);
        std::vector<int>aux;
        aux.clear();
        for(auto grupa:this -> grupe) {
            aux.push_back(grupa);
        }
        this -> grupe.clear();
        for(auto grupa:other.grupe) {
            this -> grupe.push_back(grupa);
        }
        other.grupe.clear();
        for(auto grupa:aux) {
            other.grupe.push_back(grupa);
        }
        std::swap(this -> materie, other.materie);
        std::swap(this -> salar, other.salar);
    }
};


#endif //MAIN_CPP_PROFESOR_H
