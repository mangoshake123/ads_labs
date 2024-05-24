#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void generateFibonacci(int n) {
    struct Stack* stack = createStack(MAX_SIZE);
    int a = 0, b = 1, c;
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        push(stack, a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    printf("Fibonacci series retrieved from stack: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    generateFibonacci(n);
    return 0;
}
