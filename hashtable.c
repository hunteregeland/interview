#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256 // max length of a name string
#define TABLE_SIZE 10 // max table size
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL) // flag for a deleted node

// define hash table entry struct
typedef struct {
    char name[MAX_NAME]; // name of person
    int age; // person's age
} person;

// create a hash table: an array of people
person * hash_table[TABLE_SIZE];

// create our hash function [0(length of the name)]
unsigned int hash(char *name) {

    int length = strnlen(name, MAX_NAME); // determine length of the name up to max length
    unsigned int hash_value = 0; // initialize hash value as 0

    // loop from 0 to the length of the name
    // this is the actual function
    // does not need to be exactly this, hash functions can change
    for (int i=0; i < length; i++) {
        hash_value += name[i]; // add the character's ascii value to the hash value
        hash_value = (hash_value * name[i]) % TABLE_SIZE; // multiply hash value by character ascii value, "% TABLE_SIZE" to keep it inside the table size
    }
    return hash_value; // return the hash value for the name

}

// initialize the hash table [0(TABLE_SIZE)]
void init_hash_table() {

    // loop from 0 to the max table size
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL; // create each element as NULL so it is an empty hash table
    }

}

// print out the hash table [0(TABLE_SIZE)]
void print_table() {

    printf("Start\n"); // console output that we've started outputting the table

    // loop from 0 to the max table size
    for (int i=0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) { // if the hash table element is NULL
            printf("\t%i\t---\n", i); // console output empty
        }
        else if (hash_table[i] == DELETED_NODE) { // if the hash table element is a deleted node
            printf("\t%i\t---<deleted>\n", i); // console output deleted
        }
        else { // if the hash table element has a name
            printf("\t%i\t%s\n", i, hash_table[i]->name); // console output the name
        }
    }

    printf("End\n"); // console output that we've stopped outputting the table

}

// insert a new person into the hash table [0(TABLE_SIZE)]
bool hash_table_insert(person *p) {

    if (p == NULL) return false; // if null pointer return false
    int index = hash(p->name); // define index as the hashed value of the person's name

    // loop from 0 to the max table size
    // this loop is for avoiding storing a new person at an occupied index
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE; // define try as i + index inside the max table size
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) { // if the element is NULL or a deleted node
            hash_table[try] = p; // insert this person into this element
            return true; // person inserted into table
        }
    }
    return false; // person not inserted into table

}

// find a person in the table by their name [0(TABLE_SIZE)]
person *hash_table_lookup(char *name) {

    int index = hash(name); // determine the index by hashing the name

    // loop from 0 to max table size
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE; // try variable first tries its own node, then if its NULL or deleted, checks the next iteratively
        if (hash_table[try] == NULL) { // if the element is NULL
            return false; // element is not in the hash table
        }
        if (hash_table[try] == DELETED_NODE) continue; // if the element is a deleted node, check next
        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) { // if the element is not NULL and the name matches
            return hash_table[try]; // return the person
        }
    }
    return NULL; // name was not in the hash table

}

// delete a person from the hash table [0(TABLE_SIZE)]
person *hash_table_delete(char *name) {

    int index = hash(name); // determine the index by hashing the name

    // loop from 0 to max table size
    for (int i=0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE; // try variable first tries its own node, then if its NULL or deleted, checks the next iteratively
        if (hash_table[try] == NULL) return NULL; // if element is NULL, there's nothing to delete
        if (hash_table[try] == DELETED_NODE) continue; // if the element is a deleted node, check the next
        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) { // if the node is not NULL and the name matches
            person *tmp = hash_table[try]; // set temporary person to the current element in the hash table
            hash_table[try] = DELETED_NODE; // set the element in the hash table to a deleted node
            return hash_table[try]; // return the person
        }
    }
    return NULL; // name was not in the table

}

int main() {

    // initialze the hash table
    init_hash_table();

    // print out the empty table
    print_table();

    // initialize ten people with names and ages
    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=54};
    person edna = {.name="Edna", .age=15};
    person maren = {.name="Maren", .age=25};
    person eliza = {.name="Eliza", .age=34};
    person robert = {.name="Robert", .age=1};
    person jane = {.name="Jane", .age=75};

    // insert each of the ten people into the hash table
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    // print the newly populated table
    print_table();

    // let's check if we can find the names "Mpho" and "George"
    // create a temporary person and set it equal to Mpho
    person *tmp = hash_table_lookup("Mpho");

    if (tmp == NULL) { // if lookup returned NULL
        printf("Not found!\n"); // console output not found
    }
    else { // if lookup returned a name
        printf("Found %s.\n", tmp->name); // console output found {name}
    }

    tmp = hash_table_lookup("George"); // set temp = lookup return with name George

    if (tmp == NULL) { // if lookup returned NULL
        printf("Not found!\n"); // console output not found
    }
    else { // if lookup returned a name
        printf("Found %s.\n", tmp->name); // console output found {name}
    }

    // delete Mpho from the hash table
    hash_table_delete("Mpho"); // use delete function to delete element with name "Mpho"
    tmp = hash_table_lookup("Mpho"); // set temp = lookup return with name Mpho

    // lookup Mpho in the hash table to ensure the element was deleted
    if (tmp == NULL) { // if lookup returned NULL
        printf("Not found!\n"); // console output not found
    }
    else { // if lookup returned a name
        printf("Found %s.\n", tmp->name); // console output found {name}
    }

    print_table(); // print the final table with the deleted node

    return 0;
}
