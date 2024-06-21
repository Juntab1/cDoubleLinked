#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// write functions to insert, find, and delete itesm from it
// look at dynamic memory again

typedef struct node {
    // using char* makes it dynamically allocated to the heap
    char* str;
    // struct is needed here since node is not yet created
    struct node* next;
    struct node* prev;
} Node;

struct node* head = NULL;
struct node* tail = NULL;

struct node* create_node(char* word){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // malloc error check
    if (new_node == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    // make sure to always copy a string to allocate because
    // if the original string was deleted then we would get
    // invalid memory
    new_node->str = strdup(word);
    if (new_node->str == NULL){
        printf("Memory allocation for string failed\n");
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert(char* word){
    Node* curr = create_node(word);
    // Allocation failed
    if (curr == NULL){
        return;
    }

    if (head == NULL){
        head = curr;
        tail = curr;
    }
    else{
        curr->next = head;
        head = curr;
        curr->prev = head;
    }
}

bool find(char* currWord){
    Node* point = head;
    while (point != NULL){
        if (strcmp(point->str, currWord)){
            return true;
        }
        point = point->next;
    }
    return false;
}

bool delete(char* currWord){
    Node* point = head;
    while (point != NULL){
        if (strcmp(point->str, currWord)){
            if (point->prev != NULL){
                point->prev->next = point->next;
            }
            else{
                head = point->next;
            }
            if (point->next != NULL){
                point->next->prev = point->prev;
            }
            else{
                tail = point->prev;
            }
            free(point->str);
            free(point);
            return true;
        }
        point = point->next;
    }
    return false;
}

int main() {
    insert("Hello");
    insert("World");
    
    if (find("Hello")) {
        printf("Found 'Hello'\n");
    } else {
        printf("'Hello' not found\n");
    }
    
    if (delete("Hello")) {
        printf("'Hello' deleted\n");
    } else {
        printf("Failed to delete 'Hello'\n");
    }

    return 0;
}