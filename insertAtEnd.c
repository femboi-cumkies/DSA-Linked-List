#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert_at_end (Node *head, int value) {
    Node *ptr, *newNode;     // ptr to act as counter inside while; newNode is THE new node
    ptr = head;              // initialize head to ptr

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;   // update data from "value"
    newNode->next = NULL;    // set next to NULL to indicate end of list

    while(ptr->next != NULL) {
        ptr = ptr->next;     // so long as while() is true, point to the next link
    }
    ptr->next = newNode;     // if while() is false, set the last link to point at newNode
}

int main() {

    // ignore this 
    Node *head = malloc(sizeof(Node));
    head->data = 25;
    head->next = NULL;

    Node *current = malloc(sizeof(Node));
    current->data = 40;
    current->next = NULL;
    head->next = current;

    current = malloc(sizeof(Node));
    current->data = 65;
    current->next = NULL;

    head->next->next = current;

    int value;

    printf("Add a New Node at the end of your linked list \n\n");
    printf("Data for New Node; ");
    scanf("%d", &value);

    insert_at_end(head, value);

    return 0;
}
