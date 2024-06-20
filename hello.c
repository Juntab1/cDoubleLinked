#include <stdio.h>

typedef struct node {
    int val;
    // struct is needed here since node is not yet created
    struct node* next;
    struct node* prev;
} Node;