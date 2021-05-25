#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include <stdexcept>
#include <exception>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

class Bank
{
   /* friend ostream& operator<<(ostream& os, const Account& object)
    {
        os << object.getName() << " " << object.checkBalance() << '\n';
        return os;
    }
    */
    public:
        Bank();
        void displayMenu();
        void newAccount();
        void accountDetails(int&);
        void deposit(int&, double&);
        void withdraw(int&, double&);
        void transfer(int&, int&, double&);
        void close();
        void run();

    private:
        map<int, Account> accts;
        Account acct;
        int number = 0;
};

#endif // BANK_H
