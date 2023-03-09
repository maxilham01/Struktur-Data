#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int rev_flag = 0;

void enqueue(int x, int y) {
    for (int i = 0; i < y; i++) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->val = x;
        new_node->next = NULL;
        if (tail == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    printf("%d\n", y);
}

void dequeue(int y) {
    for (int i = 0; i < y; i++) {
        if (head == NULL) {
            printf("0\n");
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        int val = temp->val;
        free(temp);
        printf("%d\n", val);
    }
}

void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    tail = head;
    head = prev;
}

int main() {
    char input[1000];
    int index = 0;
    char c;

    // membaca seluruh input
    while ((c = getchar()) != EOF) {
        input[index++] = c;
    }

    // parsing input
    int x, y;
    int offset = 0;
    char op[4];
    while (sscanf(input + offset, "%s%n", op, &offset) == 1) {
        if (strcmp(op, "add") == 0) {
            sscanf(input + offset, "%d %d%n", &x, &y, &offset);
            enqueue(x, y);
        } else if (strcmp(op, "del") == 0) {
            sscanf(input + offset, "%d%n", &y, &offset);
            dequeue(y);
        } else {
            reverse();
            rev_flag = 1 - rev_flag;
        }
    }

    // menampilkan output
    Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }

    return 0;
}
