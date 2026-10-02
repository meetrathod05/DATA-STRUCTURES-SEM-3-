#include <stdio.h>

void CallByValue(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("\nInside call by value:");
    printf("\na = %d, b = %d\n", a, b);
}

void CallByReference(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printf("\nInside call by Reference:");
    printf("\na = %d, b = %d\n", *a, *b);
}

int main()
{
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("\nBefore function call:");
    printf("\nx = %d, y = %d\n", x, y);

    CallByValue(x, y);

    printf("\nAfter call by value:");
    printf("\nx = %d, y = %d\n", x, y);

    CallByReference(&x, &y);

    printf("\nAfter call by Reference:");
    printf("\nx = %d, y = %d\n", x, y);

    return 0;
}