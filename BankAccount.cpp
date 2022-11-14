//
// Created by RTX on 11/14/2022.
//

#include "BankAccount.h"

//********************************defult constructor to intialize balance with 0 L.E.***********************************
BankAccount::BankAccount()
{
    balance = 0;
}
//*******************************constructor to set value of balance BY calling setBalance method***********************
BankAccount::BankAccount(double balance)
{
    setBalance(balance);
}
//********************************fun to set value of balance***********************************************************
void BankAccount::setBalance(double b)
{
    balance = b;
}
//**********************************fun to print value of balance ******************************************************
double BankAccount::getBalance()
{
    return balance;
}
void BankAccount::setAccID(string id)
{
    accountID = id;
}
string BankAccount::getAccID()
{
    return accountID;
}
//**********************************fun to accept amount and subtract it from balance amount****************************
void BankAccount::withdraw()
{
    double draw  ,Newbalance;
    label:
    cout << "Enter the amount you want to draw" << endl;
    cin >> draw;
    while(draw > balance)
    {
        cout << "Sorry. This is more than what you can withdraw." << endl;
        goto label;
    }

    if (balance >= draw &&((balance-draw)>100) ) {
        Newbalance = balance - draw;
        balance = Newbalance;

        cout << "Thank you."
             << "\nAccount ID: " << accountID
             << "\nNew Balance: " << balance << "\n";
    }
    else
    {
        cout<<"sorry, you can not take this amount of money!"<<endl;
    }
}
//************************************fun to accept amount and add it to balance amount*********************************
void BankAccount::setDeposit()
{
    double deposit;
    cout << "Enter the amount you want to deposit" << endl;
    cin >> deposit;
    balance += deposit;
    cout << "Thank you."
         << "\nAccount ID: " << accountID
         << "\nNew Balance: "<< balance << "\n";
}
