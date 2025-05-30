/*
    Template for class client
*/
#pragma once
#include <string>


class Client{

    private:
        std::string id;
        std::string name;
        std::string wallet;
        const double pourcentage=0.0;

    public:
        Client();
        ~Client();
        Client(std::string id,std::string name);        
        Client(std::string id,std::string name,std::string wallet);
        Client(double val):pourcentage(val){}
        void addWallet(std::string wallet);
        double getTotalBalance();
        double calculateCommission(double amount);
        std::string getId();
        double calculate_area();
       
};
class goldClient : public Client{
private:
    /* data */
    goldClient():Client(0.5){}
public:
    goldClient(std::string id,std::string name);
    ~goldClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
class standardClient : public Client{
private:
    /* data */
    standardClient():Client(0.1){}
public:
    standardClient(std::string id,std::string name);
    ~standardClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
class platinumClient : public Client{
private:
    /* data */
    platinumClient():Client(1.0){}
public:
    platinumClient(std::string id,std::string name);
    ~platinumClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
Client newClient();