//
// Created by utilizator on 23.03.2022.
//
#include <iostream>
#include <utility>
#include "Student.h"

Student::Student(std::string nume, int grupa, double medie) :nume{std::move(nume)}, grupa{grupa}, medie{medie} {}

Student::Student(std::shared_ptr<Student> const &other) : nume(other->nume), grupa(other->grupa), medie(other->medie) {
    /*this -> nume = other->nume;
    this -> grupa = other->grupa;
    this -> medie = other->medie;*/
}



std::string Student::get_nume() const {
    return nume;
}

int Student::get_grupa() const {
    return grupa;
}

double Student::get_medie() const {
    return medie;
}

std::ostream &operator<<(std::ostream &os, const Student &st) {
    os << st.nume << ' ';
    os << st.grupa << ' ';
    os << st.medie << ' ';
    return os;
}

void Student::schimbare_grupe_2_studenti(const std::shared_ptr<Student>& s2) {
    std::swap(this -> grupa, s2->grupa);
}

bool operator==(const std::shared_ptr<Student>& st1, const std::shared_ptr<Student>& st2) {
    if(st1 -> nume == st2 -> nume and st1 -> grupa == st2 -> grupa and st1 -> medie == st2 -> medie)
        return true;
    return false;
}

void Student::transfer_grupa(int grupa_noua) {
    this -> grupa = grupa_noua;
}

Student &Student::operator=(const std::shared_ptr<Student> &other) {
    nume = other -> nume;
    grupa = other -> grupa;
    medie = other -> medie;
    return *this;
}

void Student::swap(std::shared_ptr<Student> &st1, std::shared_ptr<Student> &st2) {
    std::shared_ptr<Student> aux;
    aux = st1;
    st1 = st2;
    st2 = aux;
}

void Student::creste_medie(double marire) {
    medie += marire;
}


///STUDENT BURSANT

Student_bursant::Student_bursant(std::shared_ptr<Student> s, int bursa) : s(std::move(s)), bursa(bursa) {}

Student_bursant::Student_bursant(std::shared_ptr<Student> s) : s(std::move(s)) {}

std::ostream &operator<<(std::ostream &os, const Student_bursant &st_b) {
    os << *st_b.s;
    os << st_b.bursa;
    return os;
}

Student_bursant::Student_bursant(std::shared_ptr<Student_bursant> const &other) : s(other -> s), bursa(other -> bursa) {
    /*this -> s = other.s;
    this -> bursa = other.bursa;*/
}

/*Student_bursant::Student_bursant(const Student_bursant &other) : s(s) {
    this -> s = other.s;
}*/

void Student_bursant::modificare_bursa(int val) {
    this -> bursa += val;
}

int Student_bursant::get_grupa() {
    return s -> get_grupa();
}

int Student_bursant::get_bursa() const {
    return bursa;
}

/*std::shared_ptr<Student> Student_bursant::get_student() {
    return s;
}*/

void Student_bursant::transfer_grupa(int grupa_noua) {
    this -> grupa = grupa_noua;
    std::cout << "\nAJUNG IN DER STUDENT TRANSFER\n";
}

void Student_bursant::set_medie() {
    medie = s -> get_medie();
}

double Student_bursant::get_medie() {
    return medie;
}

void Student_bursant::creste_medie(double marire) {
    ///Studentul bursant are o marire de 1.5 ori mare mare decat studentul normal.
    this -> medie += 1.5 * marire;
}

Student_bursant &Student_bursant::operator=(std::_Bit_reference &other) {
    std::swap(reinterpret_cast<bool &>(*this), other);
    return *this;
}
