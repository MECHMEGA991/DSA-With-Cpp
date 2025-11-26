#include <stdio.h>
#include <stdlib.h>

// Circular Queue
// To implement circular path -> i = ( i + 1) % size . Important after the max size it reset to 0

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isfull(struct queue *cq)
{

    return (cq->rear + 1) % cq->size == cq->front;
}

int isempty(struct queue *cq)
{

    return cq->rear == cq->front;
}

void enqueue(struct queue *cq, int val)
{

    if (isfull(cq))
    {
        printf("Stack is Overflow %d\n", val);
    }
    else
    {

        cq->rear = (cq->rear + 1) % cq->size;
        cq->arr[cq->rear] = val;
    }
}

int dequeue(struct queue *cq)
{

    if (isempty(cq))
    {
        printf("Stack is Underflow\n");
        return -1;
    }
    else
    {

        cq->front = (cq->front + 1) % cq->size;
        int val = cq->arr[cq->front];
        return val;
    }
}

void display(struct queue *cq)
{

    if (isempty(cq))
    {
        printf("Queue is empty \n");
    }

    for (int i = (cq->front) % cq->size; i != (cq->rear) % cq->size; i++)
    {

        printf("Elements : %d\n", cq->arr[i]);
    }
}

int peek(struct queue *cq){

    if(isempty(cq)){
        printf("Queue is empty \n");
        return -1;
    }
    else {

        return cq->arr[(cq->front) % cq->size ];

    }
}
int main()
{

    struct queue *cq = (struct queue *)malloc(sizeof(struct queue));
    cq->size = 5;
    cq->front = 0;
    cq->rear = 0;
    cq->arr = (int *)malloc(cq->size * sizeof(int));

    printf("Queue is empty %d\n", isempty(cq));
    printf("Queue is full %d\n", isfull(cq));

    enqueue(cq, 78);
    enqueue(cq, 45);
    enqueue(cq, 25);
    enqueue(cq, 99);
    // enqueue(cq,21);
    // enqueue(cq,21);

    printf("Queue is full %d\n", isfull(cq));

    printf("Dequeue Element : %d\n", dequeue(cq));

    printf("Queue is empty %d\n", isempty(cq));
    printf("Queue is full %d\n", isfull(cq));

    printf("Peek Element : %d \n",peek(cq));

    display(cq);

    return 0;
}