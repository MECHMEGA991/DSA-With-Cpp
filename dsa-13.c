#include<stdio.h>
#include<stdlib.h>

// Implenting stack using linked list

struct node {
    int data;
    struct node *next;
};

void traverse(struct node * ptr){

    while(ptr !=NULL){
        printf("Elements : %d\n",ptr->data);
        ptr=ptr->next;
    }

}

int isempty(struct node * top){

    return top == NULL;

}

int isfull(struct node *top){
    // Stack become full when list can't hold enough memory

    struct node * n  = (struct node *)malloc(sizeof(struct node));

    return  n==NULL;
}

struct node * push(struct node * top, int val){

   

    if(isfull(top)){
        printf("Stack is overflow \n");
    
    }

    else {
        struct node * n  = (struct node *)malloc(sizeof(struct node));
         
        n->data=val;
        n->next = top;

        top = n; // to connect to new pointer
        return top;
        
    }
}

int pop(struct node **top){

    if(isempty(*top)){
        printf("Stack is underflow \n");
        return -1;
    }

    else {
        struct node * temp = *top;
        int val;
        val=temp->data;
        *top=(*top)->next;
        free(temp);

        return val;
    }

}
int main(){

struct node * top = NULL;

top = push(top , 45);
top = push(top , 55);
traverse(top);      // ERRor

int element ;
element = pop(&top);
printf("Popped Element %d\n",element);
traverse(top);

    return 0;
}