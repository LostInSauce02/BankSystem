#include "Account.h"
using namespace std;

double Account::checkBalance() const
{
    return m_balance;
}

bool Account::deposit(double amount)
{
    if(amount > 0)
    {
        m_balance += amount;
        return true;
    }
    else
    {
        return false;
    }
}

bool Account::withdraw(double amount)
{
    if(amount > 0 && amount <= m_balance)
    {
        m_balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

bool Account::transfer(Account& name, double amount)
{
    if(amount > 0 && amount <= m_balance)
    {
        m_balance -= amount;
        name.m_balance += amount;
        return true;
    }
    else
    {
        return false;
    }
}

string Account::getName() const
{
    return m_acctName;
}

int Account::getNumber() const
{
    return m_acctNumber;
}
