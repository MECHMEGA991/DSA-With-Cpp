#include <iostream>

using namespace std;

// Linear search

int main()
{

    int arr[6] = {54, 21, 77, 98, 21, 34};
    // in case duplicate
    int store[5];

    int n;
    int flag = 0;
    cout << "Enter the element u want to search : ";
    cin >> n;

    for (int i = 0; i < 6; i++)
    {

        if (arr[i] == n)
        {

            store[flag] = i; // store the element index
            flag++;
        }
    }

    if (flag != 0)
    {
        cout << "Element found at index : ";
        for (int i = 0; i < flag; i++)
        {
            cout << store[i] << " ";
        }
    }
    else
    {
        cout << "Element not found ";
    }

    return 0;
}