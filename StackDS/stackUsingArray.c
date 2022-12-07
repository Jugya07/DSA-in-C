#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;   
    int *a;
};

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
} 

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *s, int val){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }else{
        s->top++;
        s->a[s->top] = val;
    }
}

void pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
    }else{
        s->top--;
    }
}

void peek(struct stack *s, int pos){
    int index = s->top - pos + 1;
    if(index < 0){
        printf("Invalid Position\n");
    }else{
        printf("The value at position %d is %d \n", pos, s->a[index]);
    }
}

void display(struct stack *s){
    printf("Elements are: ");
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->a[i]);
    }
}

int stackTop(struct stack *s){
    return s->a[s->top];
}

int stackBottom(struct stack *s){
    return s->a[0];
}

int main(){
    struct stack s;
    s.size = 8;
    s.top = -1;
    s.a = (int *)malloc(s.size * sizeof(int));
    push(&s, 10);
    push(&s, 50);
    push(&s, 20);
    push(&s, 30);
    push(&s, 10);
    push(&s, 90);
    push(&s, 90);
    push(&s, 90);
    push(&s, 90);

    // pop(&s);
    // pop(&s);
    // peek(&s,3);
    display(&s);
}