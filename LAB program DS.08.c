#include <stdio.h>

#define MAX 5

int pq[MAX];
int size = 0;

void enqueue(int value)
{
    int i;

    if (size >= MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    // Smaller value means higher priority
    for (i = size - 1; i >= 0 && pq[i] > value; i--)
    {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = value;
    size++;

    printf("%d inserted\n", value);
}

void dequeue(void)
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", pq[0]);

    for (i = 0; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display(void)
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue Elements: ");

    for (i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }

    printf("\n");
}

int main(void)
{
    enqueue(30);
    enqueue(10);
    enqueue(50);
    enqueue(20);

    display();

    dequeue();

    display();

    return 0;
}