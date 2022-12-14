// nodes of the left subtree is lesser
// nodes of the right subtree is greater
// no duplicate nodes
// inorder traversal of bst gives an ascending sorted array
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// creation of new node
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// preorder traversal
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// postorder traversal
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// inorder traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// is the tree BST
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// searching in BST
//  best time complexity- O(logn)
//  worst- O(n)
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// insertion in BST
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *n = newNode(key);
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert. Already in BST");
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    if (prev->data > key)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}

//deletion in BST
//case1: node is leaf node
//case2: node is no leaf node
//case3: node is root
struct node *inOrderPredecessor(struct node *root){
    if(root->left != NULL){
        root = root->left;
    }else{
        return root->right;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value){
   struct node *iPre;
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    //searching
    if(value < root->data){
        root->left= deleteNode(root->left , value);
    }
    else if(value > root->data){
        root->right=  deleteNode(root->right, value);
    }else{
        //deletion
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left , iPre->data);
        root->right = deleteNode(root->right , iPre->data);
    }
    return root;
} 
 
 void levelOrder(struct node *root){
    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front!=rear){
        struct node *temp = queue[front++];
        printf("%d ", temp->data);
        if(temp->left!=NULL)
            queue[rear++] = temp->left;
        if(temp->right!=NULL)
            queue[rear++] = temp->right;
    }
}
int main()
{
    struct node *root = newNode(40);
    struct node *p1 = newNode(25);
    struct node *p2 = newNode(70);
    root->left = p1;
    root->right = p2;
    p1->left = newNode(22);
    p1->right = newNode(35);
    p2->left = newNode(60);
    p2->right = newNode(80);

    // printf("\n%d ", isBST(root));

    // insert(root, 5);
    // struct node *n = search(root, 5);
    // if (n != NULL)
    // {
    //     printf("\nFound element: %d\n", n->data);
    // }
    // else
    // {
    //     printf("\nElement Not found");
    // }
    insert(root , 65);
    insert(root , 30);
    insert(root , 10);
    insert(root , 90);
    // inorder(root);
    printf("\n");
    deleteNode(root , 70);
    levelOrder(root);

    return 0;
}