//time complexity : O(n)
//selection sort is not stable and not adaptive

#include<stdio.h>

//selection sort
void selectionSort(int *a , int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min != i){
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}

//print array
void printArray(int * a, int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    selectionSort(a,n);
    printArray(a,n);
}