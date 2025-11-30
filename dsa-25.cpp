#include<iostream>

using namespace std;


void printarray(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int &a , int &b){
    int temp = a ;
    a = b ;
    b = temp;
}

int partition(int * arr , int low , int high){

    int pivot = arr[high] ;
    int i = low - 1;

    for(int j = low ; j < high;j++){

        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);

        }

    }

    swap(arr[i+1] , arr[high]);
    return i+1 ;


}

void quicksort(int *arr , int low , int high){

if(low<high){
int partionindex = partition(arr , low , high);

quicksort(arr , low , partionindex -1);
quicksort(arr , partionindex + 1 , high);

}
}

int main(){

    int size = 6;
    int arr[size] = {12, 54, 7, 23, 9 , 21};

    cout << "Before sorting : ";
    printarray(arr, size); // printing the array before sorting

    quicksort(arr, 0 , size -1);

    cout << "After sorting : ";
    printarray(arr, size); // printing the array after sorting


    return 0;
}