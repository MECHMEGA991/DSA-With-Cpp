#include <iostream>

using namespace std;

// Bubble sort


void printarray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int *arr, int n)
{

    int i, j;
    int temp;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                // swapping

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size = 6;
    // int arr[size] = {87,24,65,10,75,9};
    int arr[size] = {9, 10, 24, 65, 75, 87};

    cout << "Before sorting : ";
    printarray(arr, size); // printing the array before sorting

    bubblesort(arr, size); // Function to sort array

    cout << "After sorting : ";
    printarray(arr, size); // printing the array after sorting

    return 0;
}