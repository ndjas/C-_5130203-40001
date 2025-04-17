#include <iostream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>

#define _USE_MATH_DEFINES

using namespace std;

int main() {
    int choice=0,number=NULL;
    char asking;
    string num_str=to_string(number); //global definition of the variable
    
    menu_return : //name of the label for my goto 

    cout << "---------------------------------------------------"<<endl;
    cout<<"What do you want to do?"<<endl;
    cout << "[1]. Enter a number in the range between 1000 and 999999"<<endl;
    cout << "[2]. Print the digits of the number"<<endl;
    cout << "[3]. Count how many digits the number have"<<endl;
    cout << "[4]. Return the lowest and highest digits of the number"<<endl;
    cout << "[5]. Return the sum of the digits of the number"<<endl;
    cout << "[6]. Return the product of the odd digits"<<endl;
    cout << "[7]. Calculate the inverted version of the number"<<endl;
    cout << "---------------------------------------------------"<<endl;

    cout << "Enter option: "<<endl;
    cin>>choice;
    
    
    switch (choice) {
        case 1:

            do{
                cout<<"enter your number between [1000,999999999999]"<<endl;
                cin>>number;
            }while (number<1000 || number>999999999999);
            
            //return part
            cout << "Do you want to continue [y/n]? ";
            cin>> asking;
            if (asking=='y' || asking=='Y'){ //take care about capital letter
                goto menu_return; //return to the menu selection
            }else {
                cout<<"thank for using our program!!" <<endl;
                break;
            }
            
        case 2:
            
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
                num_str=to_string(number);
                int i=num_str.length();
                while (i>1){
                    cout<< num_str[i-1]<<",";
                    i--;
                }
                cout<< num_str[0]<<"."<<endl;
            
            //return part
                cout << "Do you want to continue [y/n]? ";
                cin>> asking;
                if (asking=='y' || asking=='Y'){
                    goto menu_return;
                }else {
                    cout<<"thank for using our program!!" <<endl;
                    break;
                }
            }
            
            
        case 3:
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
                num_str=to_string(number);
                int i=num_str.length(); //just return the lenght of string
                cout<<"The number have: "<<i<<" digit(s)"<<endl;
            }
            //return part
            cout << "Do you want to continue [y/n]? ";
            cin>> asking;
            if (asking=='y' || asking=='Y'){
                goto menu_return;
            }else {
                cout<<"thank for using our program!!" <<endl;
                break;
            }
            
            
        case 4:
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
            
                num_str=to_string(number);
                int i=num_str.length();
                char elmnt=num_str[i-1];
                char max, min;
                max=num_str[0];
                min=num_str[0];

                for(int j=1;j<i;j++){
                    if ((num_str[j]-'0')>(max-'0')){ //act like cast in int
                        max=num_str[j];
                    }
                }
                for(int j=1;j<i;j++){
                    if ((num_str[j]-'0')<(min-'0')){ //act like cast in int
                        min=num_str[j];
                    }
                    
                }

                cout << "The highest number is: "<< max <<"\nThe smallest is: "<< min<<endl;
            
            //retuen place
                cout << "Do you want to continue [y/n]? ";
                cin>> asking;
                if (asking=='y' || asking=='Y'){
                    goto menu_return;
                }else {
                    cout<<"thank for using our program!!" <<endl;
                    break;
                }
            }
        
        case 5:
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
                num_str=to_string(number);
                int i=num_str.length();
                char elmnt=num_str[i-1];
                int sum=0;
                
                while (i>=1){
                    int a = num_str[i-1] - '0'; //act like a cast
                    sum = sum + a;
                    i--;
                }
                
                cout << "The sum of number of the number is: "<< sum <<endl;
            
            //return place
                cout << "Do you want to continue [y/n]? ";
                cin>> asking;
                if (asking=='y' || asking=='Y'){
                    goto menu_return;
                }else {
                    cout<<"thank for using our program!!" <<endl;
                    break;
                }
            }
        
        case 6:
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
                num_str=to_string(number);
                int i=num_str.length();
                char elmnt=num_str[i-1];
                
                int prod=1;

                while (i>=1){
                    int a = num_str[i-1] - '0';
                    if((a%2)!=0){
                        prod = prod * a;
                    }
                    i--;
                }
                
                cout << "The multiplication of odd number is : "<< prod <<endl;
            
            //return place
                cout << "Do you want to continue [y/n]? ";
                cin>> asking;
                if (asking=='y' || asking=='Y'){
                    goto menu_return;
                }else {
                    cout<<"thank for using our program!!" <<endl;
                    break;
                }
            }
        
        case 7:
            if (number==NULL){
                cout<<"you must define a number"<<endl;
                goto menu_return;
            }else{
                num_str=to_string(number);
                int i=num_str.length();
                cout<< "reverse number: ";
                while (i>=1){
                    cout<< num_str[i-1];
                    i--;
                }
                cout<<"\n";
            
            //return place
                cout << "Do you want to continue [y/n]? " ;
                cin>> asking;
                if (asking=='y' || asking=='Y'){
                    goto menu_return;
                }else {
                    cout<<"thank for using our program!!" <<endl;
                    break;
                }
            }
            
        }

    return 0;
}