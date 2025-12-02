#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int r ; 
    int f ;
    int *arr;
};

int isempty(struct queue *q){

    return q->f==q->r;
}
int isfull(struct queue *q){

    return q->r == q->size -1;
}

void enqueue(struct queue *q ,int val){
    if(isfull(q)){
        printf("Queue is Overflow \n");

    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q ){

if(isempty(q)){
    printf("Queue is underflow \n");
    return -1;
}
else{
    int val;
    q->f++;
    val=q->arr[q->f];
    return val;
}

}

void display(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty\n");
        
    }
    else{

        for(int i = q->f+1 ; i<=q->r;i++){
            printf("Element : %d \n",q->arr[i]);
        }


    }
}
int main(){

 struct queue * q=(struct queue *)malloc(sizeof(struct queue));
q->size = 100;
q->r = q->f = -1;
q->arr = (int *)malloc( q->size * sizeof(int));

// enqueue(q , 87);
// enqueue(q , 97);
// enqueue(q , 45);
// enqueue(q , 33);
// printf("Deque Element : %d \n",dequeue(q));
// printf("Deque Element : %d \n",dequeue(q));
// display(q);

// BFS Implementation

int u; //current node
int i=1; // Where to start to visit graph

int visited[7]={0,0,0,0,0,0,0};
int a[7][7]= {

    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}

};

printf("%d ", i);

visited[i]=1;

enqueue(q,i); // Enqueue i for explorarion

while(!isempty(q)){


    int u =dequeue(q);

    for(int j = 0; j<7 ; j++){

        if(a[u][j] == 1 && visited[j]==0){
            printf("%d ",j);
            visited[j]=1;
            enqueue(q,j);
        }


    }


}


    return 0;
}
