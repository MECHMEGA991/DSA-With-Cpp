#include<stdio.h>
#include<stdlib.h>


// Linked list traversal and implement 

struct node{

    int data;
    struct node *next;

};
int main()
{
    struct node *ptr;
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;

    // Allocate memory for node in heap

    head = (struct node *) malloc(sizeof(struct node) );
    first =(struct node* ) malloc(sizeof(struct node));
    second =(struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));


    // inserting value of head and pointing to first node

    head->data=7;
    head->next=first;

    // link first and second

    first->data=85;
    first->next=second;

    // link second and third

    second->data=66;
    second->next=third;

    // link third and fourth

    third->data=77;
    third->next=NULL;

    ptr=head; // initialize ptr to head as start 
    while(ptr!=NULL){

        printf("Element = %d \n",ptr->data);
        ptr=ptr->next;

    }


return 0;
}