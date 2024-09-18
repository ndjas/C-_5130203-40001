// Your First C++ Program

#include <iostream>
#include <cmath>
#include <math.h>

#define _USE_MATH_DEFINES

using namespace std;

int main() {

    int A;

    cout << "------------------------------------------------------" <<endl;
    cout << "Welcome To The exercice Of The Fist Week 5130203/40001" <<endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "By @leStatois" <<endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "choose an option:" <<endl;
    cout << " " <<endl;

    cout << "1- For the first exercice" <<endl;
    cout << "2- For the second exercice" <<endl;
    cout << "3- For the third exercice" <<endl;
    cout << "- For the fourth exercice" <<endl;
    cout << "Press Ctrl + (C) - For Exit the Program" <<endl;
    cout << " " <<endl;


    cin >> A;    



    while(1){
       
         if(A==1){
            //cout << "enter the coefficient A est de 1 " <<endl;
            //cout << "\n " <<endl;
            //cout << " " <<endl;

            //start for the 1

                    double A,w,fo,T,X=0;
                    int k=0;

                    cout << "enter the coefficient A" <<endl;
                    cin >> A;
                    cout << "enter the coefficient w" <<endl;
                    cin >> w;
                    cout << "enter the coefficient k" <<endl;
                    cin >> k;
                    //cout << "A est de valeur " << A;
                    fo=asin(1.0/k)*180.0/M_PI; //affectation values of fo, and *180/3.1415 because to work in degree
                    //fo=asin(0.23)*180/3.1415;
                    //fo=1.0/k;
                    T=((M_PI/2.0)-fo)/w;
                    //T=M_PI;

                    X= A*sin(((w*T)+fo)*M_PI/180.0); //result of X(T) , *m_pi to convert angle in radians

                    cout << "the result of X("<< T <<")= " << A <<".sin[(" << T << ") x ("<< w <<") + ("<< fo <<")] est  '" << X <<"'" <<endl;
            //end

            main();
        } 
        if(A==2){
            //cout << "enter the coefficient A est de 2" <<endl;
            //cout << "\n " <<endl;
            //cout << " " <<endl;

            //start for the 2

                    double H,V,ang,T,X,Y=0;
                    double g=9.8;

                    cout << "enter the coefficient of height (meter)" <<endl;
                    cin >> H;
                    cout << "enter the coefficient of celerity (v/s)" <<endl;
                    cin >> V;
                    cout << "enter the coefficient of angle in degree (°)" <<endl;
                    cin >> ang; 
                    T=(V*sin(ang*M_PI/180.0)/g)*(1+sqrt(1+((2*g*H)/V*V*pow(sin(ang*M_PI/180.0),2))));
                    
                    //calcul de la valeur de X

                    X= V*T*cos(ang*M_PI/180.0);

                    //calcul de la valeur de Y

                    Y= H + (V*T*sin(ang*M_PI/180.0))-(0.5*g*pow(T,2));
                    

                    cout << "the result of position and time in format: [(X(t),Y(t),t)] ==> [( "<< X <<"m, "<< Y <<"m, "<< T <<"s )]" <<endl;

            //end

            main();
        } 
        if(A==3){
            //cout << "enter the coefficient A est de 3" <<endl;
            //cout << "\n " <<endl;
            //cout << " " <<endl;

            //start for the 3

                    double X,G,F,boolean=0;
                    int k=0;

                    cout << "enter the coefficient X" <<endl;
                    cin >> X;
                    
                    if (X >-4 && X < -1){
                        //cout << "je suis fou" <<endl;
                        G=abs(X+6)/(abs(X+3)-3) ;
                    }else if(X >-1 && X < 5){
                        G=sqrt(5-X)-2;
                    }else if(X >=5){
                        G=log(X+10)-2;
                    }else{
                        boolean=1; //testing if a value is small than -4
                    }

                    if (boolean==1){
                        cout << "the number "<< X <<" is not in the domain of G, so F don't exist" <<endl;
                        
                    }else if(G < -2){
                        F=abs(X/1-X);
                        cout << "value of F= "<< F << " and the value of G= " << G <<endl;
                    }else if(G >=-2 && G <= 1){
                        F=pow(G+2,2);
                        cout << "value of F= "<< F << " and the value of G= " << G <<endl;
                    }else{
                        cout << "the number  from G(x) '"<< G <<"' is not in the domain of F, so F don't exist" <<endl;
                    }

            //end

            main();
        } 
        if(A==4){
            cout << "In Process...." <<endl;
            //cout << "\n " <<endl;
            //cout << " " <<endl;
            main();
        }
        
   }
    return 0;
}
