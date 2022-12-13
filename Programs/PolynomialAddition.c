#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int co;
    int ex;
    struct node *next;
}Node;

Node *createNode(int co, int ex){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->co = co;
    newNode->ex = ex;
    newNode->next = NULL;
    return newNode;
}

Node *attachNode( Node *head , int co , int ex){
    Node *newNode = createNode(co,ex);
    if(head == NULL){
        head = newNode;
    }else{
        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

Node *addPolynomial(Node *head1 , Node *head2){
    Node *head3 = NULL;
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->ex == ptr2->ex){
            head3 = attachNode(head3,ptr1->co + ptr2->co,ptr1->ex);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }else if(ptr1->ex > ptr2->ex){
            head3 = attachNode(head3,ptr1->co,ptr1->ex);
            ptr1 = ptr1->next;
        }else{
            head3 = attachNode(head3,ptr2->co,ptr2->ex);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL){
        head3 = attachNode(head3,ptr1->co,ptr1->ex);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        head3 = attachNode(head3,ptr2->co,ptr2->ex);
        ptr2 = ptr2->next;
    }
    return head3;
}

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    int n1, n2, co , ex;
    printf("Enter no. of terms in first polynomial: ");
    scanf("%d",&n1);
    printf("Enter no. of terms in second polynomial: ");
    scanf("%d",&n2);

    printf("Enter the co and ex for the first polynomial: \n");
    for(int i =0;i<n1;i++){
        scanf("%d %d",&co,&ex);
        head1 = attachNode(head1,co,ex);
    }

    printf("Enter the co and ex for the second polynomial: \n");
    for(int i =0;i<n2;i++){
        scanf("%d %d",&co,&ex);
        head2 = attachNode(head2,co,ex);
    }

    head3 = addPolynomial(head1,head2);

    Node *ptr = head3;
    printf("Result is: ");
    while(ptr != NULL){
        if(ptr->next != NULL){
             printf("%dx^%d + ",ptr->co,ptr->ex);
        }else{
            printf("%dx^%d",ptr->co,ptr->ex);
        }
        ptr = ptr->next;
       
    }
    return 0;
}