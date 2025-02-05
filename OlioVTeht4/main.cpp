#include <iostream>
#include <string>

class Pankkitili {
protected:
    double saldo;
public:
    Pankkitili(double alkusaldo) : saldo(alkusaldo) {}
    virtual bool deposit(double amount) {
        if (amount < 0) return false;
        saldo += amount;
        std::cout << "Pankkitili: talletus " << amount << " tehty, saldo " << saldo << std::endl;
        return true;
    }
    virtual bool withdraw(double amount) {
        if (amount < 0 || amount > saldo) return false;
        saldo -= amount;
        std::cout << "Pankkitili: nosto " << amount << " tehty, saldo " << saldo << std::endl;
        return true;
    }
    double getSaldo() const {
        return saldo;
    }
};

class Luottotili : public Pankkitili {
private:
    double luottoraja;
public:
    Luottotili(double alkusaldo, double raja) : Pankkitili(alkusaldo), luottoraja(raja) {}
    bool withdraw(double amount) override {
        if (amount < 0 || saldo - amount < -luottoraja) return false;
        saldo -= amount;
        std::cout << "Luottotili: nosto " << amount << " tehty, saldo " << saldo << std::endl;
        return true;
    }
};

class Asiakas {
private:
    std::string nimi;
    Pankkitili pankki;
    Luottotili luotto;
public:
    Asiakas(const std::string& n, double pa, double la, double lr)
        : nimi(n), pankki(pa), luotto(la, lr) {}

    void showSaldo() const {
        std::cout << nimi << "\nKayttotilin saldo " << pankki.getSaldo()
        << "\nLuottotilin saldo " << luotto.getSaldo() << std::endl;
    }

    bool deposit(double amount) {
        return pankki.deposit(amount);
    }

    bool withdraw(double amount) {
        if (!pankki.withdraw(amount)) {
            std::cout << "Kayttotilin saldo ei riita. Yritetaan luottotililta..." << std::endl;
            return luotto.withdraw(amount);
        }
        return true;
    }

    bool tiliSiirto(Asiakas& toinen, double summa) {
        if (!pankki.withdraw(summa)) return false;
        toinen.pankki.deposit(summa);
        std::cout << nimi << " Pankkitili: siirrettiin " << summa << " " << toinen.nimi << ":lle" << std::endl;
        return true;
    }
};

int main() {
    Asiakas a("Aapeli", 100, 0, 1000);
    Asiakas b("Bertta", 50, 0, 1000);

    a.showSaldo();
    b.showSaldo();

    a.deposit(250);
    a.withdraw(150);
    a.showSaldo();

    a.tiliSiirto(b, 50);
    b.withdraw(50);
    a.showSaldo();
    b.showSaldo();

    return 0;
}
