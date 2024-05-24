#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front1, rear1;
    int front2, rear2;
} TwoQueues;

void initialize(TwoQueues *queues) {
    queues->front1 = -1;
    queues->rear1 = -1;
    queues->front2 = MAX;
    queues->rear2 = MAX;
}

int isFull1(TwoQueues *queues) {
    return (queues->rear1 + 1 == queues->front2);
}

int isFull2(TwoQueues *queues) {
    return (queues->rear2 - 1 == queues->rear1);
}

int isEmpty1(TwoQueues *queues) {
    return (queues->front1 == -1);
}

int isEmpty2(TwoQueues *queues) {
    return (queues->front2 == MAX);
}

void Addq1(TwoQueues *queues, int item) {
    if (isFull1(queues)) {
        printf("Queue 1 Overflow\n");
        return;
    }

    if (queues->front1 == -1) {
        queues->front1 = 0;
    }
    queues->rear1++;
    queues->arr[queues->rear1] = item;
}

void Addq2(TwoQueues *queues, int item) {
    if (isFull2(queues)) {
        printf("Queue 2 Overflow\n");
        return;
    }

    if (queues->front2 == MAX) {
        queues->front2 = MAX - 1;
    }
    queues->rear2--;
    queues->arr[queues->rear2] = item;
}

void Delq1(TwoQueues *queues) {
    if (isEmpty1(queues)) {
        printf("Queue 1 Underflow\n");
        return;
    }

    printf("Element deleted from Queue 1 is %d\n", queues->arr[queues->front1]);
    if (queues->front1 == queues->rear1) {
        queues->front1 = -1;
        queues->rear1 = -1;
    } else {
        queues->front1++;
    }
}

void Delq2(TwoQueues *queues) {
    if (isEmpty2(queues)) {
        printf("Queue 2 Underflow\n");
        return;
    }

    printf("Element deleted from Queue 2 is %d\n", queues->arr[queues->front2]);
    if (queues->front2 == queues->rear2) {
        queues->front2 = MAX;
        queues->rear2 = MAX;
    } else {
        queues->front2--;
    }
}

void displayQueue1(TwoQueues *queues) {
    if (isEmpty1(queues)) {
        printf("Queue 1 is empty\n");
        return;
    }

    printf("Queue 1 elements are:\n");
    for (int i = queues->front1; i <= queues->rear1; i++) {
        printf("%d ", queues->arr[i]);
    }
    printf("\n");
}

void displayQueue2(TwoQueues *queues) {
    if (isEmpty2(queues)) {
        printf("Queue 2 is empty\n");
        return;
    }

    printf("Queue 2 elements are:\n");
    for (int i = queues->front2; i >= queues->rear2; i--) {
        printf("%d ", queues->arr[i]);
    }
    printf("\n");
}

int main() {
    TwoQueues queues;
    initialize(&queues);
    int choice, item, queueNumber;

    while (1) {
        printf("\n1. Addq\n");
        printf("2. Delq\n");
        printf("3. Display Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                printf("Input the element to add: ");
                scanf("%d", &item);
                if (queueNumber == 1) {
                    Addq1(&queues, item);
                } else if (queueNumber == 2) {
                    Addq2(&queues, item);
                } else {
                    printf("Invalid queue number\n");
                }
                break;
            case 2:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                if (queueNumber == 1) {
                    Delq1(&queues);
                } else if (queueNumber == 2) {
                    Delq2(&queues);
                } else {
                    printf("Invalid queue number\n");
                }
                break;
            case 3:
                printf("Enter queue number (1 or 2): ");
                scanf("%d", &queueNumber);
                if (queueNumber == 1) {
                    displayQueue1(&queues);
                } else if (queueNumber == 2) {
                    displayQueue2(&queues);
                } else {
                    printf("Invalid queue number\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
