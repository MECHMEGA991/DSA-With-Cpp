#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right =NULL;

    return n;
}

int isbst(struct node * root){

    static struct node * prev = NULL;

    if(root!=NULL){

        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        
        prev = root;
        return isbst(root->right);

    }

    else{
    return 1;
    }
}

// search of data in bst

struct node * bstsearch(struct node * root , int key){



        if(root ==NULL){

            return NULL;

        }
        if(root->data == key){

            return root;

        }

        if(root->data > key){

           return bstsearch(root->left ,key );

        }
        else{
           return  bstsearch(root->right, key);
        }


    

}
int main(){

/*

        70
       /  \ 
      60   80
     / \
    45  65


*/

    struct node * p = createnode(70);
    struct node * p1 = createnode(60);
    struct node * p2 = createnode(80);
    struct node * p3 = createnode(45);
    struct node * p4 = createnode(65);

    // connecting nodes 
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right =p4;

    printf("%d \n",isbst(p) );

    struct node * result = bstsearch(p,80);
    printf("Found : %d \n",result->data);


    return 0;
}