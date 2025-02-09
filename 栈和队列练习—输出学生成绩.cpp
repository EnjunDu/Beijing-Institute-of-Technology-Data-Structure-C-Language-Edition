#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int *data;
    int front;
    int rear;
    int size;
} queue;

void initQueue(queue *q, int maxSize) {
    q->data = (int *)malloc(sizeof(int) * maxSize);
    q->size = maxSize;
    q->front = q->rear = -1;
}

bool isQueueEmpty(queue *q) {
    return q->front == -1;
}

bool isQueueFull(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(queue *q, int c) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = c;
    }
}

int dequeue(queue *q) {
    if (!isQueueEmpty(q)) {
        int element = q->data[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        return element;
    }
    return '\0';
}

int main() {
    queue fw, lj, nb;

    int maxSize_fw = 100;
    int maxSize_lj = 100;
    int maxSize_nb = 100;

    initQueue(&fw, maxSize_fw);
    initQueue(&lj, maxSize_lj);
    initQueue(&nb, maxSize_nb);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a < 60) {
            enqueue(&fw, a);
        }
        if (60 <= a && a < 100) {
            enqueue(&lj, a);
        }
        if (a >= 100) {
            enqueue(&nb, a);
        }
    }

    printf("60>x:");
    while (!isQueueEmpty(&fw)) {
        int element = dequeue(&fw);
        printf("%d ", element);
    }
    printf("\n");

    printf("60<=x<100:");
    while (!isQueueEmpty(&lj)) {
        int element = dequeue(&lj);
        printf("%d ", element);
    }
    printf("\n");

    printf("x>=100:");
    while (!isQueueEmpty(&nb)) {
        int element = dequeue(&nb);
        printf("%d ", element);
    }
    printf("\n");

    return 0;
}
