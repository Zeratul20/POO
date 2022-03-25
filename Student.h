//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H


#include <string>

class Student {
    std::string nume;
    int grupa{};
    double medie{};
public:
    Student(std::string nume, int grupa, double medie);
    Student(const Student &other);
    Student() = default;
    ~Student() = default;
    [[nodiscard]] std::string get_nume() const;
    [[nodiscard]] int get_grupa() const;

    [[nodiscard]] double get_medie() const;
    friend std::ostream &operator<<(std::ostream &os, const Student &st);


    void transfer_grupa(int grupa_noua);

    void schimbare_grupe_2_studenti(Student &s2);
    Student &operator=(const Student &other) = default;

    bool operator==(const Student& other);
};


#endif //MAIN_CPP_STUDENT_H
