cmake_minimum_required(VERSION 3.23)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp BankAccount.cpp BankAccount.h SavingBankAccount.cpp SavingBankAccount.h Client.cpp Client.h BankApplication.cpp BankApplication.h)
