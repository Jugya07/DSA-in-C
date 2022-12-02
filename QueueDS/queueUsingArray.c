
    //Queue using array
    //enqueue 0(1) increment b (initially -1) and insert at b
    //dequeue 0(1) increment f (first element at f+1)
    //b==f queue empty condition 
    //b== size-1 queue full condition

#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->b==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow!!\n");
    }else{
        q->b =  q->b + 1;
        q->arr[q->b] = val; 
    }
}
void dequeue(struct Queue *q){
    if(q->f == q->b){
        printf("Queue Empty!!\n");
        return;
    }else{
        q->f = q->f +1;
    }
}

int main (){
    struct Queue q;
    q.size = 10;
    q.f = q.b = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    
    for(int i =q.f+1;i<=q.b;i++){
        printf("%d ",q.arr[i]);
    }


}
