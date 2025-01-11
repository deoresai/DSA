//          heapsort
#include <stdio.h>
#include <stdlib.h>
void maxheap(int a[], int n, int i)
{
    int largest = i, temp;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxheap(a, n, largest);
    }
}
void heapsort(int a[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        maxheap(a, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxheap(a, i, 0);
    }
}
int main()
{
    int n, i;
    printf("Size of array:\n");
    scanf("%d", &n);
    int a[n];
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("original array:=\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    heapsort(a, n);
    printf("\nsorted array is:=\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
