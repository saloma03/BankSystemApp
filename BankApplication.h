//
// Created by RTX on 11/14/2022.
//

#ifndef BANK_BANKAPPLICATION_H
#define BANK_BANKAPPLICATION_H

#include "Client.h"
#include<bits/stdc++.h>

class BankApplication {
    vector<Client> Clients;
    vector<BankAccount> accounts;
public:
    BankApplication();
    void addClient();
    int no_client();
    void  load_data(int ch);
    void list_clients();
    void vectorToFile();
    void FileToVector();
    bool is_empty(std::ifstream& pFile);
    ~BankApplication();
};

#endif //BANK_BANKAPPLICATION_H
