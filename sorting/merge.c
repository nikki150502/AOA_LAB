 #include <stdio.h>
#include <conio.h>

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid; 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0;  
    j = 0;  
    k = left;  
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

   
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

  
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (right + left) / 2;
 
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
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

    mergeSort(a, 0, n - 1);

    printf("\nSorted array is: \n");
    display(a, n);

    getch();
}
