#include <algorithm>
#include <iostream>
#include <vector>
#include "Student.h"
#include "Profesor.h"
#include "Secretariat.h"
#include "Facultate.h"

int main() {
    Student st1{"Ionescu", 131, 7.8};
    Student st2{"Georgescu", 151, 5.8};
    Student st3 = st1;
    Student oldst1;
    Student oldst2;
    Student oldst3;
    Secretariat sc{10, "Alina"};
    Profesor pr{"Paun", {131, 152, 143, 141, 151}}, pr2{"Anca", {131, 142, 141, 134, 152}};
    Profesor oldpr, oldpr2;
    Facultate fac{"Poli", {{"Ionescu", 131, 7.8}, {"Georgescu", 151, 9}}, {{"Paun", {131, 151}}}, {10, "Alina"}};
    Facultate fac2{"FMI", {st1, st2, st3}, {pr, pr2}, sc};
    Secretariat sec{10, "Alina"};
    std::cout << "FMI\n";
    //std::cout << "Studenti\n" << fac2.get_studenti() << "\nProfesori\n" << fac2.get_profesori() << "\nSecretariat\n" << fac2.get_secretariat() << '\n';
    std::cout << fac2;
    std::cout << "Grupa veche: " << st1.get_grupa() << '\n';
    oldst1 = st1;
    Student::transfer_grupa(st1, 132);
    Facultate::update_student(fac2, oldst1, st1);
    std::cout << fac2;
    std::cout << st1 << '\n' << st2 << '\n';
    oldst1 = st1, oldst2 = st2;
    Student::schimbare_grupe_2_studenti(st1, st2);
    Facultate::update_student(fac2, oldst1, st1);
    Facultate::update_student(fac2, oldst2, st2);
    std::cout << "Au fost schimbati studentii!\n";
    std::cout << st1 << '\n' << st2;
    Profesor::sortare_grupe(pr);
    std::cout << "Grupe inainte\n";
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    std::cout << '\n';
    std::cout << "Profesor Paraseste grupa 131\n";
    oldpr = pr;
    Profesor::prof_leave_group(pr, 131);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    Facultate::update_prof(fac2, oldpr, pr);
    Secretariat::vin_secretari(sec, 5);
    Facultate::update_secretariat(fac2, sec);
    std::cout << fac2 << '\n';
    std::cout << "A fost adaugata grupa 133\n";
    oldpr = pr;
    Profesor::prof_add_group(pr, 133);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    Facultate::update_prof(fac2, oldpr, pr);
    Facultate::student_leaves(fac2, st3);
    st3 = {"Gigescu", 142, 4};
    std::cout << st3 <<'\n';
    Facultate::student_nou(fac2, st3);
    std::cout << "Toti studentii\n";
    for(int i = 0; i < fac2.get_studenti().size(); i++)
        std::cout << fac2.get_studenti()[i] << ' ';
    Facultate::student_leaves(fac2, st2);
    std::cout << '\n' << st2 << '\n' << "Abandoneaza studentul\n";
    for(int i = 0; i < fac2.get_studenti().size(); i++)
        std::cout << fac2.get_studenti()[i] << ' ';
    return 0;
}