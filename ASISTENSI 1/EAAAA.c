#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    unsigned size;
} Stack;

void initStack(Stack* stack) {
    stack->size = 0;
    stack->top = NULL;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) 
    {
        stack->size++;
        newNode->data = value;
        if (isEmpty(stack)) 
        {
        newNode->next = NULL;
        } 
        else 
        {
            newNode->next = stack->top;
        }
        stack->top = newNode;
    }
}

void pop(Stack* stack) {
    if (!isEmpty(stack)) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
}

int top(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->top->data;
    }
    return 0;
}

unsigned size(Stack* stack) {
    return stack->size;
}

int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10005);

    long long n, sum = 0;
    scanf("%lld", &n);

    long long weight;
    while (n--) {
        scanf("%lld", &weight);
        while (weight >= top(&stack)) {
            pop(&stack);
            sum += (weight < top(&stack) ? weight : top(&stack));
        }
        push(&stack, weight);
    }
    pop(&stack);
    while (top(&stack) != 10005) {
        sum += top(&stack);
        pop(&stack);
    }
    printf("%lld\n", sum);
    return 0;
}
