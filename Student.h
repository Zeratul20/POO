//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H


#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include "Exceptie.h"

class Student {
protected:
    std::string nume;
    int grupa{};
    double medie{};
public:
    Student(std::string nume, int grupa, double medie);
    explicit Student(std::shared_ptr<Student> const &other);
    Student() = default;
    virtual ~Student() = default;
    [[nodiscard]] std::string get_nume() const;

    [[nodiscard]] int get_grupa() const;

    [[nodiscard]] double get_medie() const;
    friend std::ostream &operator<<(std::ostream &os, const Student &st);


    virtual void transfer_grupa(int grupa_noua);
    void set_medie(double medie_noua);

    void schimbare_grupe_2_studenti(const std::shared_ptr<Student>& s2);
    friend bool operator==(const std::shared_ptr<Student>& st1, const std::shared_ptr<Student>& st2);
    Student &operator=(std::shared_ptr<Student> const &other);
    void check_medie() const {
        if(this -> medie < 1 or this -> medie > 10)
            throw eroare_medie("eroare medie");
    }
    void check_nume() const {
        if((this -> nume).size() < 3)
            throw eroare_student("studentul nu are un nume existent");
    }
};

class Student_bursant: public Student {
    std::shared_ptr<Student> stud;
    int bursa{};
public:
    Student_bursant(std::shared_ptr<Student> stud, int bursa);

    explicit Student_bursant(std::shared_ptr<Student> stud);

    explicit Student_bursant(std::shared_ptr<Student_bursant> const &other);
    void transfer_grupa(int grupa_noua) override;

    void modificare_bursa(int val);

    [[nodiscard]] int get_grupa();
    double get_medie();
    [[nodiscard]] int get_bursa() const;
    //std::shared_ptr<Student> get_student();
    Student_bursant() = default;
    ~Student_bursant() override = default;
    friend std::ostream &operator<<(std::ostream &os, const Student_bursant &st_b);

};


#endif //MAIN_CPP_STUDENT_H
