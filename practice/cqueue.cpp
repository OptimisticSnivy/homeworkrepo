#include<iostream>
using namespace std;
class pizzaqueue{
    int *arr;
    int front,rear,size;

public:
    pizzaqueue(){
        size=2500;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    
    bool takeorder(int order){
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            cout<<"Not accepting Orders right now, Please wait!"<<endl;
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=order;
        }
        else{
            rear++;
        }
        cout<<"Order Accepted!"<<endl;
        arr[rear]=order;
        return true;
    }

    int serveorder(){
        if(front==-1){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }

    void display()
    {
    int i = 0;
    if (front == -1)
    {
        cout << "\nCafe is Empty.No orders.\n";
        return;
    }
    else
    {
        cout << "Order Id's:";
        for (i = front; i != rear; i = ((i + 1) % size))
        {
            cout << arr[i] << "  ";
        }
        cout << arr[rear];
    }
    }
};
int main()
{
    int ch, id = 0;
    int ordert;

    pizzaqueue q;
    do
    {
        cout<<"\n-----------------";
        cout<<"-----------------";         
        cout<<"\n****Menu*****\n";         
        cout<<"1. Accept order\n";         
        cout<<"2. Serve order\n";         
        cout<<"3. Display orders\n";         
        cout<<"4. Exit";
        cout << "\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout<<"What would you Like to Order?"<<endl;
            cin>>ordert;
            q.takeorder(ordert);
            break;
        case 2:
            q.serveorder();
            break;
        case 3:
            q.display();
            break;
        }
    } while (ch != 4);
    cout << "\nThank You.Keep Visiting.";
}
