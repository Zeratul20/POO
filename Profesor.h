//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_PROFESOR_H
#define MAIN_CPP_PROFESOR_H


#include <string>
#include <utility>
#include <vector>
#include <algorithm>

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

    [[nodiscard]] virtual int get_salar() const {
        return salar;
    }

    virtual void marire_salar(int bonus) {
        salar += bonus;
    }

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
    Laborant(std::string nume, std::vector<int>grupe, std::string materie, int salar):nume(std::move(nume)), grupe(std::move(grupe)), materie(std::move(materie)), salar(salar) {}
    Laborant(std::string nume, std::vector<int>grupe, int salar):nume(std::move(nume)), grupe(std::move(grupe)), salar(salar) {}
    Laborant(const Laborant &other)  : Profesor(other) {
        this -> nume = other.nume;
        this -> grupe = other.grupe;
        this -> materie = other.materie;
        this -> salar = other.salar;
    }

    std::string get_materie() {
        return materie;
    }
    [[nodiscard]] int get_salar() const override {
        return salar;
    }

    void marire_salar(int bonus) override {
        //Laborantul primeste doar 10% din acea marire.
        salar += bonus/10;
    }

    void schimbare_materie(std::string materie_noua) {
        this -> materie = std::move(materie_noua);
    }
    void prof_add_group(int grupa) override {
        this -> grupe.push_back(grupa+1);
        std::sort(this -> grupe.begin(), this -> grupe.end());
    }
    friend std::ostream &operator<<(std::ostream &os, const Laborant &lab);
    ~Laborant() override = default;
};


#endif //MAIN_CPP_PROFESOR_H
