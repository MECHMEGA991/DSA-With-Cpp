#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size ;
    int front ;
    int rear ; 
    int * arr;

};

int isfull(struct queue *ptr){

    return ptr->rear == ptr->size -1 ;

}

int isempty(struct queue * ptr){
    return ptr->front  == ptr->rear ;
}

void enqueue(struct queue *ptr , int val){

    if(isfull(ptr)){
        printf("Queue is Overflow cant enqueue %d\n",val);

    }
    else{

        ptr->rear++;
        ptr->arr[ptr->rear]=val;


    }

}
int dequeue(struct queue * ptr){  // Insertion in queue

   if(isempty(ptr)){
    printf("Queue is underflow\n");
    return -1;
   }

   else {
    int val ; 
    ptr->front++;
    val = ptr->arr[ptr->front];
    return val;
   }
}

int main(){

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size=5;
    q->front = -1;
    q->rear  = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));


    printf("Queue is empty %d\n",isempty(q));
    printf("Queue is full %d\n",isfull(q));

    printf("After enqueue element in queue \n");
    enqueue(q,45);
    enqueue(q,35);
    enqueue(q,25);
    enqueue(q,95);
    enqueue(q,85);
    enqueue(q,75);

    printf("Dequeue Element : %d\n",dequeue(q));
    printf("Dequeue Element : %d\n",dequeue(q));
    printf("Dequeue Element : %d\n",dequeue(q));
    printf("Dequeue Element : %d\n",dequeue(q));
    

    printf("Queue is empty %d\n",isempty(q));
    printf("Queue is full %d\n",isfull(q));

    return 0;
}