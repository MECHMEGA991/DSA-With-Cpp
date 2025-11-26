#include<stdio.h>
#include<stdlib.h>

// Multiple Parantheises ( '(' , ')' , '[', ']' , '{' , '}' ) solve using stack

struct stack {

    int size;
    int top ; 
    char *arr;

};

int isfull(struct stack * ptr){

    return ptr->top == ptr->size-1;
}

int isempty(struct stack * ptr){

    return ptr->top == -1;
}

void push(struct stack *ptr,char val){

    if(isfull(ptr)){
        printf("Stack is overflow \n");
    }

    else{

        ptr->top++;
        ptr->arr[ptr->top]=val;
        
    }
}

int pop(struct stack *ptr){

    if(isempty(ptr)){
        printf("Stack is Underflow \n");
    }

    else{
        char val;
        val=ptr->arr[ptr->top];
        ptr->top--;
        return val;

    }
}

int match(char a ,char b)
{
    if(a == '(' && b ==')'){
        return 1;
    }
    if(a == '[' && b ==']'){
        return 1;
    }
    if(a == '{' && b =='}'){
        return 1;
    }

    else {
        return 0;
    }

}

int paranthesis(char *exp){

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));

    for(int i = 0 ; exp[i] != '\0';i++){

        if(exp[i]=='(' || exp[i] == '[' || exp[i] == '{' ){

            push(sp ,exp[i]);
        }
        else if(exp[i]==')' || exp[i] == ']' || exp[i] == '}' ){

            if(isempty(sp)){
                return 0;  // No opening bracket
            }

        
            
            char popped = pop(sp);
            if(!match( popped , exp[i])){
                
                return 0; // No matching pair
                
            }
        }

    }

    return isempty(sp); // stack should be empty
}
int main(){

    char arr[]="({[5+4]9}*8)";

    if(paranthesis(arr)){
        printf("Paranthesis is balanced");
    }
    
    else {
        printf("Paranthesis is not balanced");
    }



    return 0;
}