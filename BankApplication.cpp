//
// Created by RTX on 11/14/2022.
//

#include "BankApplication.h"
#include "BankAccount.h"
#include<bits/stdc++.h>
#include "SavingBankAccount.h"
#include "Client.h"
bool BankApplication:: is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
//***********************************************Listing Clients********************************************************
void BankApplication ::list_clients()
{
    for(auto i : Clients)
    {
        BankAccount* b = i.getAccount();
        cout << "--------------------------"+i.getName() +"---------------------------" <<endl;
        cout << "Adress: " << i.getAddress()    << " Phone : " << i.gatPhone() << endl;
        cout << "Account ID : " << b -> getAccID() <<  "( " << i.getAccType() << " )" << endl;
        cout << "Balance : " << b -> getBalance()  << endl;
    }
}
//*****************************************Inserting Data from Vector into File*****************************************
void BankApplication::vectorToFile()
{
    fstream clientsData;
    clientsData.open("temp.txt",ios::out);
    for(auto i : Clients)
    {
        BankAccount* b = i.getAccount();
        clientsData << i.getName() << endl;
        clientsData << i.getAddress() << endl;
        clientsData << i.gatPhone() << endl;
        clientsData << b ->getAccID() << endl;
        clientsData << i.getAccType() << endl;
        clientsData << b -> getBalance() << endl;
        clientsData << endl;
    }
    cout << endl;
    clientsData.close();

}

//****************************************************Insertting the data from file into the vector*********************
void BankApplication::FileToVector()
{
    string name,ad,phone,id,type,line;
    string  palance;
    fstream clientsData;
    clientsData.open("temp.txt",ios::in);

    while(!clientsData.eof())
    {

        getline(clientsData,name);
        if(name.empty())
        {
            clientsData.close();
            break;
        }
        getline(clientsData,ad);
        getline(clientsData,phone);
        getline(clientsData,id);
        getline(clientsData,type);
        getline(clientsData,palance);
        getline(clientsData,line);

        double tem = (double)atof(palance.c_str());
        BankAccount*b;
        if(type == "basic")          b = new BankAccount (tem);
        else if(type == "saving")    b = new SavingBankAccount (tem);
        b -> setAccID(id);
        Client c(name,ad,phone,type,b);
        Clients.push_back(c);
    }
    clientsData.close();
}
//********************************************Loading Data *************************************************************
void BankApplication::load_data(int ch)
{
    string id,line;
    cout << "Please Enter Account ID (e.g., FCAI-015)"; cin >> id;
    for(int i = 0;i < Clients.size();i++)
    {
        BankAccount* b = Clients[i].getAccount();
        if(b -> getAccID() == id)
        {
            cout << "Account ID: " << id << endl;
            cout << "Acocunt Type: " << Clients[i].getAccType() << endl;
            cout << "Balance: " << b -> getBalance() << endl;
            if(ch == 3)
            {
                b -> withdraw();
            }
            if(ch == 4)
            {
                b -> setDeposit();
            }
        }
    }
}
//***********************************************Adding Client**********************************************************
void BankApplication::addClient()
{

    string name,ad,phone,acountType;
    float palance;
    cout << "Please Enter Client Name : ";
    getline(cin,name);
    cout << "Please Enter Client Adress : ";
    getline(cin,ad);
    cout << "Please Enter Client Phone : ";
    getline(cin,phone);
    cout << "What Type (basic/saving)  : ";
    getline(cin,acountType);
    cout << "Enter a Palance to Sart With: ";
    cin >> palance;
    //cout << name<< " "<<ad<<" "<<phone<<" "<< acountType<<" "<<palance<<endl;
    BankAccount* P;
    if(acountType == "basic")      P = new BankAccount (palance);
    else if(acountType =="saving") P = new SavingBankAccount(palance);
    string id = "FCAI_"+to_string(this -> no_client());
    P -> setAccID(id);
    Client c(name, ad, phone, acountType,P);
    Clients.push_back(c);
    cout << "An Account Created with ID: " << P -> getAccID() << endl;
}

//***********************************************BankApplication Constructors***************************
BankApplication::BankApplication()
{
    FileToVector();
    int choice;
    cout << "Welcome to FCAI Banking Application\n"
         <<"1. Create a New Account\n"
         <<"2. List Clients and Accounts\n"
         <<"3. Withdraw Money\n"
         <<"4. Deposit Money: ";
    cin >> choice;
    if(choice == 1)
    {
        cin.ignore();
        addClient();
    }
    else if(choice == 2)
    {
        list_clients();
    }
    else
    {
        load_data(choice);
    }
}
//********************************************BankApplication Destructor************************************************
BankApplication::~BankApplication()
{
    vectorToFile();
    for(auto i : Clients)
        delete i.getAccount();
}
//*********************************************************************************************************************
int BankApplication::no_client()
{
    return Clients.size()+1;
}