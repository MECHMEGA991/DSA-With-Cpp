#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top ;
    char * arr;
};

int isfull(struct stack *ptr){

return ptr->top == ptr->size-1;
}

int isempty(struct stack *ptr){

return ptr->top == -1;
}

void push (struct stack *ptr , char val){

    if(isfull(ptr)){
        printf("Stack is overflow \n");
    }

    else{

        ptr->top++;
        ptr->arr[ptr->top]=val;

    }

}

char pop(struct stack *ptr)
{

    if(isempty(ptr)){
        printf("Stack is underflow\n");
        return '\0';
    }

    else{
        char val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}
char peek(struct stack *ptr){
    if(isempty(ptr)){
        return '\0';
    }

    else {
        return ptr->arr[ptr->top];
    }
}

int precedence(char ch){

    if(ch == '*' || ch == '/'){
        return 3;
    }

    else if(ch == '+' || ch =='-'){
        return 2;
    }

    else {
        return 0;
    }

}

int isoperator(char ch){
    if(ch == '+' || ch == '-' || ch =='*'  || ch =='/'){
        return 1;
    }
    else 
    return 0;
}
char * infixtopostfix(char *infix){

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char * postfix = (char *)malloc(strlen(infix)+1 * sizeof(char) );
    int i = 0; // check infix traverse
    int j = 0; // check postfix traverse

    
    while(infix[i]!= '\0'){

        if(!isoperator(infix[i])){

            postfix[j] = infix[i];
            i++;
            j++;

        }
        else if(precedence(infix[i])>precedence(peek(sp))){

            push(sp,infix[i]);
            i++;
        }
        else{
            postfix[j] = pop(sp);
            j++;

        }
    }

    while(!isempty(sp)){
        postfix[j]= pop(sp);
        j++;
    }

    postfix[j]='\0';
    return postfix;



}
int main(){

 char infix[] = "x+y *z";

 printf("Postfix is %s\n",infixtopostfix(infix));


    return 0 ; 
}