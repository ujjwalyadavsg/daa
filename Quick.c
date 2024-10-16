#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 1000 
int count; 
int partition(int a[MAX], int low, int high) 
{
    int i,j,pivot,temp;
    pivot=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(pivot>=a[i]&&i<=high)
        {
            i++;
            count++;
        }
        while(pivot<a[j]&&j>low)
        {
            j--;
            count++;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            a[low]=a[j];
            a[j]=pivot;
            return j;
        }
    }
}
void quicksort(int a[MAX], int low, int high) 
{ 
    int s; 
    if (low < high) 
    { 
        s = partition(a,low,high); 
        quicksort(a,low,s-1); 
        quicksort(a,s+1,high); 
    } 
}
int main() 
{ 
    int i, j, n, a[MAX], b[MAX], c[MAX], c1, c2, c3; 
    printf("Enter n: "); 
    scanf("%d", &n); 
    printf("Enter elements: "); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%d", &a[i]); 
    } 
    count = 0; 
    clock_t start,end;
    double cpu;
    start=clock();
    quicksort(a,0,n-1); 
    end=clock();
    cpu=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken:%f sec",cpu);
    printf("\nSorted elements:\n"); 
    for (i = 0; i < n; i++) 
    { 
        printf("%d\n", a[i]); 
    } 
    printf("\nNumber of counts: %d\n", count); 
    printf("\nSIZE\tASC\tDESC\tRAND\n"); 
    srand(time(NULL)); 
    for (i=16;i<550; i=i*2) 
    { 
        for (j = 0; j < i; j++) 
        { 
            a[j] = j;         
            b[j] = i - j;     
            c[j] = rand() % i; 
        } 
        count = 0; 
        quicksort(a, 0, i - 1); 
        c1 = count; 
        count = 0; 
        quicksort(b, 0, i - 1); 
        c2 = count; 
        count = 0; 
        quicksort(c, 0, i - 1); 
        c3 = count; 
        printf("\n%d\t%d\t%d\t%d", i, c1, c2, c3); 
    } 
    printf("\n");
    return 0; 
}