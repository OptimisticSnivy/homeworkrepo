/*A1-Practical*/
/* There  are  flight  paths  between  cities.  If  there  is  a  flight  between  city  A  and  city  B  then 
there is an edge between the cities. The cost of the edge can be the time that flight take 
to  reach  city  B  from  A,  or  the  amount  of  fuel  used  for  the  journey.  Represent  this  as  a 
graph. The node can be represented by airport name or name of the city. Use adjacency 
list  representation  of  the  graph  or  use  adjacency  matrix  representation  of  the  graph. 
Check whether the graph is connected or not. Justify the storage representation used. */

#include<iostream>
using namespace std;

class adjmtx{
private:
   int m,n;
public:
   adjmtx(int a,int b){
      m=a;
      n=b;
      int **arr=new int*[m];
      for(int i=0;i<m;i++){
         arr[i]=new int[n];
      }
   }  

   void display(){
      adjmtx s(4,4);
      for(int i=0;i<s.m;i++){
         
         
      }
   }

};
int main()
{

   return 0;
}












































