#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct dataQueue
{
    int *array;
    int front;
    int rear;
    int capacity;
    int size;
};

struct dataQueue *createQueue(int capacity)
{
    struct dataQueue *queue = (struct dataQueue *)malloc(sizeof(struct dataQueue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct dataQueue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct dataQueue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct dataQueue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Enqueued: %d\n", item);
}

void printQueue(struct dataQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nQueue elements: ");
    int count = 0;
    int index = queue->front;

    while (count < queue->size)
    {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
        count++;
    }
    printf("\n");
}

int main()
{
    int n, item;

    printf("Enter the size of queue: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid queue size! Please enter a size between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    struct dataQueue *queue = createQueue(n);

    printf("\nEnter %d integers to enqueue:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &item);
        enqueue(queue, item);
    }

    printQueue(queue);

    printf("Current queue size: %d\n", queue->size);

    return 0;
}