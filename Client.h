//
// Created by RTX on 11/14/2022.
//

#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H
#include<iostream>
#include "BankAccount.h"
using namespace std;
class Client{
    string name;
    string phone;
    string address;
    string accountType;
    BankAccount* b;

public:
    Client();
    Client(string n, string ad, string ph, string type,BankAccount* ptr);
    string getName();
    string getAddress();
    string gatPhone();
    BankAccount* getAccount();
    string getAccType();
    void setName(string n);
    void setPhone(string ph);
    void setAddress(string ad);
    void setType(string t);

};
#endif //BANK_CLIENT_H
