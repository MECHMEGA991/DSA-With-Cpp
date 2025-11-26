#include <iostream>
#include <windows.h>

using namespace std;

// LINEAR QUEUE

class queue // cq
{

private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    queue()
    {
        cout << "Enter the size of Queue : ";
        cin >> size;
        arr = new int[size];
        front = -1; // 0
        rear = -1;  // 0
    }

    int isfull()
    {
        return rear == size - 1; // (rear+1) % size == front ;
    }

    int isempty()
    {

        return front == rear; // same
    }

    void Enqueue(int val)
    {

        if (isfull())
        {
            cout << "Stack is overflow" << endl;
        }
        else
        {
            rear++;          // rear = (rear+1) % size ;
            arr[rear] = val; // arr[rear] = val;
        }
    }
    int dequeue()
    {

        if (isempty())
        {
            cout << "Stack is underflow" << endl;
            return -1;
        }
        else
        {
            int val;
            front++;
            val = arr[front];
            return val;

            /* For circular queue

            int val ;
            front = (front + 1) % size ;
            val = arr[front] ;
            return val;
            */
        }
    }

    int peek()
    {

        if (isempty())
        {
            cout << "Stack is empty " << endl;
            return -1;
        }
        else
        {
            return arr[front + 1]; // arr[(front) % size];
        }
    }

    void display()
    {
        if (isempty())
        {
            cout << " Queue is empty " << endl;
        }
        for (int i = front + 1; i != rear + 1; i++) // for(int i = (front+1) % size ; i!= (rear +1 ) % size ; i++)
        {
            cout << "Elements : " << arr[i] << endl; // cout<<"Elements : "<<arr[i];
        }
    }
};

int main()
{

    queue q;    // queue cq;
 
    int choice = 0;
    int val;
    cout << "---------------- Stack Operations ----------------" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;

    while (choice != 5)
    {

        cout << "Enter ur choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter the element to Enqueue : ";
            cin >> val;
            q.Enqueue(val);     //cq.enequeue(val);
            break;

        case 2:
            cout << "The Dequeue element : " << q.dequeue() << endl;   //  cq.dequeue();
            break;

        case 3:
            cout << "Peek Element in Queue : " << q.peek() << endl;    // cq.dequeue();
            break;

        case 4:
            cout << "Displaying all the elements in a Queue :" << endl;
            q.display();                                               // cq.display();
            break;

        default:
            system("cls");
            break;
        }
    }

    return 0;
}