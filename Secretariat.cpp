//
// Created by utilizator on 23.03.2022.
//
#include <iostream>
#include "Secretariat.h"
#include <algorithm>

Secretariat::Secretariat(int numar_angajati, std::string secretar_sef)
        :numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)} {
    /*this -> numar_angajati = numar_angajati;
    this -> secretar_sef = secretar_sef;*/
    //std::cout<<"Secretariat init\n";
}

Secretariat::Secretariat(const Secretariat &other)
        :numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef) {
    this -> numar_angajati = other.numar_angajati;
    this -> secretar_sef = other.secretar_sef;
    //std::cout<<"CC secretariat\n";
}

int Secretariat::get_numar_angajati() const {
    return numar_angajati;
}

std::string Secretariat::get_secretar_sef() const {
    return secretar_sef;
}

void Secretariat::vin_secretari(Secretariat &sec, int nr_noi) {
    sec.numar_angajati += nr_noi;
}

std::ostream &operator<<(std::ostream &os, const Secretariat &sec) {
    os << sec.numar_angajati << ' ';
    os << sec.secretar_sef << ' ';
    return os;
}
