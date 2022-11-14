//
// Created by RTX on 11/14/2022.
//

#include "SavingBankAccount.h"
#include "BankAccount.h"
SavingBankAccount::SavingBankAccount(double p) : BankAccount(p)
{
    BankAccount();
    MinBalance = 1000;
}
//**********************************constructor to set default value of Min Balance = 1000 L.E *************************
SavingBankAccount::SavingBankAccount(double b, double Mb):BankAccount(b)
{
    if (b > Mb && b > Mb) {
        MinBalance = Mb;
    }
    else
        cout << "Your Balance should be bigger than or equal MinBalance" << endl;

}
//***********************************fun to set amount of deposit ******************************************************
void SavingBankAccount::setDeposit()
{
    label:
    cout << "Enter amount money to deposit:";
    cin >> Deposit;
    while (Deposit < 100) {
        cout << "Sorry! You Can NOT deposit less than 100 " << endl;
        goto label;
    }
    balance += Deposit;
    cout << "Thank you."
         << "\nAccount ID: " << accountID
         << "\nNew Balance: "<< balance << "\n";

}
//***********************************************Function to WithDraw Money*********************************************
void SavingBankAccount::withdraw()
{
    label:
    cout << "Enter amount of withdrawing:";
    cin >> withDraw;
    while (balance - withDraw < MinBalance) {
        cout << "Sorry! You Can NOT withdrawing this value" << endl;
        goto label;
    }
    balance -= withDraw;
    cout << "Thank you."
         << "\nAccount ID: " << accountID
         << "\nNew Balance: "<< balance << "\n";

}