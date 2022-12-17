#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *below;
};
typedef struct node node_t;


void print_stack(node_t *head) {

    node_t *temporary = head;

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->below;
    }
    printf("\n");

}

node_t *create_new_node(int value) {

    node_t *temporary = malloc(sizeof(node_t));
    temporary->value = value;
    temporary->below = NULL;
    return temporary;

}

void push_to_stack(node_t **head, node_t *node_to_push) {

    node_to_push->below = *head; // set the node below in the stack to the current head
    *head = node_to_push; // move the head node up to the new node

}

node_t *pop_from_stack(node_t *head) {

    return head->below; // just return the node below the head

}

int find_node(node_t *head, int value) {

    node_t *temporary = head; // set temporary node equal to the current head
    int counter = 0; // counter initialized as 0

    // loop until bottom of stack
    while(temporary != NULL) {
        if (temporary->value == value) { // if the value of the node matches the value passed into the function
            return counter; // return the index it was found at
        }
        counter++; // iterate counter
        temporary = temporary->below; // iterate to below node
    }
    return -1; // if node is not found return -1

}


int main() {

    node_t *head = NULL; // initialize head node as NULL
    node_t *temporary;
    int found_node_index;

    printf("\n");

    for (int i = 0; i < 10; i++) {
        temporary = create_new_node(i+1);
        push_to_stack(&head, temporary);
    }

    // output to console
    print_stack(head);

    // find node 7 and print it's index in the stack
    found_node_index = find_node(head, 7);
    if (found_node_index != -1) {
        printf("Found node at index: %d\n\n", found_node_index);
    } else {
        printf("Node not found.\n");
    }

    // pop the top item from the stack
    head = pop_from_stack(head);

    // output to console
    print_stack(head);

    // find node 7 and print it's index in the stack
    found_node_index = find_node(head, 7);
    if (found_node_index != -1) {
        printf("Found node at index: %d\n\n", found_node_index);
    } else {
        printf("Node not found.\n");
    }

    // pop six nodes off the stack
    for (int i = 0; i < 6; i++) {
        head = pop_from_stack(head);
    }

    // output to console
    print_stack(head);

    // find node 7 and print it's index in the stack
    found_node_index = find_node(head, 7);
    if (found_node_index != -1) {
        printf("Found node at index: %d\n\n", found_node_index);
    } else {
        printf("Node not found.\n");
    }

    printf("\n");
    return 0;
}