#include<iostream>

using namespace std;

// Deleteion in an array

int main(){

int arr[10]={98, 54 , 21 ,44,97};
int size =5;

int  k;


cout<<"Enter the index u want to delete : ";
cin>>k;

cout<<"Before delete elements : ";

for(int i =0; i<size;i++){
    cout<<arr[i]<<" ";
}

for(int i = k; i < size-1; i++){  // size - 1 used to prevent going out array bound 
    
arr[i] = arr[i+1];

}
size--;

cout<<endl;

cout<<"After deleting elements : ";

for(int i =0; i<size;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}