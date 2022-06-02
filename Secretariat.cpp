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

template<typename T1, typename T2>
Secretariat<T1, T2>::Secretariat(T1 numar_angajati):numar_angajati(numar_angajati) {}

template<typename T1, typename T2>
Secretariat<T1, T2>::Secretariat(T1 nrRelatiicuStudentii, T1 nrRelatiicuProfii, const T2 &tipSecretar)
        :nrRelatiicuStudentii(nrRelatiicuStudentii), nrRelatiicuProfii(nrRelatiicuProfii), tipSecretar(tipSecretar) {}

template<typename T1, typename T2>
void Secretariat<T1, T2>::setNrRelatiicuProfii() {
    nrRelatiicuProfii = numar_angajati - nrRelatiicuStudentii;
}

std::shared_ptr<Secretariat<int, std::string>> Diviziuni_Secretariat::clone() const {
    std::cout << "\nAm intrat in clone\n";
    return std::make_shared<Diviziuni_Secretariat>(*this);
}

int Diviziuni_Secretariat::get_numar_angajati() const {
    std::cout << "\nGetter din derivata\n";
    return numar_angajati;
}

Diviziuni_Secretariat::Diviziuni_Secretariat(int numar_angajati, int an) : Secretariat<int, std::string>(numar_angajati), an(an) {}

int Diviziuni_Secretariat::get_an() const {
    return this -> an;
}

void Diviziuni_Secretariat::vin_secretari(int nr_noi) {
    this -> numar_angajati += nr_noi / 3;
}

SecretariatBuilder::SecretariatBuilder(const Secretariat<int, std::string> &sec2) :sec(sec2) {
    std::cout << "\n\nSECRETARIAT BUILDER\n\n";
    sec.nrRelatiicuStudentii = sec2.nrRelatiicuStudentii;
    sec.nrRelatiicuProfii = sec2.nrRelatiicuProfii;
    sec.tipSecretar = sec2.tipSecretar;
}

SecretariatBuilder &SecretariatBuilder::nrRelatiicuStudentii(const int nr) {
    sec.nrRelatiicuStudentii = nr;
    return *this;
}

SecretariatBuilder &SecretariatBuilder::nrRelatiicuProfii(const int nr) {
    sec.nrRelatiicuProfii = nr;
    return *this;
}

SecretariatBuilder &SecretariatBuilder::tipSecretar(const std::string &tip) {
    sec.tipSecretar = tip;
    return *this;
}

Secretariat<int, std::string> SecretariatBuilder::build() {
    return sec;
}

std::ostream &operator<<(std::ostream &os, const SecretariatBuilder &builder) {
    os << "nrRelatiicuStudentii: " << builder.sec.get_nrRelatiicuStudentii() << "\nnrRelatiicuProfii: " << builder.sec.get_nrRelatiicuProfii() << "\ntipSecretar: " << builder.sec.get_tipSecretar() << '\n';
    return os;
}

template class
        Secretariat<int, std::string>;

template class
        Secretariat<int, int>;
