#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


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


void deleteFirst()
{
    struct Node *temp, *del;

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    del = head;
    head = head->next;
    temp->next = head;

    free(del);
}


void deleteLast()
{
    struct Node *temp, *del;

    temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    del = temp->next;
    temp->next = head;

    free(del);
}


void deleteAfter(int given)
{
    struct Node *temp, *del;

    temp = head;

    do
    {
        if (temp->data == given)
        {
            del = temp->next;
            temp->next = del->next;

            free(del);
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
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Original List:\n");
    display();

    deleteFirst();

    printf("After deleting first node:\n");
    display();

    deleteLast();

    printf("After deleting last node:\n");
    display();

    deleteAfter(20);

    printf("After deleting node after 20:\n");
    display();

    return 0;
}