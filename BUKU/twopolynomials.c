#include <stdio.h>
#include <stdlib.h>

struct node {
    int exp;
    float coef;
    struct node* link;
};

struct node* createNode(int exp, float coef) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Out of Memory");
        return NULL;
    }
    newNode->exp = exp;
    newNode->coef = coef;
    newNode->link = NULL;
    return newNode;
}

void insertNode(struct node** r, int exp, float coef) {
    struct node* newNode = createNode(exp, coef);
    if (*r == NULL) {
        *r = newNode;
    } else {
        (*r)->link = newNode;
        *r = newNode;
    }
}

struct node* polyAdd(struct node* head1, struct node* head2) {
    struct node *p = head1, *q = head2, *r = NULL;
    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            insertNode(&r, p->exp, p->coef);
            p = p->link;
        } else if (p->exp < q->exp) {
            insertNode(&r, q->exp, q->coef);
            q = q->link;
        } else {
            float sum = p->coef + q->coef;
            if (sum != 0) {
                insertNode(&r, p->exp, sum);
            }
            p = p->link;
            q = q->link;
        }
    }
    while (p != NULL) {
        insertNode(&r, p->exp, p->coef);
        p = p->link;
    }
    while (q != NULL) {
        insertNode(&r, q->exp, q->coef);
        q = q->link;
    }
    return r;
}

void printPolynomial(struct node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly->link != NULL) {
        printf("%.1fx^%d + ", poly->coef, poly->exp);
        poly = poly->link;
    }
    printf("%.1fx^%d\n", poly->coef, poly->exp);
}

int main() {
    struct node* head1 = createNode(3, 2);
    head1->link = createNode(2, -3);
    head1->link->link = createNode(0, 1);

    struct node* head2 = createNode(4, 2);
    head2->link = createNode(2, 4);
    head2->link->link = createNode(1, -5);

    struct node* result = polyAdd(head1, head2);

    printf("Polynomial 1: ");
    printPolynomial(head1);
    printf("Polynomial 2: ");
    printPolynomial(head2);
    printf("Result: ");
    printPolynomial(result);

    return 0;
}
