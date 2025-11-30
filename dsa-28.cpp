#include<iostream>

using namespace std;

// Merge sort 

void merge(int * arr , int low , int mid , int high){

    int i , j , k ;
    i = low;
    j= mid+1;
    // k = low;
    // int arr2[100];

    // dynamically array
    int n = high - low +1;
    int * arr2 = new int[n];
    k=0;

    while(i<=mid && j <=high){

        if(arr[i]<arr[j]){
            arr2[k]=arr[i];
            k++ , i++;
        }   
        else{
            arr2[k]=arr[j];
            k++ , j++;
        }

    }
    while(i<=mid){
        arr2[k]=arr[i];
        k++ , i++;
    }
    while(j<=high){
        arr2[k]=arr[j];
        k++ , j++;
    }

    // for(int i = low ; i <= high ; i++){
    //     arr[i] = arr2[i] ;

    // }
    for(int i = 0; i < n ; i++){
        arr[low + i] = arr2[i] ;

    }
    delete[] arr2;

}


void mergesort(int *arr , int low , int high){
    if(low < high){

       int  mid = (low + high)/2;

       mergesort(arr , low , mid);
       mergesort(arr , mid + 1 , high);

       merge(arr , low , mid , high);

    

}
}
int main(){

int arr[5]={98,74,88,65,24};

mergesort(arr , 0 , 4 );

for(int i = 0 ; i <5 ;i++ ){
    cout<<arr[i]<<" ";
}

    return 0;
}