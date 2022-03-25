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

    void student_leaves(const Student& s);

    void student_nou(const Student& s);

    std::vector<Student> get_studenti();

    int find_student(const Student& s);

    void update_student(const Student& s1, const Student& s2);

    int find_prof(const Profesor& pr);

    void update_prof(const Profesor& pr1, const Profesor& pr2);

    void update_secretariat(const Secretariat& sec);
    friend std::ostream &operator<<(std::ostream &os, const Facultate &f);
};



#endif //MAIN_CPP_FACULTATE_H
