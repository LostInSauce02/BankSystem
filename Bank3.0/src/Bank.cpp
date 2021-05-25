#include "Bank.h"
using namespace std;
Bank::Bank()
{
    string line;
    string name;
    int balance;
 //   int number = 0;
    try
    {
        ifstream infile;
        infile.open("Accounts.txt");
        while(infile.is_open() && infile.good())
        {
            getline(infile, line);
            istringstream ss(line);
            ss >> number >> name >> balance;
            if(!infile.eof())
            {
                Account acct(name, number, balance);
                //accts.insert(pair<int, Account>(number, acct));
                accts[number] = acct;
            }

        }
        infile.close();
        if(accts.empty())
        {
            number = 1;
        }
        else
        {
            number = number + 1;
        }
    }catch(ifstream::failure e)
    {
        cerr << "There was an error: " << e.what() << endl;
    }
}

void Bank::displayMenu()
{
    cout << "Welcome to WEALTH BANK" << '\n';
    cout << "----------------------" << '\n';
    cout << "We Shall Deny No Guest, Even The Most Ridiculous Request" << '\n';
    cout << "Options: " << '\n';
    cout << "1) Open a New Account" << '\n';
    cout << "2) Check Account Details" << '\n';
    cout << "3) Deposit" << '\n';
    cout << "4) Withdraw" << '\n';
    cout << "5) Transfer" << '\n';
    cout << "6) Close" << '\n';
    cout << endl;

    while(true)
    {
        int selection;
        cout << "Enter a Selection: ";
        cin >> selection;

        if(selection < 1 || selection > 6)
        {
            cerr << "Invalid Selection! Please Try Again" << '\n';
        }
        else
        {
            if(selection == 1)
            {
                newAccount();
            }
            else if(selection == 2)
            {

                int temp;
                cout << "Enter Account Number: ";
                cin >> temp;
                accountDetails(temp);


            }
            else if(selection == 3)
            {
                double money;
                int acctNumber;
                cout << "Enter Account Number: ";
                cin >> acctNumber;
                cout << "Enter Amount: ";
                cin >> money;
                deposit(acctNumber, money);
            }
            else if(selection == 4)
            {
                double money;
                int acctNumber;
                cout << "Enter Account Number: ";
                cin >> acctNumber;
                cout << "Enter Amount: ";
                cin >> money;
                withdraw(acctNumber, money);
            }
            else if(selection == 5)
            {
                double money;
                int acctNumber;
                int trans;
                cout << "Enter Your Account Number: ";
                cin >> acctNumber;
                cout << "Enter Account Number to Transfer: ";
                cin >> trans;
                cout << "Enter Amount: ";
                cin >> money;
                transfer(acctNumber, trans, money);
            }
            else if(selection == 6)
            {
                close();
                cout << '\n';
                cout << "Thank You For Visiting!!!";
                break;
            }
        }
    }
}

void Bank::deposit(int& num, double& money)
{
    for(auto it = accts.begin(); it != accts.end(); it++)
    {
        if(it -> first == num)
        {
            it -> second.deposit(money);
            break;
        }
    }
}

void Bank::withdraw(int& num, double& money)
{
    for(auto it = accts.begin(); it != accts.end(); it++)
    {
        if(it -> first == num)
        {
            it -> second.withdraw(money);
            break;
        }
    }
}

void Bank::transfer(int& num, int& trans, double& money)
{
    for(auto it = accts.begin(); it != accts.end(); it++)
    {
        if(it -> first == num)
        {
            it -> second.withdraw(money);
            auto ret = accts.find(trans);
            ret -> second.deposit(money);
            break;
        }
    }
}

void Bank::newAccount()
{
    string name;
    cout << "Please Enter Your Name to Begin New Account Creation: ";
    cin >> name;
    double balance;
    cout << "Please Enter The Balance Towards the Account: ";
    cin >> balance;
    Account acct(name, number, balance);
    accts[number] = acct;
    //accts.insert(pair<int, Account>(number, acct));
    number++;

}

void Bank::accountDetails(int& num)
{
    bool selected = false;
    for(auto it = accts.cbegin(); it != accts.cend(); it++)
    {
        if((it -> first == num))
        {
            selected = true;
            cout << it -> second.getName() << " " << "$" << it -> second.checkBalance() << '\n';
            break;
        }
    }
}

void Bank::close()
{
    ofstream outfile;
    outfile.open("Accounts.txt");
    for (map<int, Account>::iterator it = accts.begin(); it != accts.end(); it++)
    {
        outfile << it->first << " " << it->second.getName() << " " << it->second.checkBalance() << '\n';
    }
    outfile.close();
}

void Bank::run()
{
    displayMenu();
}
