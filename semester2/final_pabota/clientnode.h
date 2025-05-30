
#include "Client.h"
#include <string>

class ClientNode{

    private:
        std::string clientId;
        ClientNode *cliLeft;
        ClientNode *cliRight;

    public:
        ClientNode();
        ClientNode(std::string clientId);
        //Node(const Node &child);
        ~ClientNode();
        //void setValue(int val);
        //int getValue() const;
        //void setLeft(Node *left);
        //Node *getLeft();
        //void setRight(Node *right);
        //Node *getRight();

    //friend class BinaryTree;
};
