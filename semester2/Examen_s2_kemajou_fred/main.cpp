#include <iostream>
#include <cmath>

class  Hasselman_Point;
enum SPECTRUM{RED,BLUE};

class  Hasselman_Point
{
private:
    /* data */
    double x;
    double y;
    bool z;
    SPECTRUM color;
public:
    Hasselman_Point(){

    };
    Hasselman_Point(/* args */double x, double y,bool z,SPECTRUM color){
        this->x=x;
        this->y=y;
        this->z=z;
        this->color=color;
     };
    //~ Hasselman_Point();
    void print();

    // Surcharge de l'opérateur + comme fonction membre
    Hasselman_Point operator+(const Hasselman_Point& autre ) const {
        
        Hasselman_Point c;
        c.x=sqrt(pow(x,2)+pow(autre.x,2));
        c.y=sqrt(pow(y,2)+pow(autre.y,2));
        c.z= (z || autre.z);
        c.color=autre.color;
        return Hasselman_Point(c);
    }
    friend Hasselman_Point plus(Hasselman_Point a, Hasselman_Point b);
    friend Hasselman_Point multiplication(Hasselman_Point a, Hasselman_Point b);
    friend Hasselman_Point operator*(const Hasselman_Point& a, const Hasselman_Point& b);

};

 
void Hasselman_Point::print(/* args */){
    std::cout<<"---------------------"<<std::endl;
    std::cout<<"Values of point are:"<<std::endl;
    std::cout<<"---------------------"<<std::endl;
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"y: "<<y<<std::endl;
    std::cout<<"z: "<<z<<std::endl;
    std::cout<<"color: "<<color<<std::endl;
    std::cout<<"---------------------"<<std::endl;

}
Hasselman_Point operator*(const Hasselman_Point& a, const Hasselman_Point& b){
    
    Hasselman_Point c;
    c.x=(a.x)*(b.x);
    c.y=(a.y)*(b.y);
    c.z= (a.z && b.z);
    c.color=b.color;

    return c;
}
Hasselman_Point plus(Hasselman_Point a, Hasselman_Point b){
   
    Hasselman_Point c;

    c.x=sqrt(pow(a.x,2)+pow(b.x,2));
    c.y=sqrt(pow(a.y,2)+pow(b.y,2));
    c.z= (a.z || b.z);
    c.color=a.color;

    return c;

    

}
Hasselman_Point multiplication(Hasselman_Point a, Hasselman_Point b){
   
    Hasselman_Point c;

    c.x=(a.x)*(b.x);
    c.y=(a.y)*(b.y);
    c.z= (a.z && b.z);
    c.color=b.color;

    return c;

    

}


int main(){

    Hasselman_Point a(2.5,4.0,1,RED);
    Hasselman_Point b(2.5,3.0,1,BLUE);
    Hasselman_Point c;
    //c=plus(a,b);
    c=a+b;
    Hasselman_Point d;
    //d=multiplication(a,b);
    d=a*b;

    
//plus(a,b,c);
    std::cout<<"addition with + (plus)"<<std::endl;
    c.print();
    std::cout<<"multiplication with * (multiplication)"<<std::endl;
    d.print();


    

   



    return 0;
}