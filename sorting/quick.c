 #include <stdio.h>
#include <conio.h>

void display(int a[100], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int partition(int a[100], int left, int right)
{
    int pivot, i, j, temp;
    pivot = a[left];   
    i = left;
    j = right;

    while (i < j)
    {
        
        while (a[i] <= pivot && i < right)
        {
            i++;
        }
  
        while (a[j] > pivot)
        {
            j--;
        }
   
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
 
    temp = a[left];
    a[left] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[100], int left, int right)
{
    if (left < right)
    {
        int pi = partition(a, left, right);
        quickSort(a, left, pi - 1);  
        quickSort(a, pi + 1, right);  
    }
}

void main()
{
    int i, n, a[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the values of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Unsorted array is: \n");
    display(a, n);

    quickSort(a, 0, n - 1);

    printf("\nSorted array is: \n");
    display(a, n);

    getch();
}
