#include<stdio.h>
#include<stdlib.h>

struct node{

    int data ;
    struct node *left;
    struct node *right;

};

struct node * createnode(int data){

struct node * n = (struct node *)malloc(sizeof(struct node));

n->data = data;
n->left = NULL;
n->right = NULL;

    return n;

}

// Inorder 

void inorder(struct node *root){

    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }

}

int isbst(struct node * root){
    static struct node * prev = NULL;

    if(root!=NULL){

        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0 ;
        }

        prev = root;
        return isbst(root->right);
}
else{
    return 1;
}
}
// Binary tree if it taversak inorder is in ascending order
    /*
       7
      / \
     5   9
    / \
   3   6

*/

int main(){

struct node * p = createnode(7);
struct node * p1 = createnode(5);
struct node * p2 = createnode(9);
struct node * p3 = createnode(3);
struct node * p4 = createnode(6);

// connecting node 

p->left = p1;
p->right = p2;
p1->left = p3;
p1->right = p4;

// calling inorder

inorder(p);

// Printing true or false

printf("\n%d ",isbst(p));


    return 0;
}