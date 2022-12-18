#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_NAME 256

char names[5][256] = {"Hunter", "Laron", "Kim", "Danny", "Alexis"};

typedef struct {
    char name[MAX_NAME];
} person;

// create hash table
person * hash_table[TABLE_SIZE];

int hash(char name[MAX_NAME]) {

    int length = strnlen(name, MAX_NAME);
    int hash_value = 0;

    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % MAX_NAME;
    }

    return hash_value;

}

person convert_element_to_person(char array[5][256], int array_index) {

    person temporary = {.name = array[array_index]};
    return temporary;

}

int main() {

    for (int i = 0; i < 5; i++) {
        person temporary = convert_element_to_person(names, i);
        printf("name -- %s\n", temporary.name);
    }

    return 0;
}