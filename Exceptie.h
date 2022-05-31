//
// Created by utilizator on 12.05.2022.
//

#ifndef MAIN_CPP_EXCEPTIE_H
#define MAIN_CPP_EXCEPTIE_H

#include <iostream>

class my_exceptie:public std::runtime_error {
public:
    explicit my_exceptie(const std::string &arg);
};

class eroare_student:public my_exceptie {
public:
    explicit eroare_student(const std::string &arg);
};

class eroare_medie:public my_exceptie {
public:
    explicit eroare_medie(const std::string &arg);
};

class eroare_profesor:public my_exceptie {
public:
    explicit eroare_profesor(const std::string &arg);
};


#endif //MAIN_CPP_EXCEPTIE_H
