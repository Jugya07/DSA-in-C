//insertion from rear + front
//deletion from front + rear

//two types of DEqueue
//1. Restricted Input dequeue->insertion from front is not allowed
//2. Restricted Output dequeue->deletion from rear is not allowed 

//using Linked List
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueueRear(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is full !!");
    }else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }else{
            r->next =n;
            r = n;
        }
    }
}

void enqueueFront(int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is full !!");
    }else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }else{
            n->next = f;
            f = n;
        }
    }
}

void dequeueFront(){
    int val = -1;
    struct Node *temp = f;
    if(f == NULL){
        printf("Queue is empty !!");
        return;
    }else{
        f = f->next;
        val = temp->data;
        free(temp);
    }
    printf("%d is dequeued \n",val);
}

void dequeueRear(){
    int val = -1;
    struct Node *temp = f;
    if(f == NULL){
        printf("Queue is empty !!");
        return;
    }else{
        if(f==r){
            val = f->data;
            free(r);
            f = r = NULL;
        }else{
            while(temp->next != r){
            temp = temp->next;
           }
            val = r->data;
            free(r);
            r = temp;
           r->next = NULL;
        }
     }
    printf("%d is dequeued \n",val);
}

void displayQueue(){
    struct Node *temp = f;
    if(temp ==NULL){
        printf("Queue is empty !!");
    }else{
        printf("Elements of queue: ");
        while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        }
    }
}

int main(){
    enqueueFront(20);
    enqueueFront(30);
    enqueueFront(80);
    enqueueFront(45);
    enqueueRear(50);
    enqueueRear(23);
    enqueueRear(90);
    dequeueFront();
    dequeueRear();
    dequeueRear();
    dequeueRear();
    dequeueRear();
    dequeueRear();
    dequeueRear();
    displayQueue();
    return 0;
}