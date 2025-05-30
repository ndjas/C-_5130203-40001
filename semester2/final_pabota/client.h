/*
    Template for class client
*/
//#pragma once
#include <string>


class Client{

    public:
        std::string id;
        std::string name;
        std::string wallet;
        double pourcentage;
        std::string type;

    public:
        Client();
        ~Client();
        Client(std::string id,std::string name);
        Client(const std::string &type, const double &pourcentage):type(type),pourcentage(pourcentage){}
        Client(std::string id,std::string name,std::string wallet);
        //Client(double val, std::string val2):pourcentage(val),type(val2){}
        void addWallet(std::string wallet);
        double getTotalBalance();
        double calculateCommission(double amount);
        std::string getId();
        double calculate_area();
        void getClient();
        void setClient(std::string id,std::string name,std::string wallet);
        std::string mergClient();
        void copyClient(Client a);

};
class goldClient : public Client{
public:
    /* data */
    goldClient():Client("goldClient",0.5){}

public:
    goldClient(std::string id,std::string name);
    ~goldClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
class standardClient : public Client{
public:
    /* data */
    standardClient():Client("standardClient",0.1){}

public:
    standardClient(std::string id,std::string name);
    ~standardClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
class platinumClient : public Client{
public:
    /* data */
    platinumClient():Client("platinumClient",1.0){}


public:
    platinumClient(std::string id,std::string name);
    ~platinumClient();
    double calculateCommission(double amount);
    double getTransactionId();
    std::string getBenefits();

};
void newClient();
void listClient();
