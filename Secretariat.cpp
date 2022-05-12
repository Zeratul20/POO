//
// Created by utilizator on 23.03.2022.
//
#include <iostream>
#include "Secretariat.h"
#include <algorithm>
#include <utility>

Secretariat::Secretariat(int numar_angajati, std::string secretar_sef)
        :numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)} {
}

Secretariat::Secretariat(const Secretariat &other)
        :numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef) {
    this -> numar_angajati = other.numar_angajati;
    this -> secretar_sef = other.secretar_sef;
}

int Secretariat::get_numar_angajati() const {
    std::cout << "\nGetter din baza\n";
    return numar_angajati;
}

std::string Secretariat::get_secretar_sef() const {
    return secretar_sef;
}

void Secretariat::vin_secretari(int nr_noi) {
    this -> numar_angajati += nr_noi;
}



std::ostream &operator<<(std::ostream &os, const Secretariat &sec) {
    os << sec.numar_angajati << ' ';
    os << sec.secretar_sef << ' ';
    return os;
}

void Secretariat::schimb_secretar_sef(std::string nume) {
    this -> secretar_sef = std::move(nume);
}

void Secretariat::operator++() {
    this -> numar_angajati++;
}

std::shared_ptr<Secretariat> Diviziuni_Secretariat::clone() const {
    std::cout << "\nAm intrat in clone\n";
    return std::make_shared<Diviziuni_Secretariat>(*this);
}

int Diviziuni_Secretariat::get_numar_angajati() const {
    std::cout << "\nGetter din derivata\n";
    return numar_angajati;
}

