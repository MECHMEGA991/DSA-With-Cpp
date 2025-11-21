#include<stdio.h>
#include<stdlib.h>

// Circular linked list

struct node{
  
    int data;
    struct node * next;

};

// traverse circular linked list

void traverse(struct node *head)
{

    struct node *ptr=head;
do {
    printf("Element : %d \n",ptr->data);
    ptr=ptr->next;

}
while(ptr != head);

}

struct node * insertatfirst(struct node *head ,int data){

    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data=data;

    struct node *p=head->next;
    while(p->next != head){
        p=p->next;
    }
    // At this point p points to last node of the linked list
    p->next=ptr;
    ptr->next=head;

    head=ptr; //Because when you insert a new node at the beginning, the new node must become the first node
    return head;
}

int main(){

    struct node * head;
    struct node * second;
    struct node * third;

    head=(struct node *) malloc(sizeof(struct node));
    second=(struct node *) malloc(sizeof(struct node));
    third=(struct node *) malloc(sizeof(struct node));

    // connect head to second

    head->data=10;
    head->next=second;

    // connect second to third

    second->data=20;
    second->next=third;

    // connect third to head

    third->data=30;
    third->next=head;

    printf("Circular linked list : \n");
    traverse(head);

    printf("Insertion at start : \n");
    head=insertatfirst(head,100);
    traverse(head);

    return 0 ;
}