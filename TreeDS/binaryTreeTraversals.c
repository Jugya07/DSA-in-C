#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

//creation of new node
struct node *newNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//preorder traversal
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//postorder traversal
void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root ->right);
        printf("%d ", root->data);
    }
}

//inorder traversal
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root = newNode(1);
    struct node *p1 = newNode(2);
    struct node *p2 = newNode(3);
    root->left = p1;
    root->right = p2;
    p1->left = newNode(4);
    p1->right = newNode(5);
    p2->left = newNode(6);
    p2->right = newNode(7);
   
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);    
   
    return 0;
}