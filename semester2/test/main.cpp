#include <iostream>
#include "Client.h"



int main(){

      int choice;

    

    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "Welcome To MATOBEC Bank" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "By @leStatois" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << " " <<std::endl;
    first_menu:
    std::cout << "1- Account Management \U0001F4D8" <<std::endl;
    std::cout << "2- Client Management \U0001F469" <<std::endl;
    std::cout << "3- Order Management \U0001F4C9" <<std::endl;
    //cout << "4- Order Détail Management" <<endl;
    std::cout << "Press Ctrl + (C) - For Exit the Prograam" <<std::endl;
    std::cout << " " <<std::endl;

    std::cout << "choose an option:" <<std::endl;
    std::cin>>choice;


    while(1){
      if(choice==1){
        Client client=newClient();
        break;
      }
       
    }
   return 0;

}