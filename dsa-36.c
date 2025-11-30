#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *  createnode(int data){

    struct node * n =(struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left =NULL;
    n->right =NULL;

    return n;

}
struct node * bstsearchiter(struct node * root , int key){

    while(root!=NULL){

        if(root->data == key){
            return root;
        }
        
        if(root->data < key){
            
            root = root->right;
        }
        else{
            root = root->left;
        }

    }
    return NULL;



}
int main(){

    /*

        70
       /  \ 
      60   80
     / \
    45  65


*/
    struct node * p =createnode(70);
    struct node * p1 =createnode(60);
    struct node * p2 =createnode(80);
    struct node * p3 =createnode(45);
    struct node * p4 =createnode(65);

    //connecting left right 

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right  = p4;

    struct node *result = bstsearchiter(p,5);

    if(result!=NULL){
    printf("Found : %d \n",result->data);
    }
    else{
        printf("Not found");
    }

    return 0;
}