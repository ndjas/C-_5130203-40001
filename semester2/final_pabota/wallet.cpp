#include <fstream>
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <functional> // pour std::hash
#include <iomanip>
#include <sstream>
#include "Wallet.h"

static std::string const nomFichier_wallet("./data/wallets.txt");
static std::string const nomFichier_operation("./data/operations.txt");
static std::string const nomFichier_transaction("./data/transactions.txt");

Wallet::Wallet(){

};
Wallet::~Wallet(){

};
Wallet::Wallet(std::string id,std::string ownerId, double balance=0.0){
    this->id=id;
    this->ownerId=ownerId;
    this->balance=balance;
};
void Wallet::setWallet(std::string id,std::string ownerId, double balance=0.0){
    this->id=id;
    this->ownerId=ownerId;
    this->balance=balance;
};
void Wallet::setWallet(std::string id,std::string ownerId){
    this->id=id;
    this->ownerId=ownerId;

};

std::string Wallet::mergWallet(){
    std::string merg=this->id+"#"+this->ownerId+"#"+std::to_string(this->balance);
    return merg;
};
//void Wallet::deposit(double amount);
//void Wallet::withdraw(deposit amount);
//double Wallet::getBalance();
//std::string Wallet::getId();

std::string genererIdUniqueLisible() {
    // 1. Obtenir la date/heure formatée
    auto maintenant = std::chrono::system_clock::now();
    auto temps_c = std::chrono::system_clock::to_time_t(maintenant);
    std::tm tm = *std::localtime(&temps_c);

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y%m%d%H%M%S");

    // 2. Ajouter des nanosecondes
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(
                    maintenant.time_since_epoch()).count() % 1000000000;
    ss << std::setw(9) << std::setfill('0') << nanos;

    // 3. Calculer le hash
    std::hash<std::string> hasher;
    size_t hash = hasher(ss.str());

    // 4. Combiner date et hash
    std::stringstream result;
    result << std::put_time(&tm, "%Y%m%d_") << std::hex << hash;

    return result.str();
}


std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
};

void nwBlocWallet(std::string s){

    std::ofstream monFlux(nomFichier_wallet.c_str());


    if(monFlux)
    {
        monFlux<<s<<std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

    std::cout<<"(1)  Operation done \U0001F600 \a"<<std::endl;



}

std::vector<int> find_wallet(){
    std::string walletId;
    int compt=0;
    std::cout<<"enter the account id"<<std::endl;
    std::cin>>walletId;
    std::string delimiter="#";

    std::ifstream fichier_wallet(nomFichier_wallet.c_str());
    if(fichier_wallet){
        std::string line;
         while(getline(fichier_wallet, line) ) //Tant qu'on n'est pas à la fin, on lit
            {
                std::vector <std::string> bk_prt = split(line,delimiter);
                if(bk_prt[0]==walletId){
                    std::cout<<"find"<<std::endl;
                    return {1,compt};
                }else{
                    compt+=1;
                    continue;

                }
            }
    }

return {0,-1};

};

std::vector<int> find_wallet(std::string walletId){
    int compt=0;
    std::string delimiter="#";

    std::ifstream fichier_wallet(nomFichier_wallet.c_str());
    if(fichier_wallet){
        std::string line;
         while(getline(fichier_wallet, line) ) //Tant qu'on n'est pas à la fin, on lit
            {
                std::vector <std::string> bk_prt = split(line,delimiter);
                if(bk_prt[0]==walletId){
                    std::cout<<"find"<<std::endl;
                    return {1,compt};
                }else{
                    compt+=1;
                    continue;

                }
            }
    }

return {0,-1};

};

void deposit(){

    int compt=0;
    std::vector <int> vc_wal=find_wallet();
    std::vector <std::string> k_line;
    std::string delimiter="#";
    std::string nwBloc="";

    if(vc_wal[0]){
        double amount;
        std::cout<<"How much do you want to deposit"<<std::endl;
        std::cin>>amount;
        std::ifstream fichier_wallet(nomFichier_wallet.c_str());
        if(fichier_wallet){
            std::string line;
            while(getline(fichier_wallet, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {

                if(vc_wal[1]==compt){
                    k_line = split(line,delimiter);
                    k_line[2]=std::to_string(amount + std::stod(k_line[2]));

                }else{
                    nwBloc+=line+"\n";
                }
                compt+=1;
            }
        }
    }else{
        std::cout<<"the account don't exist "<<std::endl;
    }
    nwBloc+=k_line[0]+delimiter+k_line[1]+delimiter+k_line[2];
    nwBlocWallet(nwBloc);





};

int deposit(std::string account, double amount){
    int did=0;
    int compt=0;
    std::vector <int> vc_wal=find_wallet(account);
    std::vector <std::string> k_line;
    std::string delimiter="#";
    std::string nwBloc="";

    if(vc_wal[0]){
        std::ifstream fichier_wallet(nomFichier_wallet.c_str());
        if(fichier_wallet){
            std::string line;
            while(getline(fichier_wallet, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {

                if(vc_wal[1]==compt){
                    k_line = split(line,delimiter);
                    k_line[2]=std::to_string(amount + std::stod(k_line[2]));
                    did=1;

                }else{
                    nwBloc+=line+"\n";
                }
                compt+=1;
            }
        }
    }else{
        std::cout<<"the account don't exist "<<std::endl;
    }
    nwBloc+=k_line[0]+delimiter+k_line[1]+delimiter+k_line[2];
    nwBlocWallet(nwBloc);



    return did;

};

void withdraw(){

    int compt=0;
    std::vector <int> vc_wal=find_wallet();
    std::vector <std::string> k_line;
    std::string delimiter="#";
    std::string nwBloc="";

    if(vc_wal[0]){
        double amount;
        std::cout<<"How much do you want to remove"<<std::endl;
        std::cin>>amount;
        std::ifstream fichier_wallet(nomFichier_wallet.c_str());
        if(fichier_wallet){
            std::string line;
            while(getline(fichier_wallet, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {

                if(vc_wal[1]==compt){
                    k_line = split(line,delimiter);
                    if(std::stod(k_line[2])<=amount){
                        std::cout<<"not enough money"<<std::endl;
                        break;
                    }else{
                        k_line[2]=std::to_string(std::stod(k_line[2]) - amount);
                    }


                }else{
                    nwBloc+=line+"\n";
                }
                compt+=1;
            }
        }
    }else{
        std::cout<<"the account don't exist "<<std::endl;
    }
    nwBloc+=k_line[0]+delimiter+k_line[1]+delimiter+k_line[2];
    nwBlocWallet(nwBloc);





};

int withdraw(std::string account, double amount){
    int did=0;
    int compt=0;
    std::vector <int> vc_wal=find_wallet(account);
    std::vector <std::string> k_line;
    std::string delimiter="#";
    std::string nwBloc="";

    if(vc_wal[0]){
        std::ifstream fichier_wallet(nomFichier_wallet.c_str());
        if(fichier_wallet){
            std::string line;
            while(getline(fichier_wallet, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {

                if(vc_wal[1]==compt){
                    k_line = split(line,delimiter);
                    if(std::stod(k_line[2])<=amount){
                        std::cout<<"not enough money"<<std::endl;
                        break;
                    }else{
                        k_line[2]=std::to_string(std::stod(k_line[2]) - amount);
                        did=1;
                    }


                }else{
                    nwBloc+=line+"\n";
                }
                compt+=1;
            }
        }
    }else{
        std::cout<<"the account don't exist "<<std::endl;
    }
    nwBloc+=k_line[0]+delimiter+k_line[1]+delimiter+k_line[2];
    nwBlocWallet(nwBloc);


    return did;


};

void transaction(){
    std::ofstream monFlux_trans(nomFichier_transaction.c_str(),std::ios::app);
    int control;
    std::string acc1;
    std::string acc2;
    std::string line=genererIdUniqueLisible();
    double amount;
    std::cout<<"enter the account of the sender"<<std::endl;
    std::cin>>acc1;
    std::cout<<"enter the account of the receiver"<<std::endl;
    std::cin>>acc2;
    std::cout<<"enter the account of the amount"<<std::endl;
    std::cin>>amount;

    if(withdraw(acc1,amount)){
        if(deposit(acc2,amount)){
            std::cout<<"transaction done"<<std::endl;
        }else{
            control=deposit(acc1,amount);
            std::cout<<"we found a problem in the transaction"<<std::endl;
        }
    }else{
        std::cout<<"we found a problem in the transaction"<<std::endl;
    }
    line+="#"+acc1+"#"+acc2+"#"+std::to_string(amount);
     if(monFlux_trans)
    {
        monFlux_trans <<line<< std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }



};

void listTransaction(){

    int compt=0;
    std::vector <std::string> k_line;
    std::ifstream fichier_transaction(nomFichier_transaction.c_str());
    std::string delimiter="#";
        if(fichier_transaction){
            std::string line;
            while(getline(fichier_transaction, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {


                    k_line = split(line,delimiter);
                    compt+=1;
                    std::cout<<"["<<compt<<"]Sender:"<<k_line[1]<<"{ \n  Id: "<<k_line[0]<<"\n  Amount: "<<k_line[3]<<"\n  Receiver: "<<k_line[2]<<" }\n"<<std::endl;





            }
            std::cout<<"we found "<<compt<<" transaction(s) \n"<<std::endl;
        }

};
