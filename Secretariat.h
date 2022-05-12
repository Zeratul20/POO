//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_SECRETARIAT_H
#define MAIN_CPP_SECRETARIAT_H

#include <string>
#include <utility>
#include <iostream>
#include <memory>

class Secretariat {
    int numar_angajati{};
    std::string secretar_sef;
public:
    Secretariat(int numar_angajati, std::string secretar_sef);
    Secretariat() = default;
    Secretariat(const Secretariat &other);

    [[nodiscard]] virtual int get_numar_angajati() const;
    [[nodiscard]] std::string get_secretar_sef() const;
    ~Secretariat() = default;
    virtual void vin_secretari(int nr_noi);
    void schimb_secretar_sef(std::string nume);
    virtual void operator++();

    Secretariat &operator=(const Secretariat &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Secretariat &sec);
};

class Diviziuni_Secretariat:public Secretariat {
    int numar_angajati{};
    int an;
public:
    [[nodiscard]] std::shared_ptr<Secretariat> clone() const;
    Diviziuni_Secretariat(int numar_angajati, int an): numar_angajati(numar_angajati), an(an) {}
    [[nodiscard]] int get_numar_angajati() const override;
    [[nodiscard]] int get_an() const {
        return this -> an;
    }
    void vin_secretari(int nr_noi) override {
        this -> numar_angajati += nr_noi / 3;
    }
};


#endif //MAIN_CPP_SECRETARIAT_H
