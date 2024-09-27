 #include<stdio.h>
#include<conio.h>

void display(int a[100], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void insertion(int a[100], int n)
{
    int i, temp, j;
    
    for(i = 1; i < n; i++)
    {
        temp = a[i];  
        j = i - 1;  
        
        
        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;  
        
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
    
    insertion(a, n);
    
    printf("\nSorted array is: \n");
    display(a, n);
    
    getch(); 
}
