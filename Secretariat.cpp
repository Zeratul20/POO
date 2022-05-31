//
// Created by utilizator on 23.03.2022.
//
#include <iostream>
#include "Secretariat.h"
#include <algorithm>
#include <utility>

template<typename T1, typename T2>
Secretariat<T1, T2>::Secretariat(T1 numar_angajati, T2 secretar_sef)
        :numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)} {
}

template<typename T1, typename T2>
Secretariat<T1, T2>::Secretariat(const Secretariat &other)
        :numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef) {
    this -> numar_angajati = other.numar_angajati;
    this -> secretar_sef = other.secretar_sef;
}

template<typename T1, typename T2>
T1 Secretariat<T1, T2>::get_numar_angajati() const {
    std::cout << "\nGetter din baza\n";
    return numar_angajati;
}

template<typename T1, typename T2>
T2 Secretariat<T1, T2>::get_secretar_sef() const {
    return secretar_sef;
}

template<typename T1, typename T2>
void Secretariat<T1, T2>::vin_secretari(T1 nr_noi) {
    this -> numar_angajati += nr_noi;
}


/*template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const Secretariat<T1, T2> &sec) {
    os << sec.numar_angajati << ' ';
    os << sec.secretar_sef << ' ';
    return os;
}*/


template<typename T1, typename T2>
void Secretariat<T1, T2>::schimb_secretar_sef(T2 nume) {
    this -> secretar_sef = std::move(nume);
}

template<typename T1, typename T2>
void Secretariat<T1, T2>::operator++() {
    this -> numar_angajati++;
}

template<typename T1, typename T2>
T1 Secretariat<T1, T2>::get_nrRelatiicuStudentii() const{
    return nrRelatiicuStudentii;
}

template<typename T1, typename T2>
T1 Secretariat<T1, T2>::get_nrRelatiicuProfii() const{
    return nrRelatiicuProfii;
}

template<typename T1, typename T2>
T2 Secretariat<T1, T2>::get_tipSecretar() const{
    return tipSecretar;
}

std::shared_ptr<Secretariat<int, std::string>> Diviziuni_Secretariat::clone() const {
    std::cout << "\nAm intrat in clone\n";
    return std::make_shared<Diviziuni_Secretariat>(*this);
}

int Diviziuni_Secretariat::get_numar_angajati() const {
    std::cout << "\nGetter din derivata\n";
    return numar_angajati;
}

template class
        Secretariat<int, std::string>;


