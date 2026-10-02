#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int choice, pos, value, key, found;
    char ch;

    printf("enter number of elements : ");
    scanf("%d", &n);

    printf("enter %d elements :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Traversal \n");
        printf("4. Search \n");
        printf("enter your choice : ");