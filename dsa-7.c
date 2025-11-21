#include<stdio.h>
#include<stdlib.h>

struct node{

int data ;
struct node * next;

};

// Printing linked list
void traverse(struct node*head){

    while(head != NULL){
        printf("Element : %d\n",head->data);
        head=head->next;
    }

}

// case 1 : Insertion after Begin

struct node * insertatbegin(struct node *head,int data){

    struct node * ptr = (struct node *) malloc(sizeof(struct node));

    ptr->data=87;
    ptr->next=head;

}

// case 2 Insertion at end 

struct node * insertatend(struct node *head , int data)
{

    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p =head;

    while(p->next!=NULL){

        p=p->next;

    }

    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

// case 3 Insertion at an index

struct node * insertatindex(struct node *head , int data , int index){

    struct node *ptr = (struct node * )malloc(sizeof(struct node));
    struct node *p =head;
    int i = 0;

    while( i != index - 1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;

}

// case 4 : Insetion after a node 

struct node *  insertafter( struct node * head , struct node *prevnode , int data){

    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;

  
    ptr->data=data;

    ptr->next=prevnode->next;
    prevnode->next=ptr;
    

    return head;


}
int main()
{

struct node * head;
struct node * second;
struct node * third;

head = (struct node*) malloc(sizeof(struct node));
second = (struct node*) malloc(sizeof(struct node));
third = (struct node*) malloc(sizeof(struct node));

// head to second

head->data=85;
head->next=second;

// second to third

second->data=44;
second->next=third;

// third to another

third->data=77;
third->next=NULL;

traverse(head);
printf("After Inserting at begin : \n");
head=insertatbegin(head,87);
traverse(head);
printf("insertion at a index : \n");
head=insertatindex(head,50, 1 );
traverse(head);
printf("Insert at end : \n");
head=insertatend(head,10);
traverse(head);
printf("Insert at after a node : \n");
head=insertafter(head, second ,100);
traverse(head);


    return 0;
}