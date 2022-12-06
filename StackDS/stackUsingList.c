#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *push(struct node *top, int data){
    struct node *temp = newnode(data);
    temp->next = top;
    top = temp;
    return top;
}

struct node *pop(struct node *top){
    if(top == NULL){
        printf("Stack Underflow\n");
    }else{
        struct node *temp = top;
        top = (top)->next;
        free(temp);
    }
    return top;
}

void display(struct node *top){
    if(top == NULL){
        printf("Stack is empty\n");
    }else{
        while(top != NULL){
            printf("%d", top->data);
            if(top->next != NULL){
                printf(" -> ");
            }
            top = top->next;
        }
        printf("\n");
    }
}

int peek(struct node *top , int pos){
   struct node *ptr = top;
   for(int i=0;( i<pos-1 && ptr != NULL );i++){
    ptr = ptr->next;
   } 
   if(ptr != NULL){
    return ptr->data;
   }
   return -1;
}

int stackTop(struct node *top){
    if(top == NULL){
        return -1;
    }else{
        return top->data;
    }
}

int main(){
    struct node *top= NULL ;
    // top = push(top, 10);
    // top = push(top, 20);
    // top = push(top, 30);
    // top = push(top, 40);
    // top = pop(top);n
    display(top);
    printf("The value at position 3 is %d \n", peek(top, 3));
    printf("Stack Top value is %d\n",stackTop(top));
}