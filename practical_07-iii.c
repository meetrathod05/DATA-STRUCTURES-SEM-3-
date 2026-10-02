#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node n1, n2, n3;

    n1.data = 10;
    n2.data = 20;
    n3.data = 30;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;

    struct Node *temp = &n1;

    printf("Circular Linked List:\n");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != &n1);

    printf("(HEAD)\n");

    return 0;
}