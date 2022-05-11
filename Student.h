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

    virtual void creste_medie(double marire);

    virtual void transfer_grupa(int grupa_noua);
    static void set_medie(const std::shared_ptr<Student> &st, double medie) {
        st -> medie = medie;
    }

    void schimbare_grupe_2_studenti(const std::shared_ptr<Student>& s2);
    friend bool operator==(const std::shared_ptr<Student>& st1, const std::shared_ptr<Student>& st2);
    Student &operator=(std::shared_ptr<Student> const &other);
    static void swap(std::shared_ptr<Student> &st1, std::shared_ptr<Student> &st2);

};

class Student_bursant: public Student {
    std::shared_ptr<Student> s;
    int bursa{};
public:
    Student_bursant(std::shared_ptr<Student> s, int bursa);

    explicit Student_bursant(std::shared_ptr<Student> s);

    explicit Student_bursant(std::shared_ptr<Student_bursant> const &other);
    void transfer_grupa(int grupa_noua) override;

    void modificare_bursa(int val);

    [[nodiscard]] int get_grupa();
    void set_medie();
    double get_medie();
    [[nodiscard]] int get_bursa() const;
    //std::shared_ptr<Student> get_student();
    void creste_medie(double marire) override;
    Student_bursant() = default;
    ~Student_bursant() override = default;
    friend std::ostream &operator<<(std::ostream &os, const Student_bursant &st_b);

    static void f();

};

class my_exceptie:public std::runtime_error {
public:
    explicit my_exceptie(const std::string &arg): runtime_error(arg) {
        std::cout << "my_exceptie err\n";
    }
};

class eroare_student:public my_exceptie {
public:
    explicit eroare_student(const std::string &arg): my_exceptie(arg) {
        std::cout << "student err\n";
    }
};

class eroare_facultate:public my_exceptie {
public:
    explicit eroare_facultate(const std::string &arg): my_exceptie(arg) {
        std::cout << "facultate err\n";
    }
};


#endif //MAIN_CPP_STUDENT_H
