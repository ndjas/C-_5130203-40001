
#pragma once
#include "clientnode.h"
#include <string>
class ClientBinaryTree{

    private:
        ClientNode *root;


    private:
        void insertNode(ClientNode *&current, std::string clientId);
        ClientNode *findNode(ClientNode *current, std::string cliendId) const;
        void displayInOrder(const ClientNode *current) const;

    public:
        ClientBinaryTree();
        ~ClientBinaryTree();

};
