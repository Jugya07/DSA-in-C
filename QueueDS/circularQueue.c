#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f;
    int b;
    int *arr;
};   

void enqueue(struct Queue *q, int val){
    if((q->b+1)% q->size == q->f){
        printf("Queue is full!!\n");
    }else{
        q->b = (q->b+1)%q->size;
        q->arr[q->b] = val;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(q->f == q->b){
        printf("Queue is empty!!\n");
    }else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct Queue q;
    q.size = 4;
    q.f = q.b = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
    enqueue(&q, 30);
    enqueue(&q, 30);
    return 0;
}