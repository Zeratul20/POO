#include <iostream>
#include <vector>
class Student;
class Profesor;
class Secretariat;
class Facultate;

class Student {
    std::string nume;
    int grupa;
    double medie;
public:
    Student(std::string nume, int grupa, double medie):nume{std::move(nume)}, grupa{grupa}, medie{medie}
    {
        std::cout<<"Student init\n";
    }
    Student(const Student &other):nume(other.nume), grupa(other.grupa), medie(other.medie)
    {
        std::cout<<"CC Student\n";
    }
    ~Student() = default;
    [[nodiscard]] std::string get_nume() const {
        return nume;
    }
    [[nodiscard]] int get_grupa() const {
        return grupa;
    }

    [[nodiscard]] double get_medie() const {
        return medie;
    }
    friend std::ostream &operator<<(std::ostream &os, const Student &st);


    static void transfer_grupa(Student &s, int grupa_noua) {
        s.grupa = grupa_noua;
    }

    static void schimbare_grupe_2_studenti(Student &s1, Student &s2) {
        std::swap(s1.grupa, s2.grupa);
    }

};

class Profesor {
    std::string nume;
    std::vector<int>grupe;
public:
    Profesor(std::string nume, std::vector<int>grupe):nume{std::move(nume)}, grupe{std::move(grupe)}
    {
        std::cout<<"Profesor init\n";
    }
    Profesor(const Profesor &other):nume(other.nume), grupe(other.grupe)
    {
        std::cout<<"CC profesor\n";
    }
    ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const {
        return nume;
    }
    [[nodiscard]] std::vector<int> get_grupe() const {
        return grupe;
    }
    static void leave_group(Profesor &pr, int grupa) {
        for(int i = 0; i < pr.grupe.size(); i++) {
            if(pr.grupe[i] == grupa) {
                for(int j = i; j < pr.grupe.size() - 1; j++)
                    pr.grupe[j] = pr.grupe[j + 1];
                break;
            }
        }
        pr.grupe.pop_back();
    }
    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};

class Secretariat {
    std::string departament;
    int numar_angajati;
    std::string secretar_sef;
public:
    Secretariat(std::string departament, int numar_angajati, std::string secretar_sef):
            departament{std::move(departament)}, numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)}
    {
        std::cout<<"Secretariat init\n";
    }
    Secretariat(const Secretariat &other):
            departament(other.departament), numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef)
    {
        std::cout<<"CC secretariat\n";
    }
    [[nodiscard]] std::string get_departament() const {
        return departament;
    }
    [[nodiscard]] int get_numar_angajati() const {
        return numar_angajati;
    }
    [[nodiscard]] std::string get_secretar_sef() const {
        return secretar_sef;
    }
    ~Secretariat() = default;
    friend std::ostream &operator<<(std::ostream &os, const Secretariat &sec);
};
class Facultate {
    std::string nume;
    std::vector<Student>St;
    std::vector<Profesor>Pr;
    Secretariat Sec;
public:
    Facultate(std::string nume, std::vector<Student>St, std::vector<Profesor>Pr, const Secretariat& Sec):nume{std::move(nume)}, St{std::move(St)}, Pr{std::move(Pr)}, Sec(Sec)
    {
        std::cout<<"init facultate\n";
    }
    Facultate(const Facultate &other):nume(other.nume), St(other.St), Pr(other.Pr), Sec(other.Sec)
    {
        std::cout<<"CC facultate\n";
    }
    Facultate &operator=(const Facultate &other) = default;
    ~Facultate() = default;

    friend std::ostream &operator<<(std::ostream &os, const Facultate &f);
};

std::ostream &operator<<(std::ostream &os, const Student &st) {
    os << st.nume << ' ';
    os << st.grupa << ' ';
    os << st.medie << ' ';
    return os;
}


std::ostream &operator<<(std::ostream &os, const Profesor &pr) {
    os << pr.nume << '\n';
    for(int i : pr.grupe) {
        os << i << ' ';
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Secretariat &sec) {
    os << sec.departament << ' ';
    os << sec.numar_angajati << ' ';
    os << sec.secretar_sef << ' ';
    return os;
}

std::ostream &operator<<(std::ostream &os, const Facultate &f) {
    os << "Nume facultate: " << f.nume << '\n';
    os << '\n';
    os << "Studenti:\n";
    for(const auto & i : f.St)
    {
        os << i.get_grupa() << ' ';
        os << i.get_nume() << ' ';
        os << i.get_medie() << ' ';
        os << '\n';
    }
    os << '\n';
    os << '\n';
    os << "Profesori:\n";
    for(const auto & i : f.Pr)
    {
        os << i.get_nume() << ' ';
        for(int j : i.get_grupe())
            os << j << ' ';
        os << '\n';
    }
    os << '\n';
    os << "Secretariat:\n";
    os << f.Sec.get_departament() << ' ' << f.Sec.get_numar_angajati() << ' ' << f.Sec.get_secretar_sef() << '\n';
    return os;
}

int main() {
    Student st1{"Ionescu", 131, 7.8};
    Student st2{"Georgescu", 151, 5.8};
    Secretariat sc{"Contabilitate", 10, "Alina"};
    Profesor pr{"Paun", {131, 152}};
    Facultate fac{"FMI", {{"Ionescu", 131, 7.8}, {"Georgescu", 151, 9}}, {{"Paun", {131, 151}}}, {"Contabilitate", 10, "Alina"}};
    Facultate fac2{"FMI", {st1, st2}, {pr}, sc};
    std::cout << "Grupa veche: " << st1.get_grupa() << '\n';
    Student::transfer_grupa(st1, 132);
    std::cout << "Grupa noua: " << st1.get_grupa() << '\n';
    std::cout << st1 << '\n' << st2 << '\n';
    Student::schimbare_grupe_2_studenti(st1, st2);
    std::cout << "Au fost schimbati studentii!\n";
    std::cout << st1 << '\n' << st2;
    std::cout << "Grupe inainte\n";
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    std::cout << '\n';
    std::cout << "Paraseste grupa 131\n";
    Profesor::leave_group(pr, 131);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
    return 0;
}
