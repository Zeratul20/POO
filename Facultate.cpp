//
// Created by utilizator on 23.03.2022.
//

#include "Facultate.h"
#include <iostream>
#include <algorithm>

Facultate::Facultate(std::string nume, std::vector<Student> St, std::vector<Profesor> Pr, const Secretariat &Sec)
        :nume{std::move(nume)}, St{std::move(St)}, Pr{std::move(Pr)}, Sec(Sec) {
    /*this -> nume = nume;
    this -> St = St;
    this -> Pr = Pr;
    this -> Sec = Sec;*/
    //std::cout<<"init facultate\n";
}

Facultate::Facultate(const Facultate &other) :nume(other.nume), St(other.St), Pr(other.Pr), Sec(other.Sec)
{
    this -> nume = other.nume;
    this -> St = other.St;
    this -> Pr = other.Pr;
    this -> Sec = other.Sec;
    //std::cout<<"CC facultate\n";
}

void Facultate::student_leaves(Facultate &f, const Student &s) {
    for(int i = 0; i < f.St.size(); i++) {
        if(f.St[i] == s) {
            for(int j = i; j < f.St.size() - 1; j++)
                f.St[j] = f.St[j + 1];
            break;
        }
    }
    f.St.pop_back();
}

void Facultate::student_nou(Facultate &f, const Student &s) {
    f.St.push_back(s);
}

std::vector<Student> Facultate::get_studenti() {
    return St;
}

int Facultate::find_student(Facultate &f, const Student &s) {
    int ans = 0;
    for(int i = 0; i < f.St.size(); i++)
        if(f.St[i] == s) {
            ans = i;
            return ans;
        }
    return ans;
}

void Facultate::update_student(Facultate &f, const Student &s1, const Student &s2) {
    int x = Facultate::find_student(f, s1);
    f.St[x] = s2;
}

int Facultate::find_prof(Facultate &f, const Profesor &pr) {
    int ans = 0;
    for(int i = 0; i < f.Pr.size(); i++) {
        if(f.Pr[i] == pr) {
            ans = i;
            return ans;
        }
    }
    return ans;
}

void Facultate::update_prof(Facultate &f, const Profesor &pr1, const Profesor &pr2) {
    int x = Facultate::find_prof(f, pr1);
    f.Pr[x] = pr2;
}

void Facultate::update_secretariat(Facultate &f, const Secretariat &sec) {
    f.Sec = sec;
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
