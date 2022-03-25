//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_PROFESOR_H
#define MAIN_CPP_PROFESOR_H


#include <string>

class Profesor {
    std::string nume;
    std::vector<int>grupe;
public:
    Profesor(std::string nume, std::vector<int>grupe);
    Profesor(const Profesor &other);
    Profesor() = default;

    explicit Profesor(const std::string &nume);

    ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const;
    [[nodiscard]] std::vector<int> get_grupe() const;

    bool operator==(const Profesor &other);

    void sortare_grupe();

    void prof_leave_group(int grupa);
    void prof_add_group(int grupa);

    Profesor &operator=(const Profesor &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};


#endif //MAIN_CPP_PROFESOR_H
