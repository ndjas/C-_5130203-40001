#include <random>
#include <iostream>
#include <string>
#include "Client.h"

uint64_t generateUUID();

uint64_t generateUUID() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;
    return dis(gen);  // Génère un nombre 64 bits aléatoire
}

Client::Client(){

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

Client newClient(){
    
    std::string name;
    char ask;
    std::string wallet;
    uint64_t n_wallet;
    n_wallet=generateUUID();
    std::string id_c=std::to_string(n_wallet);
    id_c="c-"+id_c;
    Client client;

    std::cout<<"enter the name of the client"<<std::endl;
    std::cin >>name;
    std::cout<<"do you want to create a wallet now?(y/n)"<<std::endl;
    std::cin>>ask;

    
    if(ask=='y'){
        n_wallet=generateUUID();
        wallet=std::to_string(n_wallet);
        Client client(id_c,name,wallet);
        return client; 
    }else if(ask=='n'){
        Client client(id_c,name); 
        return client;
    }else{
        std::cout<<"incorrect choice"<<std::endl;
    }
    
    return client;


}