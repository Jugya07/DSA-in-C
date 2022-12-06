#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int size;
    int top;
    int *a;
}Stack;

void push(Stack *p , int val){
    if(p->top == p->size-1){
        printf("Stack Overflow\n");
    }else{
        p->top++;
        p->a[p->top] = val;
    }
}

void pop(Stack *p){
    if(p->top == -1){
        printf("Stack Underflow\n");
    }else{
        p->top--;
    }
}

int top(Stack *p){
    return p->a[p->top];
}

int main(){
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->size = 10;
    p->top = -1;
    p->a = (int *)malloc(p->size*sizeof(int));

    char s[200];
    printf("Enter prefix expression: ");
    scanf("%s",s);

    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i] >= '0' && s[i] <= '9'){
            push(p,s[i]-'0');
        }else{
            int x = top(p);
            pop(p);
            int y = top(p);
            pop(p);
            switch(s[i]){
                case '+':
                    push(p,x+y);
                    break;
                case '-':
                    push(p,y-x);
                    break;
                case '*':
                    push(p,x*y);
                    break;
                case '/':
                    push(p,y/x);
                    break;
            }
        }
    }
    printf("The result : %d\n",top(p));                        
}