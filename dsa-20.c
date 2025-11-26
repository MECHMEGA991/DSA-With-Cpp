#include <stdio.h>
#include <stdlib.h>

// Implenting queue using linked list

// Node structure
struct node
{

    int data;
    struct node *next;
};

// queue structure
struct queue
{
    struct node *f;
    struct node *r;
};

int isempty(struct queue *lq)
{

    return lq->f == NULL;
}

int isfull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

void enqueue(struct queue *lq, int val)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));

    n->data = val;
    n->next = NULL;
    if (isfull())
    {
        printf("Queue is Overflow\n");
    }

    if (lq->r == NULL)
    {
        lq->f = lq->r = n;
    }

    lq->r->next = n;
    lq->r = n;
}

int dequeue(struct queue *lq)
{

    if (isempty(lq))
    {
        printf("Stack is underflow\n");
    }
    struct node *temp = lq->f;
    int val = temp->data;

    lq->f = lq->f->next;

    // If queue becomes empty
    if (lq->f == NULL)
    {
        lq->r = NULL;
    }

    free(temp);
    return val;
}

void display(struct queue *lq){
    if(isempty(lq)){
        printf("Queue is empty\n");
    }

    struct node * temp = lq->f;
    while(temp != NULL ){
        printf("Elemets : %d\n",temp->data);
        temp=temp->next;
    }
    free(temp);


}
int main()
{

    struct queue *lq = (struct queue *)malloc(sizeof(struct queue));

    lq->f = lq->r = NULL;

    printf("Queue is empty %d\n", isempty(lq));
   
    enqueue(lq, 88);
    enqueue(lq, 55);

    printf("Queue is empty %d\n", isempty(lq));

    display(lq);

    dequeue(lq);
    dequeue(lq);

    printf("Queue is empty %d\n", isempty(lq));
    display(lq);
    

    

    return 0;
}