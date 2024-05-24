#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void push(struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            postfix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }
    postfix[++k] = '\0';
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, operand1, operand2;
    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch(postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
                case '^':
                    push(stack, operand1 ^ operand2);
                    break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
