#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    int i;
    struct Node *temp;

    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    temp = *head;

    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(struct Node **head, int position)
{
    int i;
    struct Node *temp;
    struct Node *nodeToDelete;

    if (position < 0 || *head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }

    temp = *head;

    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void traverse(const struct Node *head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int search(const struct Node *head, int target)
{
    while (head != NULL) {
        if (head->data == target) {
            return 1;
        }

        head = head->next;
    }

    return 0;
}

void reverse(struct Node **head)
{
    struct Node *previous = NULL;
    struct Node *current = *head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

void sortList(struct Node *head)
{
    struct Node *current;
    struct Node *next;
    int tempData;

    for (current = head; current != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (current->data > next->data) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;
            }
        }
    }
}

int length(const struct Node *head)
{
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(void)
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    traverse(head);

    insertAtBeginning(&head, 5);
    traverse(head);

    insertAtPosition(&head, 25, 2);
    traverse(head);

    deleteFromBeginning(&head);
    traverse(head);

    deleteFromEnd(&head);
    traverse(head);

    deleteFromPosition(&head, 1);
    traverse(head);

    printf("List contains 20: %s\n",
           search(head, 20) ? "Yes" : "No");

    printf("List contains 40: %s\n",
           search(head, 40) ? "Yes" : "No");

    reverse(&head);
    traverse(head);

    insertAtEnd(&head, 15);
    insertAtEnd(&head, 5);
    traverse(head);

    sortList(head);
    traverse(head);

    printf("Length of the list: %d\n", length(head));

    freeList(&head);

    return 0;
}
OUTPUT
10 -> 20 -> 30 -> NULL
5 -> 10 -> 20 -> 30 -> NULL
5 -> 10 -> 25 -> 20 -> 30 -> NULL
10 -> 25 -> 20 -> 30 -> NULL
10 -> 25 -> 20 -> NULL
10 -> 20 -> NULL
List contains 20: Yes
List contains 40: No
20 -> 10 -> NULL
20 -> 10 -> 15 -> 5 -> NULL
5 -> 10 -> 15 -> 20 -> NULL
Length of the list: 4
