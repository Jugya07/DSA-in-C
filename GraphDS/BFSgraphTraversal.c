#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full");
        return;
    }
    q->r++;
    q->arr[q->r] = val;
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    q->f++;
    a = q->arr[q->f];
    return a;
}

int main()
{
    struct queue q;
    q.size = 500;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // graph representation and BST implementation
    int u;
    int i = 6; //source node
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    
    //adjacency matirx representation
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // enqueue i for exploration
    while (!isEmpty(&q))
    {
        u = dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[u][j]==1 && visited[j]==0){
                 printf("%d ", j);
                 visited[j]=1;
                 enqueue(&q,j);
            }
        }   
    }

    return 0;
}