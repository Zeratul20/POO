//
// Created by utilizator on 23.03.2022.
//

#include <utility>
#include <vector>
#include <iostream>
#include "Profesor.h"
#include <algorithm>

Profesor::Profesor(std::string nume) : nume(std::move(nume)) {}
Profesor::Profesor(std::string nume, std::vector<int> grupe, double salar) :nume{std::move(nume)}, grupe{std::move(grupe)}, salar(salar) {}
Profesor::Profesor(const Profesor &other) :nume(other.nume), grupe(other.grupe), salar(other.salar) {
    this -> nume = other.nume;
    this -> grupe = other.grupe;
    this -> salar = other.salar;
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

void Profesor::leave_group(int grupa) {
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

void Profesor::add_group(int grupa) {
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

double Profesor::get_salar() const {
    return salar;
}

void Profesor::marire_salar(double bonus) {
    salar += bonus;
}

std::ostream &operator<<(std::ostream &os, const Laborant &lab) {
    os << lab.nume << '\n';
    for(int i : lab.grupe) {
        os << i << ' ';
    }
    os << '\n';
    os << lab.materie << '\n';
    os << lab.salar << '\n';
    return os;
}

std::string Laborant::get_materie() {
    return materie;
}

double Laborant::get_salar() const {
    return salar;
}

void Laborant::marire_salar(double bonus) {
    //Laborantul primeste doar 10% din acea marire.
    salar += bonus/10;
}

void Laborant::schimbare_materie(std::string materie_noua) {
    this -> materie = std::move(materie_noua);
}

void Laborant::add_group(int grupa) {
    this -> grupe.push_back(grupa+1);
    std::sort(this -> grupe.begin(), this -> grupe.end());
}

Laborant::Laborant(std::string nume, std::vector<int> grupe, double salar, std::string materie)
        : Profesor(std::move(nume), std::move(grupe), salar), materie(std::move(materie)){}

Laborant::Laborant(std::string nume, std::vector<int> grupe, double salar)
        : Profesor(std::move(nume), std::move(grupe), salar){}
