//
// Created by utilizator on 23.03.2022.
//

#include "Facultate.h"
#include <iostream>
#include <algorithm>

Facultate::Facultate(std::string nume, std::vector<Student> St, std::vector<Profesor> Pr, const Secretariat &Sec)
        :nume{std::move(nume)}, St{std::move(St)}, Pr{std::move(Pr)}, Sec(Sec) {
}

Facultate::Facultate(const Facultate &other) :nume(other.nume), St(other.St), Pr(other.Pr), Sec(other.Sec)
{
    this -> nume = other.nume;
    this -> St = other.St;
    this -> Pr = other.Pr;
    this -> Sec = other.Sec;
}

void Facultate::student_leaves(const Student &s) {
    for(int i = 0; i < this -> St.size(); i++) {
        if(this -> St[i] == s) {
            for(int j = i; j < this -> St.size() - 1; j++)
                this -> St[j] = this -> St[j + 1];
            break;
        }
    }
    this -> St.pop_back();
}

void Facultate::student_nou(const Student &s) {
    this -> St.push_back(s);
}

std::vector<Student> Facultate::get_studenti() {
    return St;
}

int Facultate::find_student(const Student &s) {
    int ans = 0;
    for(int i = 0; i < this -> St.size(); i++)
        if(this -> St[i] == s) {
            ans = i;
            return ans;
        }
    return ans;
}

void Facultate::update_student(const Student &s1, const Student &s2) {
    int x = Facultate::find_student(s1);
    this -> St[x] = s2;
}

int Facultate::find_prof(const Profesor &pr) {
    int ans = 0;
    for(int i = 0; i < this -> Pr.size(); i++) {
        if(this -> Pr[i] == pr) {
            ans = i;
            return ans;
        }
    }
    return ans;
}

void Facultate::update_prof(const Profesor &pr1, const Profesor &pr2) {
    int x = Facultate::find_prof(pr1);
    this -> Pr[x] = pr2;
}

void Facultate::update_secretariat(const Secretariat &sec) {
    this -> Sec = sec;
}

std::ostream &operator<<(std::ostream &os, const Facultate &f) {
    os << "Nume facultate: " << f.nume << '\n';
    os << '\n';
    os << "Studenti:\n";
    for(const auto & i : f.St)
    {
        os << i.get_nume() << ' ';
        os << i.get_grupa() << ' ';
        os << i.get_medie() << ' ';
        os << '\n';
    }
    os << '\n';
    os << '\n';
    os << "Profesori:\n";
    for(const auto & i : f.Pr)
    {
        os << i.get_nume() << ' ';
        for(int j : i.get_grupe())
            os << j << ' ';
        os << '\n';
    }
    os << '\n';
    os << "Secretariat:\n";
    os << f.Sec.get_numar_angajati() << ' ' << f.Sec.get_secretar_sef() << '\n';
    return os;
}
