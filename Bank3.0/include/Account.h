#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>
using namespace std;

class Account
{
    public:
        Account() = default;
        explicit Account(string acctName, int acctNumber, double balance): m_acctName(acctName), m_acctNumber(acctNumber), m_balance(balance) {}
        string getName() const;
        int getNumber() const;
        double checkBalance() const;
        bool deposit(double amount);
        bool withdraw(double amount);
        bool transfer(Account& name, double amount);

    private:
        string m_acctName;
        int m_acctNumber;
        double m_balance;
};

#endif // ACCOUNT_H
