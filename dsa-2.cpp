#include<iostream>


using namespace std;

int main(){

int arr[10]={65,87,21,47,20};
int size = 5 ;

int k , n;

cout<<"Enter the element u want to insert : ";
cin>>n;

cout<<"Enter the index u want to insert the element : ";
cin>>k;

cout<<"Before inserting elements : ";

for(int i =0; i<size;i++){
    cout<<arr[i]<<" ";
}
// shifting elements right to left

for(int i = size ; i > k ;i--){
    arr[i]=arr[i-1];
}
arr[k]=n;
size++;

// Before inserting

// after inserting element 
cout<<"\nAfter inserting element the array : ";

for(int i =0 ;i<size ;i ++){
    cout<<arr[i]<<" ";
}

    return 0;
}