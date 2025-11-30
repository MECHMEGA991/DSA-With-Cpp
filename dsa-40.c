#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// Function to get height of a node
int height(struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

// Function to get maximum of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}

// Function to create a new node
struct node *createnode(int key){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get balance factor
int balancefactor(struct node * n){
    if(n==NULL) return 0;
    return height(n->left) - height(n->right);
}

// Right rotation
struct node *rightrotate(struct node *y){
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
struct node *leftrotate(struct node *x){
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// AVL insertion
struct node *insert(struct node *node, int key){
    if(node == NULL)
        return createnode(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate keys not allowed

    node->height = 1 + max(height(node->left), height(node->right));
    int bf = balancefactor(node);

    // LL Case
    if(bf > 1 && key < node->left->key)
        return rightrotate(node);

    // RR Case
    if(bf < -1 && key > node->right->key)
        return leftrotate(node);

    // LR Case
    if(bf > 1 && key > node->left->key){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // RL Case
    if(bf < -1 && key < node->right->key){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

// Preorder traversal
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root = NULL;

    // Inserting values
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    printf("Preorder traversal of AVL tree: \n");
    preorder(root);

    return 0;
}
