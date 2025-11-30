#include<iostream>

using namespace std;

void merge(int *a , int *b , int *c , int m  , int n){

    int i , j , k ;
    i=j=k=0;

    while(i<m && j<n){

        if(a[i] < b[j]){
            c[k]=a[i];
            i++ , k++;
        }
        else{
            c[k]=b[j];
            k++,j++;
        }

    }
    // copying all remaining element of arr1;
    while(i<m){
        c[k]=a[i];
        k++ , i++;
    }
    // copying all remaining element of arr2;
    while(j<n){
        c[k]=b[j];
        k++ , j++;
    }


}

int main(){

int m = 3;
int n =4;
int arr[m]={25,64,78};
int arr2[n]={21,34,67,99};
int k = m+n;
int arr3[k];

merge(arr , arr2 , arr3,m , n );

for(int i = 0;i<k;i++){
    cout<<arr3[i]<<" ";
}

    return 0;
}