/*A1-Practical*/
/* There  are  flight  paths  between  cities.  If  there  is  a  flight  between  city  A  and  city  B  then 
there is an edge between the cities. The cost of the edge can be the time that flight take 
to  reach  city  B  from  A,  or  the  amount  of  fuel  used  for  the  journey.  Represent  this  as  a 
graph. The node can be represented by airport name or name of the city. Use adjacency 
list  representation  of  the  graph  or  use  adjacency  matrix  representation  of  the  graph. 
Check whether the graph is connected or not. Justify the storage representation used. */
#include<iostream>
#define max 50
using namespace std;

class adjmtx{
private:
    int matrix[max];
    int a,b;
public:
    adjmtx(m,n){
        a=m;
        b=n;   
    }

};