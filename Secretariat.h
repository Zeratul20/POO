//
// Created by utilizator on 23.03.2022.
//

#ifndef MAIN_CPP_SECRETARIAT_H
#define MAIN_CPP_SECRETARIAT_H

#include <string>
#include <utility>
#include <iostream>
#include <memory>

template<typename T1, typename T2>
class Secretariat {
protected:
    T1 numar_angajati{};
    T2 secretar_sef;
    T1 nrRelatiicuStudentii{};
    T1 nrRelatiicuProfii{};
    T2 tipSecretar;
public:
    Secretariat(T1 numar_angajati, T2 secretar_sef);
    explicit Secretariat(T1 numar_angajati):numar_angajati(numar_angajati) {numar_angajati = 5;}
    Secretariat(T1 nrRelatiicuStudentii, T1 nrRelatiicuProfii, T2 tipSecretar):nrRelatiicuStudentii(nrRelatiicuStudentii), nrRelatiicuProfii(nrRelatiicuProfii), tipSecretar(tipSecretar) {
        nrRelatiicuStudentii = 3;
        nrRelatiicuProfii = 2;
        tipSecretar = "Contabil";
    }
    Secretariat() = default;
    Secretariat(const Secretariat &other);

    [[nodiscard]] virtual T1 get_numar_angajati() const;
    [[nodiscard]] T2 get_secretar_sef() const;
    ~Secretariat() = default;
    virtual void vin_secretari(T1 nr_noi);
    void schimb_secretar_sef(T2 nume);
    virtual void operator++();
    [[nodiscard]] T1 get_nrRelatiicuStudentii() const;
    [[nodiscard]] T1 get_nrRelatiicuProfii() const ;
    [[nodiscard]] T2 get_tipSecretar() const;

    Secretariat &operator=(const Secretariat &other) = default;

    //friend std::ostream &operator<< <>(std::ostream&, const Secretariat<T1, T2> &sec);
    friend class SecretariatBuilder;
};

class Diviziuni_Secretariat:public Secretariat<int, std::string> {
    int an;
public:
    [[nodiscard]] std::shared_ptr<Secretariat> clone() const;
    Diviziuni_Secretariat(int numar_angajati, int an): Secretariat<int, std::string>(numar_angajati), an(an) {}
    [[nodiscard]] int get_numar_angajati() const override;
    [[nodiscard]] int get_an() const {
        return this -> an;
    }
    void vin_secretari(int nr_noi) override {
        this -> numar_angajati += nr_noi / 3;
    }
};

class SecretariatBuilder{
    Secretariat<int, std::string>sec;
public:
    SecretariatBuilder() = default;
    explicit SecretariatBuilder(const Secretariat<int, std::string>&sec2):sec(sec2) {
        std::cout << "\n\nSECRETARIAT BUILDER\n\n";
        sec.nrRelatiicuStudentii = sec2.nrRelatiicuStudentii;
        sec.nrRelatiicuProfii = sec2.nrRelatiicuProfii;
        sec.tipSecretar = sec2.tipSecretar;
    }

    SecretariatBuilder &nrRelatiicuStudentii(const int nr) {
        sec.nrRelatiicuStudentii = nr;
        return *this;
    }

    SecretariatBuilder &nrRelatiicuProfii(const int nr) {
        sec.nrRelatiicuProfii = nr;
        return *this;
    }

    SecretariatBuilder &tipSecretar(const std::string& tip) {
        sec.tipSecretar = tip;
        return *this;
    }

    Secretariat<int, std::string> build() {
        return sec;
    }

    friend std::ostream &operator<<(std::ostream &os, const SecretariatBuilder &builder) {
        os << "nrRelatiicuStudentii: " << builder.sec.get_nrRelatiicuStudentii() << "\nnrRelatiicuProfii: " << builder.sec.get_nrRelatiicuProfii() << "\ntipSecretar: " << builder.sec.get_tipSecretar() << '\n';
        return os;
    }
};


#endif //MAIN_CPP_SECRETARIAT_H
