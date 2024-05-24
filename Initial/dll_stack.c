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

void push(struct Node** topRef, int data) {
    struct Node* newNode = createNode(data);
    if (*topRef != NULL) {
        newNode->next = *topRef;
        (*topRef)->prev = newNode;
    }
    *topRef = newNode;
    printf("Pushed %d onto the stack\n", data);
}

int pop(struct Node** topRef) {
    if (*topRef == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *topRef;
    int poppedData = temp->data;
    *topRef = temp->next;
    if (*topRef != NULL) {
        (*topRef)->prev = NULL;
    }
    free(temp);
    printf("Popped %d from the stack\n", poppedData);
    return poppedData;
}


void printStack(struct Node* top) {
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printStack(top);

    pop(&top);
    pop(&top);

    printStack(top);

    pop(&top);

    pop(&top);

    return 0;
}
