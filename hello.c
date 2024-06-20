#include <stdio.h>

// write functions to insert, find, and delete itesm from it
// look at dynamic memory again

typedef struct node {
    // using char* makes it dynamically allocated to the heap
    char* str;
    // struct is needed here since node is not yet created
    struct node* next;
    struct node* prev;
} Node;