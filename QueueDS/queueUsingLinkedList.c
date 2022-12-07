#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueue(val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full");
    }
    else{
        newNode->data = val;
        newNode->next = NULL;
        if(f == NULL){
            f = newNode;
            r = newNode;
        }
        else{
            r->next = newNode;
            r = newNode;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node *temp = f;
    if(f == NULL){
        printf("Queue is empty\n");
    }
    else{
        f = f->next;
        val = temp->data;
        free(temp);
    }
    return val;
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

    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    displayQueue();
    return 0;
}