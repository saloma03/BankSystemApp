//
// Created by RTX on 11/14/2022.
//

#ifndef BANK_SAVINGBANKACCOUNT_H
#define BANK_SAVINGBANKACCOUNT_H
#include "BankAccount.h"
class SavingBankAccount :public BankAccount
{
private:
    double MinBalance;
    double Deposit;
    double withDraw;

public:
    SavingBankAccount(double b);
    SavingBankAccount(double b, double Mb);
    virtual void withdraw();
    virtual void setDeposit();
};


#endif //BANK_SAVINGBANKACCOUNT_H
