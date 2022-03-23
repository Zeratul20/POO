//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_FACULTATE_H
#define MAIN_CPP_FACULTATE_H

#include <string>
#include <vector>
#include "Secretariat.h"
#include "Profesor.h"
#include "Student.h"


class Facultate {
    std::string nume;
    std::vector<Student>St;
    std::vector<Profesor>Pr;
    Secretariat Sec;
public:
    Facultate(std::string nume, std::vector<Student>St, std::vector<Profesor>Pr, const Secretariat& Sec);
    Facultate(const Facultate &other);
    Facultate &operator=(const Facultate &other) = default;
    ~Facultate() = default;

    static void student_leaves(Facultate &f, const Student& s);

    static void student_nou(Facultate &f, const Student& s);

    std::vector<Student> get_studenti();

    static int find_student(Facultate &f, const Student& s);

    static void update_student(Facultate &f, const Student& s1, const Student& s2);

    static int find_prof(Facultate &f, const Profesor& pr);

    static void update_prof(Facultate &f, const Profesor& pr1, const Profesor& pr2);

    static void update_secretariat(Facultate &f, const Secretariat& sec);
    friend std::ostream &operator<<(std::ostream &os, const Facultate &f);
};



#endif //MAIN_CPP_FACULTATE_H
