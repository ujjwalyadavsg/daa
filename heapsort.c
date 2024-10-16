#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;
        count++;

    if (right < n && arr[right] > arr[largest])
        largest = right;
        count++;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // clock_t start, end;
    // double time_used;

    // start = clock(); // Record start time

    heapSort(arr, n);

    // end = clock(); // Record end time

    // time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, n);

//     printf("Time taken to sort the array: %f seconds\n", time_used);




//     int i, j, c1, c2, c3; 
//     printf("\nSIZE\tASC\tDESC\tRAND\n"); 
// for (i=16;i<550; i=i*2) 
//     { 
//         count = 0; 
//         int len=i,a[1000];;
//         for(j=1;j<=i;j++)
//         {
//             a[j]=j;
//         }
//         heapSort(a,i); 
//         c1 = count; 
//         count=0;
//         len=i;
//         for(j=1;j<=i;j++)
//         {
//             a[j]=i-j;
//         }
//         heapSort(a,i); 
//         c2 = count; 
//         count=0;
//         len=i;
//         for(j=1;j<=i;j++)
//         {
//             a[j]=rand()%i;
//         }
//         heapSort(a,i); 
//         c3 = count; 
//         printf("\n%d\t%d\t%d\t%d", i, c1, c2, c3); 
//     } 
    printf("\n");
    return 0;
}