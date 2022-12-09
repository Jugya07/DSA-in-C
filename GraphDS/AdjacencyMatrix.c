#include<stdio.h>
int v;
void insert(int matrix[][v],int i,int j){
    matrix[i][j]=1;
    matrix[j][i]=1;
}

int main(){
    int n,v1,v2;
    printf("Enter the size of the matrix\n");
    scanf("%d",&v);
    int matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=0;
        }
    }
    printf("Enter the no of path you want to create\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&v1,&v2);
        insert(matrix,v1,v2);
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

}