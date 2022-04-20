#include <algorithm>
#include <iostream>
#include "Student.h"
#include "Profesor.h"
#include "Secretariat.h"
#include "Facultate.h"
#include <memory>

int main() {
    Student st4{"Andrei", 130, 7};
    Student st5{"Ion", 140, 8};
    std::shared_ptr<Student> st1;
    st1 = std::make_shared<Student>(st4);
    std::cout << "DEBUG\n" << *st1 << '\n';
    std::shared_ptr<Student> st2;
    st2 = std::make_shared<Student>(st5);
    st5 = {"Georgescu", 143, 8};
    std::shared_ptr<Student> st3 = std::make_shared<Student>(st5);
    Student oldst1;
    Student oldst2;
    Student oldst3;
    Secretariat sc{10, "Alina"};
    Profesor pr{"Paun", {131, 152, 143, 141, 151}, 6000}, pr2{"Anca", {131, 142, 141, 134, 152}, 5000};
    Profesor oldpr, oldpr2;
    Facultate fac2{"FMI", {st1, st2, st3}, {pr, pr2}, sc};
    Facultate fac3{"ASE", {st1, st2, st3}, {pr, pr2}, sc};
    std::cout << *st1 <<'\n';
    Secretariat sec{10, "Alina"};
    std::cout << "FMI\n";
    //std::cout << "Studenti\n" << fac2.get_studenti() << "\nProfesori\n" << fac2.get_profesori() << "\nSecretariat\n" << fac2.get_secretariat() << '\n';
    std::cout << fac2;
    std::cout << "Grupa veche: " << st1->get_grupa() << '\n';
    oldst1 = st1;
    st1->transfer_grupa(132);
    fac2.update_student(oldst1, st1);
    std::cout << fac2;
    std::cout << *st1 << '\n' << *st2 << '\n';
    oldst1 = st1, oldst2 = st2;
    st1->schimbare_grupe_2_studenti(st2);
    fac2.update_student(oldst1, st1);
    fac2.update_student(oldst2, st2);
    std::cout << "Au fost schimbati studentii!\n";
    std::cout << *st1 << '\n' << *st2;
    pr.sortare_grupe();
    std::cout << "Grupe inainte\n";
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    std::cout << '\n';
    std::cout << "Profesor Paraseste grupa 131\n";
    oldpr = pr;
    pr.prof_leave_group(131);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    fac2.update_prof(oldpr, pr);
    sec.vin_secretari(5);
    fac2.update_secretariat(sec);
    std::cout << fac2 << '\n';
    std::cout << "A fost adaugata grupa 133\n";
    oldpr = pr;
    pr.prof_add_group(133);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    fac2.update_prof(oldpr, pr);
    fac2.student_leaves(st3);
    st3 = std::make_shared<Student>(st4);
    std::cout << "\nAICIIIII\n";
    std::cout << *st3 <<'\n';
    fac2.student_nou(st3);
    sec.schimb_secretar_sef("Oana");
    fac2.update_secretariat(sec);
    std::cout << "Am schimbat secretar-sef\n" << sec.get_secretar_sef()<<'\n';
    std::cout << "Toti studentii\n";
    for(int i = 0; i < fac2.get_studenti().size(); i++)
        std::cout << *fac2.get_studenti()[i] << ' ';
    fac2.student_leaves(st2);
    std::cout << '\n' << *st2 << '\n' << "Abandoneaza studentul\n";
    for(int i = 0; i < fac2.get_studenti().size(); i++)
        std::cout << *fac2.get_studenti()[i] << ' ';
    Student_bursant stb{st1, 700};
    std::cout << stb.get_grupa() << '\n';
    Student *st1_up = new Student_bursant();
    //std::cout << st1_up->debug();
    //st1_up->transfer_grupa(152);
    std::cout << st1_up->get_medie() << '\n';
    delete st1_up;
    std::cout << *st1 << '\n';
    //std::cout << st1;
    st1 = fac2.first_student();
    st1 = std::make_shared<Student_bursant>(st1);
    std::cout << *st1 << '\n';
    fac2.make_student_bursant();
    Student_bursant stb1{st1, 700};
    std::cout << "BURSA INAINTE\n" << stb1.get_bursa() << '\n';
    stb1.modificare_bursa(100);
    std::cout << "BURSA DUPA\n" << stb1.get_bursa() << '\n';
    //std::cout << "STUDENTUL\n" << *stb1.get_student() << '\n';
    //std::shared_ptr<Student_bursant>st1;
    st1->transfer_grupa(131);
    std::cout << st1->get_grupa() << '\n';
    //st1 = std::make_shared<Student_bursant>(st1);
    std::cout << "Studenti inainte de swap\n" << *st2 << *st3 <<'\n';
    Student::swap(st2, st3);
    std::cout << "Studenti dupa swap\n" << *st2 << *st3 <<'\n';
    std::cout << "\n\nPARTEA CU PROFI\n\n";
    std::cout << pr << '\n';
    Laborant lab{"Adi", {130, 151, 150, 134}, 2000};
    Laborant lab2{"Ana", {131, 132, 142}, "POO", 1000};
    std::cout << lab << '\n';
    std::cout << lab.get_salar() << '\n';
    lab.prof_add_group(160);
    std::cout << lab << '\n';
    std::cout << "MATERIE INAINTE\n" << lab2.get_materie() << '\n';
    lab2.schimbare_materie("LFA");
    std::cout << "MATERIE DUPA\n" << lab2.get_materie() << '\n';
    std::cout << lab << '\n';
    pr.prof_add_group(160);
    std::cout << pr << '\n';
    std::cout << "Salariul profesorului inainte de marire\n" << pr.get_salar() << '\n';
    pr.marire_salar(1000);
    std::cout << "Salariul profesorului dupa marire\n" << pr.get_salar() << '\n';
    std::cout << "Salariul laborantului inainte de marire\n" << lab.get_salar() << '\n';
    lab.marire_salar(1000);
    std::cout << "Salariul laborantului dupa marire\n" << lab.get_salar() << '\n';
    return 0;
}