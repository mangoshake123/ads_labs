#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    char* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

char peek(struct Stack* stack) {
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

void infixToPrefix(char* infix, char* prefix) {
    int len = strlen(infix);
    // Reverse the infix expression
    for (int i = 0; i < len / 2; ++i) {
        char temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }
    // Swap '(' and ')' and reverse the precedence of operators
    for (int i = 0; i < len; ++i) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    struct Stack* stack = createStack(MAX_SIZE);
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            prefix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                prefix[++k] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(peek(stack))) {
                prefix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        prefix[++k] = pop(stack);
    }
    prefix[++k] = '\0';
    // Reverse the prefix expression to get the final result
    len = strlen(prefix);
    for (int i = 0; i < len / 2; ++i) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, operand1, operand2;
    for (i = 0; prefix[i]; ++i) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch(prefix[i]) {
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
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    printf("Result: %d\n", evaluatePrefix(prefix));
    return 0;
}
