//
// Created by utilizator on 23.03.2022.
//

#include "Facultate.h"
#include <iostream>
#include <algorithm>
#include <utility>

Facultate::Facultate(std::string nume, std::vector<std::shared_ptr<Student>> St, std::vector<Profesor> Pr, const Secretariat &Sec)
        :nume{std::move(nume)}, St{std::move(St)}, Pr{std::move(Pr)}, Sec(Sec) {
}

Facultate::Facultate(const Facultate &other) = default;

void Facultate::student_leaves(const std::shared_ptr<Student>& s) {
    for(int i = 0; i < this -> St.size(); i++) {
        if(this -> St[i] == s) {
            for(int j = i; j < this -> St.size() - 1; j++)
                this -> St[j] = this -> St[j + 1];
            break;
        }
    }
    this -> St.pop_back();
}

void Facultate::student_nou(const std::shared_ptr<Student>& s) {
    this -> St.push_back(s);
}

std::vector<std::shared_ptr<Student>> Facultate::get_studenti() {
    return St;
}

int Facultate::find_student(const std::shared_ptr<Student>& s) {
    int ans = 0;
    for(int i = 0; i < this -> St.size(); i++)
        if(this -> St[i] == s) {
            ans = i;
            return ans;
        }
    return ans;
}

void Facultate::update_student(const Student &s1, std::shared_ptr<Student> s2) {
    int x = Facultate::find_student((const std::shared_ptr<Student> &) s1);
    this -> St[x] = std::move(s2);
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
        os << i->get_nume() << ' ';
        os << i->get_grupa() << ' ';
        os << i->get_medie() << ' ';
        os << '\n';
    }
    os << '\n';
    os << '\n';
    os << "Profesori:\n";
    for(const auto & prof : f.Pr)
    {
        os << prof.get_nume() << ' ';
        for(int grupa : prof.get_grupe())
            os << grupa << ' ';
        os << '\n';
    }
    os << '\n';
    os << "Secretariat:\n";
    os << f.Sec.get_numar_angajati() << ' ' << f.Sec.get_secretar_sef() << '\n';
    return os;
}
