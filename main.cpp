#include <iostream>
#include <vector>
class Student;
class Profesor;
class Secretariat;
class Facultate;

class Student {
    std::string nume;
    int grupa{};
    double medie{};
public:
    Student(std::string nume, int grupa, double medie):nume{std::move(nume)}, grupa{grupa}, medie{medie} {
        /*this -> nume = nume;
        this -> grupa = grupa;
        this -> medie = medie;*/
        std::cout<<"Student init\n";
    }
    Student(const Student &other):nume(other.nume), grupa(other.grupa), medie(other.medie) {
        this -> nume = other.nume;
        this -> grupa = other.grupa;
        this -> medie = other.medie;
        //std::cout<<"CC Student\n";
    }
    Student() = default;
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
    Student &operator=(const Student &other) = default;

    bool operator==(const Student &other) {
        if(this -> nume == other.nume and this -> grupa == other.grupa and this -> medie == other.medie)
            return true;
        return false;
    }

    static bool check(Student s1, const Student& s2) {
        if(s1 == s2)
            return true;
        return false;
    }

    friend class Facultate;
};

class Profesor {
    std::string nume;
    std::vector<int>grupe;
public:
    Profesor(std::string nume, std::vector<int>grupe):nume{std::move(nume)}, grupe{std::move(grupe)} {
        /*this -> nume = nume;
        this -> grupe = grupe;*/
        std::cout<<"Profesor init\n";
    }
    Profesor(const Profesor &other):nume(other.nume), grupe(other.grupe) {
        this -> nume = other.nume;
        this -> grupe = other.grupe;
        //std::cout<<"CC profesor\n";
    }
    Profesor() = default;
    ~Profesor() = default;
    [[nodiscard]] std::string get_nume() const {
        return nume;
    }
    [[nodiscard]] std::vector<int> get_grupe() const {
        return grupe;
    }

    bool operator==(const Profesor &other) {
        if(this -> nume == other.nume and this -> grupe == other.grupe)
            return true;
        return false;
    }

    static void sortare_grupe(Profesor &pr) {
        std::sort(pr.grupe.begin(), pr.grupe.end());
    }

    static void prof_leave_group(Profesor &pr, int grupa) {
        for(int i = 0; i < pr.grupe.size(); i++) {
            if(pr.grupe[i] == grupa) {
                for(int j = i; j < pr.grupe.size() - 1; j++)
                    pr.grupe[j] = pr.grupe[j + 1];
                break;
            }
        }
        pr.grupe.pop_back();
        std::sort(pr.grupe.begin(), pr.grupe.end());
    }
    static void prof_add_group(Profesor &pr, int grupa) {
        pr.grupe.push_back(grupa);
        std::sort(pr.grupe.begin(), pr.grupe.end());
    }
    friend std::ostream &operator<<(std::ostream &os, const Profesor &pr);
};

class Secretariat {
    std::string departament;
    int numar_angajati;
    std::string secretar_sef;
public:
    Secretariat(std::string departament, int numar_angajati, std::string secretar_sef):departament{std::move(departament)}, numar_angajati{numar_angajati}, secretar_sef{std::move(secretar_sef)} {
        /*this -> departament = departament;
        this -> numar_angajati = numar_angajati;
        this -> secretar_sef = secretar_sef;*/
        std::cout<<"Secretariat init\n";
    }
    Secretariat(const Secretariat &other):departament(other.departament), numar_angajati(other.numar_angajati), secretar_sef(other.secretar_sef) {
        this -> departament = other.departament;
        this -> numar_angajati = other.numar_angajati;
        this -> secretar_sef = other.secretar_sef;
        //std::cout<<"CC secretariat\n";
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
    Facultate(std::string nume, std::vector<Student>St, std::vector<Profesor>Pr, const Secretariat& Sec):nume{std::move(nume)}, St{std::move(St)}, Pr{std::move(Pr)}, Sec(Sec) {
        /*this -> nume = nume;
        this -> St = St;
        this -> Pr = Pr;
        this -> Sec = Sec;*/
        std::cout<<"init facultate\n";
    }
    Facultate(const Facultate &other):nume(other.nume), St(other.St), Pr(other.Pr), Sec(other.Sec)
    {
        this -> nume = other.nume;
        this -> St = other.St;
        this -> Pr = other.Pr;
        this -> Sec = other.Sec;
        //std::cout<<"CC facultate\n";
    }
    Facultate &operator=(const Facultate &other) = default;
    ~Facultate() = default;

    static void student_leaves(Facultate &f, const Student& s) {
        for(int i = 0; i < f.St.size(); i++) {
            if(Student::check(f.St[i], s)) {
                for(int j = i; j < f.St.size() - 1; j++)
                    f.St[j] = f.St[j + 1];
                break;
            }
        }
        f.St.pop_back();
    }

    static void student_nou(Facultate &f, const Student& s) {
        f.St.push_back(s);
    }

    std::vector<Student> get_studenti() {
        return St;
    }

    [[maybe_unused]] std::vector<Profesor> get_profesori() {
        return Pr;
    }

    [[maybe_unused]] Secretariat get_secretariat() {
        return Sec;
    }
    static int find_student(Facultate &f, const Student& s) {
        int ans = 0;
        for(int i = 0; i < f.St.size(); i++)
            if(f.St[i] == s) {
                ans = i;
                return ans;
            }
        return ans;
    }

    static void update_student(Facultate &f, const Student& s1, const Student& s2) {
        int x = Facultate::find_student(f, s1);
        f.St[x] = s2;
    }

    /*static void schimbare_grupe_2_studenti(Facultate &f, Student s1, Student s2) {
        int x = 0, y = 0;
        for(int i = 0; i<f.St.size(); i++)
            if(f.St[i] == s1) {
                x = i;
                break;
            }
        for(int i = 0; i<f.St.size(); i++)
            if(f.St[i] == s2) {
                y = i;
                break;
            }
        std::swap(f.St[x], f.St[y]);
    }*/

    static int find_prof(Facultate &f, const Profesor& pr) {
        int ans = 0;
        for(int i = 0; i < f.Pr.size(); i++) {
            if(f.Pr[i] == pr) {
                ans = i;
                return ans;
            }
        }
        return ans;
    }

    static void update_prof(Facultate &f, const Profesor& pr1, const Profesor& pr2) {
        int x = Facultate::find_prof(f, pr1);
        f.Pr[x] = pr2;
    }

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
        os << i.get_nume() << ' ';
        os << i.get_grupa() << ' ';
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
    Student st3 = st1;
    Student oldst1;
    Student oldst2;
    Student oldst3;
    Secretariat sc{"Contabilitate", 10, "Alina"};
    Profesor pr{"Paun", {131, 152, 143, 141, 151}}, pr2{"Anca", {131, 142, 141, 134, 152}};
    Profesor oldpr, oldpr2;
    Facultate fac{"Poli", {{"Ionescu", 131, 7.8}, {"Georgescu", 151, 9}}, {{"Paun", {131, 151}}}, {"Contabilitate", 10, "Alina"}};
    Facultate fac2{"FMI", {st1, st2, st3}, {pr, pr2}, sc};
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
    std::cout << "A fost adaugata grupa 133\n";
    Profesor::prof_add_group(pr, 133);
    for(int i = 0; i<pr.get_grupe().size(); i++)
        std::cout << pr.get_grupe()[i] << ' ';
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