#include <stdlib.h>
#include <stdio.h>

struct node {
    int value; // value of the node
    struct node* next; // pointer to next node in the list
    struct node* prev; // pointer to previous node in the list
};
typedef struct node node_t; // define a type node_t to be a 'node' struct

// function: print the list, starting at the head pointer that we pass in
void printlist(node_t *head) {

    node_t *temporary = head; // declare temporary pointer to start at head pointer

    // loop until temporary is NULL, which means the end of the list
    while (temporary != NULL) {
        printf("%d -> ", temporary->value); // print the value that temporary is pointing to
        temporary = temporary->next; // set temporary to the next node to traverse the list
    }
    printf("\n");

}

// function: create new node
node_t *create_new_node(int value) {

    node_t *result = malloc(sizeof(node_t)); // initialize new node (result) and allocate memory to the result node
    result->value = value; // set the value of the new node to the value passed into the function
    result->next = NULL; // set the next pointer of the new node to NULL
    result->prev = NULL; // set the previous pointer of the new node to NULL
    return result;

}

// function: insert node at the front of the list
// parameters: **head is a pointer to a pointer which allows us to change the head pointer
//             *node_to_insert is the pointer to the node that we want to insert
node_t *insert_at_head(node_t **head, node_t *node_to_insert) {

    node_to_insert->next = *head; // set the node to insert to point to the head pointer
    if (*head != NULL) {
        (*head)->prev = node_to_insert;
    }
    *head = node_to_insert; // set the head pointer to the node to insert
    node_to_insert->prev = NULL;
    return node_to_insert; // return the inserted node;

}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {

    // set the new node's next pointer to the node to insert after's next node
    newnode->next = node_to_insert_after->next;

    if (newnode->next == NULL) {
        newnode->next->prev = node_to_insert_after;
    }
    newnode->prev = node_to_insert_after;

    // set the node to insert after's next pointer to the new node
    node_to_insert_after->next = newnode;

}

void remove_node(node_t **head, node_t *node_to_remove) {

    if (*head == node_to_remove) {
        *head = node_to_remove->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    else {
        node_to_remove->prev->next = node_to_remove->next;
        if (node_to_remove->next != NULL) {
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;

}

int insert_before_node(node_t *head, node_t *node_to_insert_before, node_t *newnode) {

    node_t *current = head; // temp node to start at the head
    node_t *previous; // temp node to store previous

    if (node_to_insert_before == head) {
        printf("Cannot print before head node.\n");
        return 0;
    }
        
    while (current != NULL) { // from 0 until temp is NULL, end of list
        if (current == node_to_insert_before) {
            newnode->next = current;
            previous->next = newnode;
            return 1;
        }
        previous = current;
        current = current->next; // iterates to next node in the list
    }
    return 0;

}

node_t *find_node(node_t *head, int value) {

    node_t *tmp = head; // set temporary node to head pointer
    
    // loop through the whole list
    while (tmp != NULL) { // until the temp node is NULL, which is the end of the list
        if (tmp->value == value) return tmp; // if the value of the node matches the value passed into the function, return the pointer to the node
        tmp = tmp->next; // iterate to the next node if value didn't match
    }
    return NULL; // if the value didn't match any value in the list, return NULL

}

int main() {

    node_t *head = NULL; // head node
    node_t *tmp; // temporary node

    // loop to create a bunch of nodes, adding each number to the front of the list
    for (int i=0; i < 25; i++) {
        tmp = create_new_node(i); // create a new node with value i
        head = insert_at_head(&head, tmp); // insert the temporary node into the front of the list
    }

    // try to find the node with value 13
    tmp = find_node(head, 13); // set tmp equal to the return from find_node, which will either be the node with value 13 or NULL
    printf("found node with value %d.\n", tmp->value); // output to console

    // insert 75 after 13
    insert_after_node(tmp, create_new_node(75));

    // output the list to the console
    printlist(head);

    printf("\n");

    tmp = find_node(head, 18);
    insert_before_node(head, tmp, create_new_node(99));

    // output the list to the console
    printlist(head);

    remove_node(&head, tmp);
    remove_node(&head, head);

    // output the list to the console
    printf("\n");
    printlist(head);


    return 0;
    
}