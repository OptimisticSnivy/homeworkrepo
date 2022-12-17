#include <iostream>
using namespace std;
const int Max = 10;
class queue
{
private:
    int arr[Max];
    int front, rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    void addq(int ele);
    int delq();
    void display();
};
void queue::addq(int ele)
{
    if (rear == Max - 1)
    {
        cout << "\n Queue is full \n"
             << endl;
        return;
    }
    rear++;
    arr[rear] = ele;
    if (front == -1)
    {
        front = 0;
    }
}
int queue::delq()
{
    if (front == -1)
    {
        cout << "\n Queue is empty \n"
             << endl;
        return -1;
    }
    int value = arr[front];
    arr[front] = 0;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return value;
}
void queue::display()
{
    if (front == -1 && rear == -1)
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
            q.addq(ele);
            break;
        case 2:
            int n;
            n = q.delq();
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