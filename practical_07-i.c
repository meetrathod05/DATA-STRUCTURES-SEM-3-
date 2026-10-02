#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void insertBeginning(int value)
{
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}


void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}


void insertAfter(int given, int value)
{
    struct Node *temp, *newNode;

    temp = head;

    do
    {
        if (temp->data == given)
        {
            newNode = malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            return;
        }

        temp = temp->next;

    } while (temp != head);
}

void display()
{
    struct Node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != head);

    printf("(HEAD)\n");
}

int main()
{
    insertBeginning(20);
    insertBeginning(10);

    insertEnd(30);
    insertEnd(40);

    insertAfter(20, 25);

    printf("Circular Linked List:\n");
    display();

    return 0;
}