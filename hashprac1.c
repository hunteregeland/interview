#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

int names = {'a','b','c','d','e'};

typedef struct {
    char initial;
} person;

// create hash table
person * hash_table[TABLE_SIZE];

int hash(char initial) {

    int length = strlen(initial);
    int hash_value = 0;

    for (int i = 0; i < length; i++) {
        hash_value += initial;
        hash_value = (hash_value * initial) % TABLE_SIZE;
    }

    return hash_value;

}

person convert_element_to_person(char array[5], int array_index) {

    person temporary = {.name = names[0]};
    return temporary;

}

int main() {

    for (int i = 0; i < 5; i++) {
        person temporary = convert_element_to_person(names, i);
        printf("name -- %s\n", temporary.name);
    }

    return 0;
}