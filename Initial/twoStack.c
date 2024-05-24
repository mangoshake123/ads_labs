#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent two stacks
struct TwoStacks {
    int top1; // Top index of the first stack
    int top2; // Top index of the second stack
    int array[MAX_SIZE]; // Array to store elements of both stacks
};

// Function to create a new two stacks structure
struct TwoStacks* createTwoStacks() {
    struct TwoStacks* stacks = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    stacks->top1 = -1; // Initialize top index of the first stack
    stacks->top2 = MAX_SIZE; // Initialize top index of the second stack
    return stacks;
}

// Function to check if the first stack is full
int isStack1Full(struct TwoStacks* stacks) {
    return stacks->top1 == stacks->top2 - 1;
}

// Function to check if the second stack is full
int isStack2Full(struct TwoStacks* stacks) {
    return stacks->top2 == stacks->top1 + 1;
}

// Function to check if the first stack is empty
int isStack1Empty(struct TwoStacks* stacks) {
    return stacks->top1 == -1;
}

// Function to check if the second stack is empty
int isStack2Empty(struct TwoStacks* stacks) {
    return stacks->top2 == MAX_SIZE;
}

// Function to push an element onto the first stack
void push1(struct TwoStacks* stacks, int data) {
    if (isStack1Full(stacks)) {
        printf("Stack 1 overflow\n");
        return;
    }
    stacks->array[++stacks->top1] = data;
}

// Function to push an element onto the second stack
void push2(struct TwoStacks* stacks, int data) {
    if (isStack2Full(stacks)) {
        printf("Stack 2 overflow\n");
        return;
    }
    stacks->array[--stacks->top2] = data;
}

// Function to pop an element from the first stack
int pop1(struct TwoStacks* stacks) {
    if (isStack1Empty(stacks)) {
        printf("Stack 1 underflow\n");
        return -1;
    }
    return stacks->array[stacks->top1--];
}

// Function to pop an element from the second stack
int pop2(struct TwoStacks* stacks) {
    if (isStack2Empty(stacks)) {
        printf("Stack 2 underflow\n");
        return -1;
    }
    return stacks->array[stacks->top2++];
}

// Function to display the elements of the first stack
void displayStack1(struct TwoStacks* stacks) {
    if (isStack1Empty(stacks)) {
        printf("Stack 1 is empty\n");
        return;
    }
    printf("Stack 1: ");
    for (int i = stacks->top1; i >= 0; i--) {
        printf("%d ", stacks->array[i]);
    }
    printf("\n");
}

// Function to display the elements of the second stack
void displayStack2(struct TwoStacks* stacks) {
    if (isStack2Empty(stacks)) {
        printf("Stack 2 is empty\n");
        return;
    }
    printf("Stack 2: ");
    for (int i = stacks->top2; i < MAX_SIZE; i++) {
        printf("%d ", stacks->array[i]);
    }
    printf("\n");
}

// Function to display both stacks
void displayBothStacks(struct TwoStacks* stacks) {
    displayStack1(stacks);
    displayStack2(stacks);
}

int main() {
    struct TwoStacks* stacks = createTwoStacks();

    // Push elements onto the first stack
    push1(stacks, 10);
    push1(stacks, 20);
    push1(stacks, 30);

    // Push elements onto the second stack
    push2(stacks, 40);
    push2(stacks, 50);
    push2(stacks, 60);

    // Display both stacks
    displayBothStacks(stacks);

    // Pop elements from both stacks
    pop1(stacks);
    pop2(stacks);

    // Display both stacks again
    displayBothStacks(stacks);

    return 0;
}
