#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node * createnode(int data){

    struct node *n = (struct node * )malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

return n;
}
int main(){

// counstructing the node using function(easy and simple)

struct node *p = createnode(2);
struct node *p1 = createnode(6);
struct node *p2 = createnode(10);

p->left = p1;
p->right = p2;


    return 0;
}