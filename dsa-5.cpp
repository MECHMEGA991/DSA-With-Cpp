#include<iostream>

using namespace std;

// Binary search 
int main(){

int arr[5]={21,45,65,87,98}; // array have to be sorted for binary search
int n , high , low , mid;
low = 0;
high = 4;

while(low<=high){

mid = (low + high)/2;

if(arr[mid] == n){
cout<<"Element found at "<<mid<<endl;
break;
}

else if(n>arr[mid])
{
low = mid +1;
}

else if(n<arr[mid])
{
high= mid - 1;
}
else {
    cout<<"Element not found ";
}

}



    return 0;
}