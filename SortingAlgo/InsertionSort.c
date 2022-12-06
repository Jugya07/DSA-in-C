//time complexity - worst case O(n^2) &  best case O(n)


#include<stdio.h>

//insertion sort
void insertionSort(int *a,int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

//display array
void display(int *a,int n){
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
    insertionSort(a, n);
    display(a, n);
}