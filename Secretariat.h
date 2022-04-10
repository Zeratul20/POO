//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_SECRETARIAT_H
#define MAIN_CPP_SECRETARIAT_H

#include <string>

class Secretariat {
    int numar_angajati;
    std::string secretar_sef;
public:
    Secretariat(int numar_angajati, std::string secretar_sef);
    Secretariat(const Secretariat &other);
    [[nodiscard]] int get_numar_angajati() const;
    [[nodiscard]] std::string get_secretar_sef() const;
    ~Secretariat() = default;
    void vin_secretari(int nr_noi);
    void schimb_secretar_sef(std::string nume);

    Secretariat &operator=(const Secretariat &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Secretariat &sec);
};


#endif //MAIN_CPP_SECRETARIAT_H
