#include <iostream>
#include<windows.h>

using namespace std;

class stack
{

private:
    int size;
    int *arr;
    int top;

public:
    stack()
    {   
        cout << "Enter the size of stack : ";
        cin >> size;
        arr = new int[size];
        top = -1;
    }

    int isfull()
    {

        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isempty()
    {

        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int val)
    {

        if (isfull())
        {
            cout << "Stack is overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {

        if (isempty())
        {
            cout << "Stack is underflow" << endl;
            return -1;
        }
        else
        {
            int val;
            val = arr[top];
            top--;
            return val;
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
            return arr[top];
        }
    }

    void display()
    {
        if (isempty())
        {
            cout << "Stack is empty " << endl;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << "Elements : " << arr[i] << endl;
        }
    }
};

int main()
{

    stack s1;

    int choice = 0;
    int val;
    cout<<"---------------- Stack Operations ----------------"<<endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
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
            cout << "Enter the element to push : ";
            cin >> val;
            s1.push(val);
            break;

        case 2:
            cout << "The Pop element : " << s1.pop() << endl;
            break;

        case 3:
            cout << "Peek Element in stack : " << s1.peek()<<endl;
            break;

        case 4:
            cout << "Displaying all the elements in a stack :" << endl;
            s1.display();
            break;

        default:
            system("cls");
            break;
        }
    }

    return 0;
}