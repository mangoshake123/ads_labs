#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void add(struct Node** frontRef, struct Node** rearRef, int data) {
    struct Node* newNode = createNode(data);
    if (*rearRef == NULL) {
        *frontRef = *rearRef = newNode;
    } else {
        (*rearRef)->next = newNode;
        newNode->prev = *rearRef;
        *rearRef = newNode;
    }
    printf("Added %d to the queue\n", data);
}

int delete(struct Node** frontRef, struct Node** rearRef) {
    if (*frontRef == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = *frontRef;
    int deletedData = temp->data;
    *frontRef = (*frontRef)->next;
    if (*frontRef != NULL) {
        (*frontRef)->prev = NULL;
    } else {
        *rearRef = NULL;
    }
    free(temp);
    printf("Deleted %d from the queue\n", deletedData);
    return deletedData;
}

void printQueue(struct Node* front) {
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    add(&front, &rear, 10);
    add(&front, &rear, 20);
    add(&front, &rear, 30);

    printQueue(front);

    delete(&front, &rear);
    delete(&front, &rear);

    printQueue(front);

    delete(&front, &rear);
    
    delete(&front, &rear);

    return 0;
}
