#include<iostream>
#include<fstream>
using namespace std;


int main(){
    string str1;

    ofstream outf("hellomom.txt");
    outf<<"Hello Mom!"<<endl;

    outf.close();

    ifstream inf;
    inf.open("hellomom.txt");
    getline(inf,str1);
    cout<<"After opening again & reading into 'hellomom.txt'as input:-\n"<<str1<<endl;
    inf.close();

    
}