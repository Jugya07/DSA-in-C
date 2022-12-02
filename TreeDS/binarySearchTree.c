//nodes of the left subtree is lesser
//nodes of the right subtree is greater
//no duplicate nodes
//inorder traversal of bst gives an ascending sorted array
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

//is the tree BST
int isBST(struct node *root){
   static  struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
             return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}


int main(){
    struct node *root = newNode(10);
    struct node *p1 = newNode(4);
    struct node *p2 = newNode(15);
    root->left = p1;
    root->right = p2;
    p1->left = newNode(1);
    p1->right = newNode(6);
    p2->left = newNode(11);
    p2->right = newNode(16);
   
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n%d ",isBST(root));    
   
    return 0;
}