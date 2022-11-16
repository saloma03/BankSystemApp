//
// Created by RTX on 11/14/2022.
//

#include "Client.h"
Client::Client(){}
Client::Client(string n, string ad, string ph, string type,BankAccount* ptr)
{
    name = n;
    address = ad;
    phone = ph;
    accountType = type;
    b = ptr;
}
//****************************************getters for the attributes the Client Class**********************************
string Client::getName() { return name;}
string Client::getAddress() {return address;}
string Client::gatPhone() {return phone;}
string Client::getAccType() {return accountType;}
BankAccount* Client::getAccount(){return b;}
//*******************************************Setters for the attributes of Client Class*********************************
void Client::setName(string n) { name = n;}
void Client::setAddress(string ad) { address = ad;}
void Client::setPhone(string ph) { phone = ph;}
void Client::setType(string t) { accountType = t;}
//**************************************************************************************
