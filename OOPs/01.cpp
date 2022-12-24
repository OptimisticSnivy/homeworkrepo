#include<iostream>
using namespace std;

class complex{
private:
    int real;
    int img;
public:
    complex(){                                              //default constructor
        real=0;                             
        img=0;
        
    }
    
    complex(int r,int i){                                   //PARAMETRIZED constructor
        real=r;
        img=i;
    }

    complex operator + (complex a){                 
        complex result;
        result.real=real+a.real;
        result.img=img+a.img;
        return result;
    }

    complex operator * (complex a){
        complex result;
        result.real=real*a.real;
        result.img=img*a.img;
        return result;
    }

    friend ostream & operator<<(ostream &out,complex c){
        out<<c.real;
        out<<"+"<<c.img<<"i"<<endl;
        return out;
    }


    friend istream & operator>>(istream &in,complex c){
        in>>c.real;
        in>>c.img;
        return in;
    }

    void cprint(){ cout<<real<<"+"<<img<<"i"<<endl;}


};

int main(){

    complex c2(1,1);
    complex c1(1,0);
    complex c3=c1+c2;
    c3.cprint();
}