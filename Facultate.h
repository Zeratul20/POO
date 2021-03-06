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
#include <memory>

class Facultate {
    std::string nume;
    std::vector<std::shared_ptr<Student>>St;
    std::vector<Profesor>Pr;
    Secretariat<int, std::string> Sec;
public:
    Facultate(std::string nume, std::vector<std::shared_ptr<Student>>St, std::vector<Profesor>Pr, const Secretariat<int, std::string>& Sec);
    Facultate(const Facultate &other) = default;
    Facultate &operator=(const Facultate &other) = default;
    ~Facultate() = default;

    void student_leaves(const std::shared_ptr<Student>& s);

    void student_nou(const std::shared_ptr<Student>& s);

    std::vector<std::shared_ptr<Student>> get_studenti();

    int find_student(const std::shared_ptr<Student>& s);

    void update_student(const Student& s1, std::shared_ptr<Student> s2);

    void update_student(const std::shared_ptr<Student>& s1, std::shared_ptr<Student> s2);

    int find_prof(const Profesor& pr);

    void update_prof(const Profesor& pr1, const Profesor& pr2);

    void update_secretariat(const Secretariat<int, std::string>& sec);

    void make_student_bursant();


    std::shared_ptr<Student> first_student();

    friend std::ostream &operator<<(std::ostream &os, const Facultate &f);
};



#endif //MAIN_CPP_FACULTATE_H
