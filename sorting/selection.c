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
void selection(int a[100], int n)
{
    int i, j, temp;
 
    for (i = 0; i < n - 1; i++)
    {
             int mini = 99999999,index=-1;
             for(int j=i;j<n;j++)
             {
                if(a[j]<mini)
                {
                    mini = a[j];
                    index =j;
                }
             }
             temp  = a[i];
             a[i]=a[index];
             a[index]=temp;
             
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
    selection(a, n);
    printf("\nsorted array is:-\n");
    display(a, n);
    getch();
}