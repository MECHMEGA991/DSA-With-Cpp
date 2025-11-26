#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isfull(struct stack *ptr){

    return ptr->top == ptr->size-1;
    
}
int isempty(struct stack *ptr){

    return ptr->top == -1;

}

void push(struct stack *ptr , char val){

    if(isfull(ptr)){
        printf("Stack is Overflow \n");
    }

    else{

        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}

char pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("Stack is underflow \n");
        return '\0';
        
    }

    else{
        char val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}

int paranthesismatch(char *exp){

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top=-1;
    sp->arr= (char *)malloc(sp->size * sizeof(char));

    for(int i = 0 ; exp[i]!='\0';i++){

        if(exp[i]=='('){
            push(sp,'(');
        }
        
        else if(exp[i]==')'){

            if(isempty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }

        }


    }

    return isempty(sp);


}
int main(){

    char exp[] = "8*(5+4)+(87-21)";

    // check if stack is empty

    if(paranthesismatch(exp)){
        printf("The paranthesis is matching \n");
    }
    else{
        printf("The paranthesis is not matching \n");
    }

    return 0 ; 

}