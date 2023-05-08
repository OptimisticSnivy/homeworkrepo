/*Practical C14*/
/*There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take to
reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The
node can be represented by airport name or name of the city. Use adjacency list representation
of the graph or use adjacency matrix representation of Check whether the graph is connected
or not. Justify the storage representation used.the graph.*/

#include<iostream>
using namespace std;

class adjMatrix{
private:
  int m,n;
  int* arr=new int[m*n];
public:
  adjMatrix(int a,int b){
    m=a;
    n=b;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        *(arr+i*n+j)=0;
      }
    } 
  }
  void display(){
    for (int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout<<*(arr+i*n+j)<<"";
      }
      cout<<endl;
    }
  }
};

int main(int argc, char *argv[])
{
  adjMatrix flights(5,5);
  flights.display();
  return 0;
}
