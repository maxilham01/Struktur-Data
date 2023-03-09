#include <stdio.h>
#include <stdlib.h>

struct bt
{
    struct bt *left;
    int data ;
    struct bt *right;
};

//function prototypes
void insert(struct bt *root, struct bt *newl);
void in - order (struct bt *temp);
void preorder (struct bt *temp);
void postorder()