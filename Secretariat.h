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
    explicit Secretariat(T1 numar_angajati);
    Secretariat(T1 nrRelatiicuStudentii, T1 nrRelatiicuProfii, const T2 &tipSecretar);
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
    Diviziuni_Secretariat(int numar_angajati, int an);
    [[nodiscard]] int get_numar_angajati() const override;
    [[nodiscard]] int get_an() const;
    void vin_secretari(int nr_noi) override;
};

class SecretariatBuilder{
    Secretariat<int, std::string>sec;
public:
    SecretariatBuilder() = default;
    explicit SecretariatBuilder(const Secretariat<int, std::string>&sec2);

    SecretariatBuilder &nrRelatiicuStudentii(const int nr);

    SecretariatBuilder &nrRelatiicuProfii(const int nr);

    SecretariatBuilder &tipSecretar(const std::string& tip);

    Secretariat<int, std::string> build();

    friend std::ostream &operator<<(std::ostream &os, const SecretariatBuilder &builder);
};


#endif //MAIN_CPP_SECRETARIAT_H
