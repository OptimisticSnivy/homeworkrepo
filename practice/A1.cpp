/*A1-Practical*/
/*Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number*/
#include<iostream>
#define max 10
using namespace std;


class hashTable{
private:
  int arr[max];
public:
  hashTable(){
    for(int i=0;i<max;i++){
      arr[i]=-1;
    }
  }

  int hashFunction(int entry){
    int index;
    index=entry%10;
    return index;
  }

  void push(int ent){  
    int ind,i;
    ind=hashFunction(ent);
    i=0;
    while(i<max){
      if(arr[(ind+i)%10]==-1){
        arr[(ind+i)%10]=ent;
        break;
      }
      else{
        i++;
      }
    }
  }

  void display(){
   for(int i=0;i<max;i++){  
    cout<<arr[i]<<endl;
   }             
  }
};

int main(){
  hashTable s;
  s.push(35);
  s.push(25);
  s.push(39);
  s.push(29);
  s.display();
  
  return 0;
}
