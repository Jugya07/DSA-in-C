#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char *a;
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

void push(struct stack *s, char val){
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

char stackTop(struct stack *s){
    return s->a[s->top];
}

int isOperand(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 0;
    }else{
        return 1;
    }
}

int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else{
        return 0;
    }
}

void infix_postfix(char *str, int n){
    char pos[n+1];
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = n;
    s->top = -1;
    s->a = (char *)malloc(s->size * sizeof(char));
    int i = 0, j = 0;
    while(str[i] != '\0'){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')){
            pos[j] = str[i];
            j++;
            i++;

        }else if(str[i] == '('){
            push(s, str[i++]);
        }else if(str[i] == ')'){
            while(stackTop(s) != '('){
                pos[j] = stackTop(s);
                j++;
                pop(s);
            }
            pop(s);
            i++;
        }
        else{
            if(precedence(str[i]) > precedence(stackTop(s))){
                push(s, str[i]);
                i++;
            }else{
                pos[j] = stackTop(s);
                j++;
                pop(s);
            }
        }
    }
    while(!isEmpty(s)){
        pos[j] = stackTop(s);
        j++;
        pop(s);
    }
    pos[j] = '\0';
    printf("%s", pos);
}

int main(){
    char str[200];
    printf("Enter the infix expression: ");
    scanf("%s", str);
    int n = strlen(str);
    infix_postfix(str,n);

}