//
// Created by utilizator on 23.03.2022.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Profesor.h"
#include <algorithm>

Profesor::Profesor(std::string nume) : nume(std::move(nume)) {}
Profesor::Profesor(std::string nume, std::vector<int> grupe) :nume{std::move(nume)}, grupe{std::move(grupe)} {}
Profesor::Profesor(const Profesor &other) :nume(other.nume), grupe(other.grupe) {
    this -> nume = other.nume;
    this -> grupe = other.grupe;
}

std::string Profesor::get_nume() const {
    return nume;
}

std::vector<int> Profesor::get_grupe() const {
    return grupe;
}

bool Profesor::operator==(const Profesor &other) {
    if(this -> nume == other.nume and this -> grupe == other.grupe)
        return true;
    return false;
}

void Profesor::sortare_grupe() {
    std::sort(this -> grupe.begin(), this -> grupe.end());
}

void Profesor::prof_leave_group(int grupa) {
    for(int i = 0; i < this -> grupe.size(); i++) {
        if(this -> grupe[i] == grupa) {
            for(int j = i; j < this -> grupe.size() - 1; j++)
                this -> grupe[j] = this -> grupe[j + 1];
            break;
        }
    }
    this -> grupe.pop_back();
    std::sort(this -> grupe.begin(), this -> grupe.end());
}

void Profesor::prof_add_group(int grupa) {
    this -> grupe.push_back(grupa);
    std::sort(this -> grupe.begin(), this -> grupe.end());
}

std::ostream &operator<<(std::ostream &os, const Profesor &pr) {
    os << pr.nume << '\n';
    for(int i : pr.grupe) {
        os << i << ' ';
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Laborant &lab) {
    os << lab.nume << '\n';
    for(int i : lab.grupe) {
        os << i << ' ';
    }
    os << '\n';
    os << lab.materie << '\n';
    return os;
}
