#include<iostream>
using namespace std;
class queue{
    int arr[25];
    int front;
    int rear;
    int size;
public:
    queue(){
        front=0;
        rear=0;      
    }  

    void addjob(int ele)
    {
        if(rear==size){
            cout<<"Queue is full!"<<endl;
        }
        else{
            arr[rear]=ele;
            rear++;
        }
    }
    int finishjob(){
        if(front==rear){
            cout<<"No Jobs left to be Done!"<<endl;
            return -1;
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){                            //if popped the only left element
                front=0;            
                rear=0;
            }
        return ans;
        }
    }
    void display()
    {
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty. \n";
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}


};

int main()
{
    queue q;
    int select, ele;
    do
    {
        cout << "\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "Enter data:";
            cin >> ele;
            q.addjob(ele);
            break;
        case 2:
            int n;
            n = q.finishjob();
            if (n != -1)
            {
                cout << "deleted job:" << n;
            }
            break;
        case 3:
            cout << "\n Queue contains:";
            q.display();
            break;
        case 4:
            cout << "\n Exiting Program...";
            break;
        }
    } while (select != 4);
    return 0;
}