//
// Created by utilizator on 23.03.2022.
//
#include <iostream>
#include "Student.h"

Student::Student(std::string nume, int grupa, double medie) :nume{std::move(nume)}, grupa{grupa}, medie{medie} {
}

Student::Student(const Student &other) :nume(other.nume), grupa(other.grupa), medie(other.medie) {
    this -> nume = other.nume;
    this -> grupa = other.grupa;
    this -> medie = other.medie;
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

void Student::transfer_grupa(int grupa_noua) {
    this -> grupa = grupa_noua;
}

void Student::schimbare_grupe_2_studenti(Student &s2) {
    std::swap(this -> grupa, s2.grupa);
}

bool Student::operator==(const Student &other) {
    if(this -> nume == other.nume and this -> grupa == other.grupa and this -> medie == other.medie)
        return true;
    return false;
}
