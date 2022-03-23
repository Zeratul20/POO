//
// Created by utilizator on 23.03.2022.
//

#include <vector>
#include <iostream>
#include "Profesor.h"
#include <algorithm>

Profesor::Profesor(const std::string &nume) : nume(nume) {}
Profesor::Profesor(std::string nume, std::vector<int> grupe) :nume{std::move(nume)}, grupe{std::move(grupe)} {
}
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

void Profesor::sortare_grupe(Profesor &pr) {
    std::sort(pr.grupe.begin(), pr.grupe.end());
}

void Profesor::prof_leave_group(Profesor &pr, int grupa) {
    for(int i = 0; i < pr.grupe.size(); i++) {
        if(pr.grupe[i] == grupa) {
            for(int j = i; j < pr.grupe.size() - 1; j++)
                pr.grupe[j] = pr.grupe[j + 1];
            break;
        }
    }
    pr.grupe.pop_back();
    std::sort(pr.grupe.begin(), pr.grupe.end());
}

void Profesor::prof_add_group(Profesor &pr, int grupa) {
    pr.grupe.push_back(grupa);
    std::sort(pr.grupe.begin(), pr.grupe.end());
}

std::ostream &operator<<(std::ostream &os, const Profesor &pr) {
    os << pr.nume << '\n';
    for(int i : pr.grupe) {
        os << i << ' ';
    }
    return os;
}
