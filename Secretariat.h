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
    void vin_secretari(int nr_noi);
    void schimb_secretar_sef(std::string nume);
    static void g(Secretariat &sec) {
        sec.numar_angajati++;
    }

    Secretariat &operator=(const Secretariat &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Secretariat &sec);
};

class Diviziuni_Secretariat:public Secretariat {
    int numar_angajati{};
    std::string secretar_sef;
    int an;
public:
    [[nodiscard]] std::shared_ptr<Secretariat> clone() const  {
        std::cout << "\nAm intrat in clone\n";
        return std::make_shared<Diviziuni_Secretariat>(*this);
    }
    Diviziuni_Secretariat(int numar_angajati, std::string secretar_sef, int an): numar_angajati(numar_angajati), secretar_sef(std::move(secretar_sef)), an(an) {}
    Diviziuni_Secretariat( const Diviziuni_Secretariat &other)  : Secretariat(other) {
        this -> numar_angajati = other.numar_angajati;
        this -> secretar_sef = other.secretar_sef;
        this -> an = other.an;
    }
    [[nodiscard]] int get_numar_angajati() const override {
        std::cout << "\nGetter din derivata\n";
        return numar_angajati;
    }

};


#endif //MAIN_CPP_SECRETARIAT_H
