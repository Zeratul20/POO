//
// Created by utilizator on 12.05.2022.
//

#include "Exceptie.h"

my_exceptie::my_exceptie(const std::string &arg) : runtime_error(arg) {
    std::cout << "my_exceptie err\n";
}

eroare_student::eroare_student(const std::string &arg) : my_exceptie(arg) {
    std::cout << "student err\n";
}

eroare_medie::eroare_medie(const std::string &arg) : my_exceptie(arg) {
    std::cout << "err medie imposibila\n";
}

eroare_profesor::eroare_profesor(const std::string &arg) : my_exceptie(arg) {
    std::cout << "err numar insuficient de grupe prof";
}
