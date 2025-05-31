/*
    Template for class client
*/
//#pragma once
#include <string>
#include <vector>

class Wallet{

    public:
        std::string id;
        double balance=0.0;
        std::string ownerId;

    public:
        Wallet();
        ~Wallet();
        Wallet(std::string id,std::string ownerId, double balance);
        //Client(double val, std::string val2):pourcentage(val),type(val2){}
        //void deposit(double amount);
        //void withdraw(deposit amount);
        void setWallet(std::string id,std::string ownerId, double balance);
        void setWallet(std::string id,std::string ownerId);
        std::string mergWallet();
        double getBalance();
        std::string getId();


};
void deposit();
void withdraw();
int deposit(std::string account, double montant);
int withdraw(std::string account, double montant);
std::vector<std::string> find_wallet(std::string walletId);
void transaction();
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<int> find_wallet();
void nwBlocWallet(std::string s);
std::string genererIdUniqueLisible();
void listTransaction();
