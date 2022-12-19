#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10

struct node {
    char name[MAX_NAME_LENGTH];
    struct node *before;
};
typedef struct node node_t;


void print_queue(node_t *head) {

    node_t *temporary = head;

    printf("BACK -> ");

    while (temporary != NULL) {
        printf("%s -> ", temporary->name);
        temporary = temporary->before;
    }
    printf("FRONT\n");

}

node_t *create_new_node(char name[MAX_NAME_LENGTH]) {

    node_t *temporary = malloc(sizeof(node_t));
    strcpy(temporary->name, name);
    temporary->before = NULL;
    return temporary;

}

void enqueue(node_t **head, node_t *node_to_enqueue) {

    node_to_enqueue->before = *head;
    *head = node_to_enqueue;
    
}

void dequeue(node_t **head, int number_of_dequeues) {

    node_t *temporary = malloc(sizeof(node_t));
    temporary = head;

    for (int i = 0; i < number_of_dequeues; i++) {

        if (temporary->before == NULL) {
            *head = NULL;
            return;
        }

        while (temporary->before->before != NULL) {
            temporary = temporary->before;
        }

        temporary->before = NULL;
        temporary = head;
    
    }

}

int find_place_in_queue(node_t *head, char name[MAX_NAME_LENGTH]) {

    node_t *temporary = malloc(sizeof(node_t));
    temporary = head;
    int i = 0;
    int length = 0;

    // get the length of the queue
    while (temporary != NULL) {
        length++; // increment length
        temporary = temporary->before; // iterate temporary node
    }
    temporary = head; // set temp node back to the head

    // find matching name
    while (temporary != NULL) {
        if (strcmp(temporary->name, name) == 0) { // if the name matches
            return length - i; // return the length minus the index from head
        }
        temporary = temporary->before; // iterate temporary node
        i++; // iterate counter
    }
    return -1; // if not found, return NULL

}


int main() {

    node_t *head = NULL; // initialize head node as NULL

    printf("\n");

    // create five people and enqueue them
    node_t *hunter = create_new_node("Hunter");
    enqueue(&head, hunter);

    node_t *kayla = create_new_node("Kayla");
    enqueue(&head, kayla);

    node_t *laron = create_new_node("Laron");
    enqueue(&head, laron);

    node_t *heather = create_new_node("Heather");
    enqueue(&head, heather);

    node_t *kim = create_new_node("Kim");
    enqueue(&head, kim);

    printf("\n");

    // output to console
    print_queue(head);

    // search what place in the queue laron is in
    int laronplace = find_place_in_queue(head, "Laron");
    if (laronplace == -1) {
        printf("\nNode not in queue.\n");
    } 
    else {
        printf("\nLaron is in place: %d\n", laronplace);
    }

    printf("\n");

    // dequeue two people from the queue
    dequeue(head,2);
    printf("Two people dequeued.\n\n");

    print_queue(head);

    // search what place in the queue laron is in
    laronplace = find_place_in_queue(head, "Laron");
    if (laronplace == -1) {
        printf("\nNode not in queue.\n");
    } 
    else {
        printf("\nLaron is in place: %d\n", laronplace);
    }

    printf("\n");

    return 0;
}