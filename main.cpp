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
    std::string get_nume() const {
        return nume;
    }
    int get_grupa() const {
        return grupa;
    }

    double get_medie() const {
        return medie;
    }
    friend std::ostream &operator<<(std::ostream &os, const Student &st);

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
    std::string get_nume() const {
        return nume;
    }
    std::vector<int> get_grupe() const {
        return grupe;
    }
    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};

class Secretariat {
    std::string Departament;
    int numar_angajati;
    std::string secretar_sef;
public:
    Secretariat(std::string Departament, int numar_angajati, std::string secretar_sef):
            Departament{std::move(Departament)}, numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)}
    {
        std::cout<<"Secretariat init\n";
    }
    Secretariat(const Secretariat &other):
            Departament(other.Departament), numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef)
    {
        std::cout<<"CC secretariat\n";
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
    os << st.nume;
    os << st.grupa;
    os << st.medie;
    return os;
}


std::ostream &operator<<(std::ostream &os, const Profesor &pr) {
    os << pr.nume;
    os << pr.nume;
    for(int i : pr.grupe) {
        os << i;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Secretariat &sec) {
    os << sec.Departament;
    os << sec.numar_angajati;
    os << sec.secretar_sef;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Facultate &f) {
    os << f.nume;
    for(const auto & i : f.St)
    {
        os << i.get_grupa();
        os << i.get_nume();
        os << i.get_medie();
    }
    for(const auto & i : f.Pr)
    {
        os << i.get_nume();
        for(int j : i.get_grupe())
            os << j;
    }
    return os;
}

int main() {
    Student st{"Ionescu", 131, 7.8};
    Secretariat sc{"Contabilitate", 10, "Alina"};
    Profesor pr{"Paun", {131, 152}};
    Facultate fac{"FMI", {{"Ionescu", 131, 7.8}, {"Georgescu", 151, 9}}, {{"Paun", {131, 151}}}, {"Contabilitate", 10, "Alina"}};
    std::cout << st.get_nume();
    return 0;
}
