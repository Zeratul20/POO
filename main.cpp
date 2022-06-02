#include <algorithm>
#include <iostream>
#include "Student.h"
#include "Profesor.h"
#include "Secretariat.h"
#include "Facultate.h"
#include <memory>
#include "Exceptie.h"

using std::swap;
int main() {
    Student stt1{"Andrei", 130, 7};
    Student stt2{"Ion", 140, 8};
    std::shared_ptr<Student> st1;
    st1 = std::make_shared<Student>(stt2);
    std::cout << "DEBUG\n" << *st1 << '\n';
    std::shared_ptr<Student> st2;
    st2 = std::make_shared<Student>(stt1);
    stt1 = {"Georgescu", 143, 8};
    std::shared_ptr<Student> st3 = std::make_shared<Student>(stt1);
    Student oldst1;
    Student oldst2;
    Student oldst3;
    Secretariat<int, std::string> sc{10, "Alina"};
    Profesor pr{"Paun", {131, 152, 143, 141, 151}, 6000}, pr2{"Anca", {131, 142, 141, 134, 152}, 5000};
    Facultate fac2{"POLI", {st1, st2, st3}, {pr, pr2}, sc};
    Facultate fac3{"ASE", {st1, st2, st3}, {pr, pr2}, sc};
    Profesor oldpr;
    std::cout << *st1 <<'\n';
    Secretariat<int, std::string> sec{10, "Alina"};
    Secretariat<int, std::string> sec2{5, 8, "Contabil"};
    Student stIF = Student_factory::IF();
    Student stIFR = Student_factory::IFR();
    Student stID = Student_factory::ID();
    Student stMaster = Student_factory::Master();
    Student stDoctor = Student_factory::Doctor();
    std::cout << stIF << '\n';
    std::cout << stIFR << '\n';
    std::cout << stID << '\n';
    std::cout << stMaster << '\n';
    std::cout << stDoctor << '\n';
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
    pr.leave_group(131);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    fac2.update_prof(oldpr, pr);
    sec.vin_secretari(5);
    fac2.update_secretariat(sec);
    std::cout << fac2 << '\n';
    std::cout << "A fost adaugata grupa 133\n";
    oldpr = pr;
    pr.add_group(133);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    fac2.update_prof(oldpr, pr);
    fac2.student_leaves(st3);
    st3 = std::make_shared<Student>(stt2);
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
    Student *st1_up = new Student_bursant;
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
    swap(st2, st3);
    std::cout << "Studenti dupa swap\n" << *st2 << *st3 <<'\n';
    Student_bursant stb2{st2, 800};
    std::cout << stb2 << '\n';
    std::cout << *st2 << '\n' << *st3 << '\n';
    std::shared_ptr<Student> st4 = std::make_shared<Student>(stt1);
    std::shared_ptr<Student> st5 = std::make_shared<Student>(stt2);
    std::cout << *st4 << '\n';
    Facultate fac{"FMI", {st2, st3, st4, st5}, {pr, pr2}, sc};
    std::cout << fac << '\n';
    const std::shared_ptr<Student>& oldst5 = st5;
    st5->transfer_grupa(141);
    fac.update_student(oldst5, st5);
    std::cout << fac << '\n';
    std::cout << "\n\nPARTEA CU PROFI\n\n";
    std::cout << pr << '\n';
    Laborant lab{"Adi", {130, 151, 150, 134}, 2000};
    Laborant lab2{"Ana", {131, 132, 142}, "POO", 1000};
    Laborant lab3 = lab2;
    lab3.sortare_grupe();
    std::cout << lab3 << '\n';
    std::cout << lab << '\n';
    std::cout << lab.get_salar() << '\n';
    lab.add_group(160);
    std::cout << lab << '\n';
    std::cout << "MATERIE INAINTE\n" << lab2.get_materie() << '\n';
    lab2.schimbare_materie("LFA");
    std::cout << "MATERIE DUPA\n" << lab2.get_materie() << '\n';
    std::cout << lab << '\n';
    pr.add_group(160);
    std::cout << pr << '\n';
    std::cout << "Salariul profesorului inainte de marire\n" << pr.get_salar() << '\n';
    pr.marire_salar(1000);
    std::cout << "Salariul profesorului dupa marire\n" << pr.get_salar() << '\n';
    std::cout << "Salariul laborantului inainte de marire\n" << lab.get_salar() << '\n';
    lab.marire_salar(1000);
    std::cout << "Salariul laborantului dupa marire\n" << lab.get_salar() << '\n';
    std::cout << stb2.get_medie();
    Laborant lab4{"Alin", {131, 130, 142, 140}, "SD", 1500};
    Laborant lab5{"Ioana", {132, 130, 141, 150}, "LCM", 1700};
    std::cout << "\n\nPARTEA CU SECRETARIAT\n\n";
    Diviziuni_Secretariat divsec{7, 1};
    std::cout << divsec.get_an() << '\n';
    divsec.vin_secretari(3);
    std::cout << divsec.get_numar_angajati() << '\n';
    auto copie = divsec.clone();
    std::cout << sec.get_numar_angajati();
    copie -> operator++();
    std::cout << sec.get_numar_angajati();
    std::cout <<'\n';
    SecretariatBuilder secb;
    Secretariat<int, std::string>secr = secb.nrRelatiicuStudentii(5).tipSecretar("Contabilitate").build();
    SecretariatBuilder sec2b(sec2);
    std::cout << sec2b << '\n';
    Secretariat<int, std::string>secr2 = secb.nrRelatiicuProfii(7).tipSecretar("Dosarier").build();

    Secretariat<double, std::string>sec10{8, "Ioana"};
    sec10.setNrRelatiicuProfii();
    std::cout << sec10.get_nrRelatiicuProfii() << '\n';
    std::cout << "\n\nPARTEA CU EXCEPTII\n\n";
    std::cout << st3 -> get_medie() << '\n';
    st3 -> set_medie(11);
    std::cout << *st3 << '\n';
    Student ostn{"Ab", 130, 7};
    std::shared_ptr<Student>stn = std::make_shared<Student>(ostn);
    std::cout << pr << '\n';
    Profesor prof{"Ionel", {130}, 2000};
    try {
        st3 -> check_medie();
        stn -> check_nume();
        prof.check_nr_grupe();
    } catch (my_exceptie &err) {
        std::cout << "catch logic err\n" << err.what();
    }

    try {
        prof.check_nr_grupe();
    } catch (my_exceptie &err) {
        std::cout << "\ncatch logic err\n" << err.what();
    }
    return 0;
}