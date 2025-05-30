
#include "clientnode.h"
//#include "client.h"


ClientNode::ClientNode(){
    this->clientId = "";
    this->cliLeft = nullptr;
    this->cliRight = nullptr;

};
ClientNode::ClientNode(std::string clientId){
    this->clientId = clientId;
    this->cliLeft = nullptr;
    this->cliRight = nullptr;

};
        //Node(const Node &child);
ClientNode::~ClientNode(){

};
