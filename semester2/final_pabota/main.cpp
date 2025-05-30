#include <iostream>
#include "Client.h"
#include "Wallet.h"


//using namespace std;

int main()
{
    //std::cout << "Hello world!" << std::endl;


      int choice;



    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "Welcome To MATOBEC Bank" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "By @leStatois" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << " " <<std::endl;
    first_menu:
    std::cout << "1- Clien Management " <<std::endl;
    std::cout << "2- Operation Management " <<std::endl;
    std::cout << "3- Wallet Management" <<std::endl;
    //cout << "4- Order Détail Management" <<endl;
    std::cout << "Press 4 - For Exit the Prograam" <<std::endl;
    std::cout << " " <<std::endl;

    std::cout << "choose an option:" <<std::endl;
    std::cin>>choice;


    while(1){

      if(choice==1){
        choice_fst:
        int var;
        std::cout << "::::::::::::::::::::::::::::" <<std::endl;
        std::cout << "choose an option:" <<std::endl;
        std::cout << "1- create new client" <<std::endl;
        std::cout << "2- list client" <<std::endl;
        std::cout << "other to return to the main" <<std::endl;
        std::cin>>var;

        if(var==1){
            newClient();
            std::cout<<""<<std::endl;
            goto first_menu;
        }else if(var==2){
            listClient();
            std::cout<<""<<std::endl;
            goto first_menu;
        }else{
            goto choice_fst;
        }


        //listClient();
        //transaction();
        //break;
        //goto first_menu;
      }
    else if(choice==2){
        choice_snd:
        int var;
        std::cout << "::::::::::::::::::::::::::::" <<std::endl;
        std::cout << "choose an option:" <<std::endl;
        std::cout << "1- make a deposit" <<std::endl;
        std::cout << "2- make a withdraw" <<std::endl;
        std::cout << "3- transfert to another client" <<std::endl;
        std::cout << "4- list transactions" <<std::endl;
        std::cout << "5- list operations" <<std::endl;
        std::cout << "other to return to the main" <<std::endl;

        std::cin>>var;
        if(var==1){
            deposit();
            std::cout<<"\n"<<std::endl;
            goto first_menu;
        }else if(var==2){
            withdraw();
            std::cout<<"\n"<<std::endl;
            goto first_menu;
        }else if(var==3){
            transaction();
            std::cout<<"\n"<<std::endl;
            goto first_menu;
        }else if(var==4){
            listTransaction();
            std::cout<<"\n"<<std::endl;
            goto first_menu;
        }else if(var==5){
            //listTransaction();
            std::cout<<"this part is in construction\n"<<std::endl;
            std::cout<<"\n"<<std::endl;
            goto first_menu;
        }else{goto choice_snd;}


    }
    else if(choice==3){
        std::cout<<"this part is in construction\n"<<std::endl;
    }
    else if(choice==4 ){
        break;
    }else{
        std::cout<<"\n"<<std::endl;
        std::cout<<"make a correct choice\n"<<std::endl;
        goto first_menu;
    }

    }


    return 0;
}
