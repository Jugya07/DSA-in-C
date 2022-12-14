#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *left, *right;
    int height;
};

int max(int a , int b){
    return (a>b)?a:b;
}

int getHeight(struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct Node *n){
    if(n==NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

struct Node *insert(struct Node *node, int key){
    if(node==NULL)
        return createNode(key);
 
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if(balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

void levelOrder(struct Node *root){
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front!=rear){
        struct Node *temp = queue[front++];
        printf("%d ", temp->key);
        if(temp->left!=NULL)
            queue[rear++] = temp->left;
        if(temp->right!=NULL)
            queue[rear++] = temp->right;
    }
}

int main(){
    struct Node *root = NULL;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    levelOrder(root);
    return 0;
}