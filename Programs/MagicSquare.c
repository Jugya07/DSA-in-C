#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            a[i][j] = 0;
        }
    }
    int mid = n/2;
    a[0][mid] = 1;
    int count = 2;
    int i =0,j = mid;
    while(count != n*n+1){
        int t1=i , t2 = j;
        i = abs((i-1+n)%n);
        j = abs((j-1+n)%n);
        if(a[i][j] == 0){
            a[i][j] = count;
            count++;
        }else{
            i = t1;
            j = t2;
            i =(i+1)%n;
            a[i][j] = count;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}