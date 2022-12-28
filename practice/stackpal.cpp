#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class cstack
{
private:
        int top;
		char a[max];
public:
    cstack(){
        top=-1;
    }
    void push(char c){
        top++;
        a[top]=c;
        a[top+1]='\0';
    }
    void reverse(){
        int i,j;
        char str[max];
        for(i=top,j=0;i>=0;i--,j++){
            str[j]=a[i];
        }
    }
    void convert(char str[])
    {
        int j,k,len=strlen(str);
    for(j=0,k=0;j<len;j++)
     {
        if((int)(str[j]>=97) &&(int)(str[j]<=122) || (int)(str[j]>=65) &&(int)(str[j]<=90) )
        {
            if(((int)(str[j]<=90))){
                str[k]=(int)(str[j])+32;
            }
            else{
                str[k]=str[j];
            }
            k++;
        }
     }
    str[k]=0;    
    }
};

int main(){}