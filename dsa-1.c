#include<stdio.h>
#include<stdlib.h>
 
// Abstract data type (ADT) Implenting on array
// It is a custom data type that classified in data structure by using set values and methods 
struct custom_arr{

int total_size;
int used_siz;
int *ptr;

};

void array(struct custom_arr *a , int tsize , int usize){

// (*a).totat_size=tsize;
// (*a).used_siz=usize;
// (*a).ptr=(int* )malloc(10*sizeof(int));

a->used_siz=usize;
a->total_size=tsize;;
a->ptr=(int* )malloc(10*sizeof(int));
}

void get(struct custom_arr *a){

printf("Getting the value of array : \n" );

for(int i =0 ; i < a->used_siz ; i ++){
    int n;
    printf("Enter the element : ");
    scanf("%d",&n);
    (a->ptr)[i]=n;

}


}

void show(struct custom_arr *a){

for(int i=0; i<a->used_siz; i++){

    printf("The Elements are : %d \n", (a->ptr)[i]);
}


}

int main(){

struct custom_arr marks;

array(&marks , 10 , 2);
get(&marks);
show(&marks);

    return 0;
}