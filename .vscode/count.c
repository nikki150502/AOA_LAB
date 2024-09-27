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
void bubble(int a[100], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int n, i, a[100];
    printf("enter size of array:-");
    scanf("%d", &n);
    printf("enter values of array:-");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("unsorted array is:-\n");
    display(a, n);
    bubble(a, n);
    printf("\nsorted array is:-\n");
    display(a, n);
    getch();
}