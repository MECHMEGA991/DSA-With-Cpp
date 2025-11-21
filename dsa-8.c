#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("Element : %d \n", head->data);
        head = head->next;
    }
}

// Reverse of singly linked list

struct node* reverse(struct node * head)
{
    struct node * current = head;
    struct node * prev = NULL;
    struct node * next = NULL;

    while(current != NULL)
    {

        next = current->next;  // store next node
        current->next = prev;  // reverse pointer
        prev = current;        // move prev forward
        current = next;        // move current forward 


    }

    return prev;


}

// Case 1 : Deletion at beggining

struct node *deleteatbegin(struct node *head)
{

    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

// Deleting an element at given index
struct node *deleteatindex(struct node *head, int index)
{

    // if Index become 0 or at the begin
    if (index == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    struct node *p = head;
    struct node *q = head->next;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    // If q is NULL, index is invalid

    if (q == NULL)
        return head;

    p->next = q->next;
    free(q);
    return head;
}
// Deleting the last element
struct node *deleteatend(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != NULL)
    {

        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

// Deletion of an element with a given value

struct node *deleteatele(struct node *head, int value)
{

    if (head->data = value)
    {
        struct node *temp = head;

        head = head->next;
        free(temp);

        return head;
    }

    struct node *p = head;
    struct node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {

        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    // connect head to second

    head->data = 10;
    head->next = second;

    // connect first to second

    second->data = 20;
    second->next = third;

    // connect second to third

    third->data = 30;
    third->next = fourth;

    // connect third to fourth

    fourth->data = 40;
    fourth->next = fifth;

    // connect fourth to fifth

    fifth->data = 50;
    fifth->next = NULL;

    printf("Brfore Deletion Linked list : \n");
    traverse(head);

    // printf("After deletion at begin : \n");
    // head=deleteatbegin(head);
    // traverse(head);

    // printf("After deletion at an index : \n");
    // head=deleteatindex(head , 1);
    // traverse(head);

    // printf("After deletion at an end: \n");
    // head=deleteatend(head );
    // traverse(head);

    // printf("After deletion at the element after : \n");
    // head = deleteatele(head, 10);
    // traverse(head);

    printf("Reversing the singly linked list : \n");
    head = reverse(head);
    traverse(head);

    return 0;
}