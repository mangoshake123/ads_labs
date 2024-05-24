#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Queue Overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front = dq->front - 1;
    }

    dq->arr[dq->front] = item;
}

void insertRear(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Queue Overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear = dq->rear + 1;
    }

    dq->arr[dq->rear] = item;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from front is %d\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front = dq->front + 1;
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from rear is %d\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear = dq->rear - 1;
    }
}

void display(Deque *dq) {
    int i;

    if (isEmpty(dq)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    if (dq->front <= dq->rear) {
        for (i = dq->front; i <= dq->rear; i++)
            printf("%d ", dq->arr[i]);
    } else {
        for (i = dq->front; i < MAX; i++)
            printf("%d ", dq->arr[i]);
        for (i = 0; i <= dq->rear; i++)
            printf("%d ", dq->arr[i]);
    }

    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);
    int choice, item;

    while (1) {
        printf("\n1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input the element for insertion in front: ");
                scanf("%d", &item);
                insertFront(&dq, item);
                break;
            case 2:
                printf("Input the element for insertion in rear: ");
                scanf("%d", &item);
                insertRear(&dq, item);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
