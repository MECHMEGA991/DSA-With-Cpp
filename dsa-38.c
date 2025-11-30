#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void inorder(struct node * root ){

    if(root!=NULL){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

    }


}
/*
Case 1: Node is a Leaf (No children)

Simply remove the node from the tree.

Example:

    50
   /  \
  30   70
       /
      60


Delete 60 → it’s a leaf → just remove it.

Case 2: Node has One Child

Remove the node and replace it with its only child.

Example:

    50
   /  \
  30   70
       /
      60


Delete 70 → 70 has only one child (60) → replace 70 with 60.

    50
   /  \
  30   60

Case 3: Node has Two Children

Find inorder successor (smallest node in right subtree) or inorder predecessor (largest node in left subtree).

Replace the node’s value with successor/predecessor.

Delete the successor/predecessor (which will fall in Case 1 or 2).

Example:

    50
   /  \
  30   70
       / \
      60  80


Delete 70 → 70 has two children → inorder successor = 80 (smallest in right subtree)

Replace 70 with 80 → then delete original 80 node.

    50
   /  \
  30   80
       /
      60

*/

struct node *findmin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deletenode(struct node *root, int key)
{

    if (root == NULL)
    {
        return root;
    }
    if (root->data < key)
    {
        root->right = deletenode(root->right, key);
    }
    else if(root->data > key)
    {
        root->left = deletenode(root->left, key);
    }
    else
    {
        // Having no child
        if(root->right == NULL && root->left == NULL){

            free(root);
            return NULL;
        }

        else if(root->left == NULL){
            struct node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node * temp = root->left ;
            free(root);
            return temp;
        }

        // Case 3: Having two children

        struct node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right , temp->data);
    }

    return root ;

}
int main()
{

    struct node *p = createnode(50);
    struct node *p1 = createnode(30);
    struct node *p2 = createnode(70);
    struct node *p3 = createnode(60);
    struct node *p4 = createnode(80);

    // Linking nodes left right

    p->left = p1;
    p->right = p2;
    p2->left = p3;
    p2->right = p4;

    inorder(p);
    p=deletenode(p,60);
    printf("\n");
    inorder(p);
    return 0;
}