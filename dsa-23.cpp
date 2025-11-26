#include <iostream>

using namespace std;

void printarray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionsort(int *arr, int n)
{

for(int i = 1 ; i < n ; i++ ){

    int key , j;
    key = arr[i];
    j=i-1;

    while(j>=0 && arr[j] > key){
        arr[j+1]=arr[j];   // shift greater element
        j--;
    }

    arr[j+1]=key;      // insert key at correct position

}

}

int main()
{
    int size = 6;
    int arr[size] = {12, 54, 7, 23, 9 , 21};

    cout << "Before sorting : ";
    printarray(arr, size); // printing the array before sorting

    insertionsort(arr, size);

    cout << "After sorting : ";
    printarray(arr, size); // printing the array after sorting

    return 0;
}