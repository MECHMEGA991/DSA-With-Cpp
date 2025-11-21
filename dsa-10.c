#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *prev;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("Elements : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * reverse(struct node *head)
{

    struct node *current = head;
    struct node *temp = NULL;

    while (current != NULL)
    {
        // Swapping

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // move to next node (which is actually previous node now)

        current = current->prev;

    }
        // After the loop, temp points to the new head's previous
        if (temp != NULL)
        head = temp->prev;

        
        return head;
    
}

int main()
{

    struct node *head;
    struct node *n1;
    struct node *n2;

    head = (struct node *)malloc(sizeof(struct node));
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));

    // connect head to n1

    head->prev = NULL;
    head->data = 10;
    head->next = n1;

    // connect head to n2

    n1->prev = head;
    n1->data = 20;
    n1->next = n2;

    // connect head to null

    n2->prev = n1;
    n2->data = 30;
    n2->next = NULL;

    printf("Printing doubly linked list : \n");
    traverse(head);

    printf("Printing reverse of doubly linked list : \n");
    head=reverse(head);
    traverse(head);

    return 0;
}