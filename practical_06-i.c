#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}


void insertAfter(int given, int value)
{
    struct Node *temp, *newNode;

    temp = head;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}


void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insertBeginning(20);
    insertBeginning(10);

    insertEnd(30);
    insertEnd(40);

    insertAfter(20, 25);

    printf("Singly Linked List:\n");
    display();

    return 0;
}