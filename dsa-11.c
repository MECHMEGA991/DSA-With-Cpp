#include<stdio.h>
#include<stdlib.h>

// Stack using pointer 

struct stack {

int size ;
int top ; 
int *arr;

};


isfull(struct stack * ptr){

    return ptr->top == ptr->size-1;
}

isempty(struct stack * ptr){

    return ptr->top == -1;
}

void push(struct stack *ptr , int val)
{

    if(isfull(ptr)){
        printf("Stack is overflow %d\n",val);
    }

    else {

        ptr->top++;
        ptr->arr[ptr->top]=val;
        
    }

}

int pop(struct stack * ptr ){
    if(isempty(ptr)){
        printf("Stack is underflow \n");
        return -1;
    }

    else {
        int val;
        val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr ){

    if(isempty(ptr)){
        printf("Stack is empty \n");
        return -1;
    }

    else {
       
        return ptr->arr[ptr->top];
    }

}
int main(){

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=5;
    sp->top=-1;
    sp->arr = (int *)malloc(sp->size * sizeof(int ));

    printf("Before pushing element stack is , Full %d\n",isfull(sp));
    printf("Before pushing element stack is , Empty %d\n",isempty(sp));

    push(sp,78);
    push(sp,68);
    push(sp,48);
    push(sp,98);
    push(sp,38);
    // push(sp,28); for checking overflow condition 

    printf("Peek Element : %d\n",peek(sp));

    printf("After pushing element stack is , Full %d\n",isfull(sp));
    printf("After pushing element stack is , Empty %d\n",isempty(sp));

    printf("Poping ELement : %d\n",pop(sp));
    printf("Poping ELement : %d\n",pop(sp));
    printf("Poping ELement : %d\n",pop(sp));
    printf("Poping ELement : %d\n",pop(sp));
    printf("Poping ELement : %d\n",pop(sp));
    
    // printf("Peek Element : %d\n",peek(sp));



    // Underflow condition 
    // printf("Poping ELement : %d\n",pop(sp));  


    printf("After Popping element stack is , Full %d\n",isfull(sp));
    printf("After popping element stack is , Empty %d\n",isempty(sp));
    


    return 0;
}