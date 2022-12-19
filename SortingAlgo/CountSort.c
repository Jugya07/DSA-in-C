#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int maxElement(int arr[] , int n){
    int max = INT_MIN;
    for(int i = 0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr , int n){
    int max = maxElement(arr , n);
    int *count = (int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<max+1;i++){
        count[i] = 0;
    }
    for(int i =0;i<n;i++){
        count[arr[i]]++;
    }
    int k=0;
    for(int i =0;i<max+1;i++){  
        while(count[i]!=0){
            arr[k]=i;
            k++;
            count[i]--;
        }
    }
}
void printArray(int arr[] , int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]= {1,2,6,2,7,9,5};
    int n = 7;
    printArray(arr,n);
    countSort(arr , n);
    printArray(arr,n);
    return 0;
}