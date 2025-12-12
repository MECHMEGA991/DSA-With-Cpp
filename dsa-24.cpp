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

void selectionsort(int *arr , int n){

    for(int i = 0 ; i < n-1;i++){

        int minindex = i ;
        

        for(int j = i+1 ; j<n ;j++){

            if(arr[j] < arr[minindex]){
                minindex = j;
            }

        }

        if(minindex!=i){
        int temp;
        temp = arr[i];
        arr[i]= arr[minindex];
        arr[minindex] = temp;
        }
    }


}
int main(){

    int size = 6;
    int arr[size] = {12, 54, 7, 23, 9 , 21};

    cout << "Before sorting : ";
    printarray(arr, size); // printing the array before sorting
    selectionsort(arr, size);

    cout << "After sorting : ";
    printarray(arr, size); // printing the array after sorting

;

    return 0;
}