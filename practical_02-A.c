#include <stdio.h>

int main()
{
    int arr[100], m, i;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &m);

    printf("Enter %d elements:\n", m);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = &arr[m - 1];

    printf("Array elements in reverse order are:\n");

    for(i = m - 1; i >= 0; i--)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}