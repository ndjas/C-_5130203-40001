#include <fstream>
#include <random>
#include <iostream>
#include <string>
#include <chrono>
#include <functional> // pour std::hash
#include <iomanip>
#include <sstream>
#include "Client.h"
#include "Wallet.h"

uint64_t generateUUID();

uint64_t generateUUID() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;
    return dis(gen);  //Génère un nombre 64 bits aléatoire
}

static std::string const nomFichier_client("./data/clients.txt");
static std::string const nomFichier_wallet("./data/wallets.txt");

Client::Client(){

};

goldClient::goldClient(std::string id,std::string name){
    this->id=id;
    this->name=name;
};

standardClient::standardClient(std::string id,std::string name){
    this->id=id;
    this->name=name;
};

platinumClient::platinumClient(std::string id,std::string name){
    this->id=id;
    this->name=name;
};

Client::Client(std::string id,std::string name,std::string wallet){
    this->id=id;
    this->name=name;
    this->wallet=wallet;
};

Client::Client(std::string id,std::string name){
    this->id=id;
    this->name=name;
};

Client::~Client(){};
goldClient::~goldClient(){};
platinumClient::~platinumClient(){};
standardClient::~standardClient(){};

void Client::getClient(){
    std::cout<<"id: "<<this->id<<std::endl;
    std::cout<<"wallet: "<<this->wallet<<std::endl;
    std::cout<<"name: "<<this->name<<std::endl;
    std::cout<<"type: "<<this->type<<std::endl;
    std::cout<<"percent: "<<this->pourcentage<<std::endl;

};

std::string Client::mergClient(){
    std::string merg=this->id+"#"+this->name+"#"+this->wallet+"#"+this->type+"#"+std::to_string(this->pourcentage);
    return merg;
}

void Client::setClient(std::string id,std::string name,std::string wallet){
    this->id=id;
    this->name=name;
    this->wallet=wallet;
};

void Client::copyClient(Client a){
    this->id=a.id;
    this->name=a.name;
    this->wallet=a.wallet;
    this->type=a.type;
    this->pourcentage=a.pourcentage;
};

void newClient(){
    std::ofstream monFlux(nomFichier_client.c_str(),std::ios::app);
    std::ofstream monFlux_wallet(nomFichier_wallet.c_str(),std::ios::app);

    std::string name;
    char ask;
    std::string walletId;
    //uint64_t n_cli;
    //n_cli=generateUUID();
    //std::string id_c=std::to_string(n_cli);
    std::string id_c=genererIdUniqueLisible();
    id_c="c-"+id_c;
    Client client;
    Wallet wallet;
    char type;

    std::cout<<"enter the name of the client"<<std::endl;
    std::cin >>name;
    std::cout<<"do you want to create a wallet now?(y/n)"<<std::endl;
    std::cin>>ask;
    type_client:
    std::cout<<"what kind of client do you want to create"<<std::endl;
    std::cout<<"standard: S \nGold: G\nPlatinum: P\n"<<std::endl;
    std::cin >>type;


    if(ask=='y'){
        //uint64_t n_wallet=generateUUID();
        //walletId=std::to_string(n_wallet);
        walletId=genererIdUniqueLisible();
        wallet.setWallet(walletId,id_c);

        if(type=='S'){
            standardClient temp;
            temp.setClient(id_c,name,walletId);
            //temp.getClient();
            client.copyClient(temp);


        }else if(type=='G'){
            goldClient temp;
            temp.setClient(id_c,name,walletId);
            client.copyClient(temp);

        }else if(type=='P'){
            platinumClient temp;
            temp.setClient(id_c,name,walletId);
            client.copyClient(temp);

        }else{
            goto type_client;
        }
        //client.setClient(id_c,name,wallet);
        //client.getClient();
        std::cout<<"the wallet "<<walletId<<" correctly created for the client "<< id_c <<std::endl;
        //return client;
    }else if(ask=='n'){
        Client client(id_c,name);
        //return client;
        std::cout<<"client create correctly"<<std::endl;
    }else{
        std::cout<<"incorrect choice"<<std::endl;
    }

    if(monFlux)
    {
        monFlux << client.mergClient() << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
     if(monFlux_wallet)
    {
        monFlux_wallet << wallet.mergWallet() << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }




};

void listClient(){
    int compt=0;
    std::vector <std::string> k_line;
    std::ifstream fichier_client(nomFichier_client.c_str());
    std::string delimiter="#";
        if(fichier_client){
            std::string line;
            while(getline(fichier_client, line) && line!="" ) //Tant qu'on n'est pas à la fin, on lit
                {


                    k_line = split(line,delimiter);
                    compt+=1;
                    std::cout<<"["<<compt<<"]Name:"<<k_line[1]<<"{ \n  Id: "<<k_line[0]<<"\n  Wallet: "<<k_line[2]<<"\n  Type: "<<k_line[3]<<"\n  Commission:"<<k_line[4]<<" }\n"<<std::endl;





            }
            std::cout<<"we found "<<compt<<" client(s) \n"<<std::endl;
        }
    };


