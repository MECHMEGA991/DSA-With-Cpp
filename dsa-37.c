#include<stdio.h>
#include<stdlib.h>

struct node {

int data;
struct node *left;
struct node *right;

};

struct node * createnode(int data){

    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data= data;
    n->left = NULL;
    n->right =NULL;

    return n;
}

void inorder(struct node *root){

    if(root!=NULL){

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

    }


}

int isbst(struct node *root){

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

    struct node *bstsearch(struct node * root , int key){
        

        while(root!=NULL){

            if(root->data==key){
                return root;
            }
            else if(root->data < key){
                root = root->right;
            }
            else{
                root=root->left;
            }


        }
        return NULL;
    
}

void bstinsert(struct node *root , int data){
    
    struct node * prev =NULL;
    while(root!=NULL){

        prev = root;

        if(root->data == data){
            
            printf("Cant insert %d \n",root);
            return;

        }
        else if(root->data < data){
            root = root->right;
            
        }
        else{
            root=root->left;
        }
        
    
    }
    struct node * newnode = createnode(data);

    if(prev->data < data){
        prev->right = newnode ;
    }
    else{
        prev->left =newnode ;
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
    struct node *p = createnode(70);
    struct node *p1 = createnode(60);
    struct node *p2 = createnode(80);
    struct node *p3 = createnode(95);
    struct node *p4 = createnode(65);

    // Linking nodes left right

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p);
    printf("\n%d",isbst(p));

    struct node * result = bstsearch(p,70);

    if(result!=NULL){
        printf("\nFound : %d \n",result->data);
    }
    else{
        printf("\nNot found");
    }

    bstinsert(p,90);
    printf("%d \n", p->right->right->data);
    return 0;
}