// Your First C++ Program

#include <iostream>
#include <cmath>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;

int main() {

    double A,T,X=0;
    char G,R,W;
    int k,F=0;

    cout << "please respect entry!!!!!" <<endl;

    cout << "enter the dimesion of your land in meter square" <<endl;
    cin >> A;
    X=A;
    cout << "do you have a garden? (y/n)" <<endl;
    cin >> G;
    if(G=='y'){
        T=1000*X;
    }
    cout << "do you have a roof? (y/n)" <<endl;
    cin >> R;
    if(R=='y'){
        T=T+(5000*X);
    }else{
        T=T+(3000*X);
    }
    cout << "what is the quality of your materials? give a note between 1 and 5 in integer" <<endl;
    cin >> k;
    if(k<2){
        T=T+(5*T)/100;
    }else if(k<4){
        T=T+(10*T)/100;
    }else{
        T=T+(15*T)/100;
    }
    cout << "do you have water and toilet (y/n)" <<endl;
    cin >> W;
    if(W=='y'){
        T=T+2500;
    }
    cout << "How many floor do you have?" <<endl;
    cin >> F;
    if(k<=2){
        T=T+(10*T)/100;
    }else if(k==4 || k==3){
        T=T+(10*T)/100;
    }else{
        T=T+(20*T)/100;
    }

    cout << "You are going to pay : " << T << " rub" <<endl;



    //while(1){
        
   // }
    return 0;
}
