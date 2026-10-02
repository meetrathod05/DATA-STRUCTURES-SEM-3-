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
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertEnd(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}


void insertAfter(int given, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}


void deleteLast()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void deleteAfter(int given)
{
    struct Node *temp = head;
    struct Node *deleteNode;

    while (temp != NULL && temp->data != given)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Node after given node not found\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
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
    // Insert operations
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(30);
    insertEnd(40);
    insertAfter(20, 25);

    printf("Original List:\n");
    display();

 
    deleteFirst();
    printf("\nAfter deleting first node:\n");
    display();

    
    deleteLast();
    printf("\nAfter deleting last node:\n");
    display();

    
    deleteAfter(20);
    printf("\nAfter deleting node after 20:\n");
    display();

    return 0;
}