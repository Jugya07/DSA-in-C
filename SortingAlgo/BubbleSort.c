//time-complexity :worst case  O(n^2)
//space-complexity : O(1)


#include <stdio.h>

// bubble sort function
void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    int isSorted = 0;
    for (i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

// for printing array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}