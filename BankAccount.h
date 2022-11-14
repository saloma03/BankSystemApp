//
// Created by RTX on 11/14/2022.
//

#ifndef BANK_BANKACCOUNT_H
#define BANK_BANKACCOUNT_H
#include<iostream>
using namespace std;
class BankAccount
{
protected:
    string accountID;
    double balance;

public:
    BankAccount();
    BankAccount(double balance);
    void setBalance(double b);
    double getBalance();
    void setAccID(string id);
    string getAccID();
    virtual void withdraw();
    virtual void setDeposit();
};


#endif //BANK_BANKACCOUNT_H
