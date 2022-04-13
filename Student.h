//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H


#include <string>
#include <iostream>
#include <memory>
#include <utility>

class Student {
protected:
    std::string nume;
    int grupa{};
    double medie{};
public:
    Student(std::string nume, int grupa, double medie);
    explicit Student(std::shared_ptr<Student> &other);
    Student() = default;
    ~Student() = default;
    [[nodiscard]] std::string get_nume() const;

    [[nodiscard]] int get_grupa() const;

    [[nodiscard]] double get_medie() const;
    friend std::ostream &operator<<(std::ostream &os, const Student &st);


    virtual void transfer_grupa(int grupa_noua);

    void schimbare_grupe_2_studenti(const std::shared_ptr<Student>& s2);
    friend bool operator==(const std::shared_ptr<Student>& st1, const std::shared_ptr<Student>& st2);
    Student &operator=(std::shared_ptr<Student> &other) {
        nume = other -> nume;
        grupa = other -> grupa;
        medie = other -> medie;
        return *this;
    }

};

class Student_bursant: public Student {
    std::shared_ptr<Student> s;
    int bursa{};
public:
    Student_bursant(std::shared_ptr<Student> s, int bursa);

    explicit Student_bursant(std::shared_ptr<Student> s);

    explicit Student_bursant(std::shared_ptr<Student_bursant> &other);
    void transfer_grupa(int grupa_nouaa) override;

    void modificare_bursa(int val);

    [[nodiscard]] int get_grupa();
    [[nodiscard]] int get_bursa() const;
    Student get_student();

    Student_bursant() = default;

    friend std::ostream &operator<<(std::ostream &os, const Student_bursant &st_b);

};

class Student_nebursant: public Student {
    std::shared_ptr<Student> s;
public:
    explicit Student_nebursant(std::shared_ptr<Student> s);

    explicit Student_nebursant(std::shared_ptr<Student_nebursant> &other);

    Student_nebursant() = default;
};

#endif //MAIN_CPP_STUDENT_H
