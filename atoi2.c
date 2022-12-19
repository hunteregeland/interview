#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 10

int myatoi(char *string) {

    int converted_character;
    int result = 0;
    int sign = 1;
    int i = 0;

    // loop through each character
    while (string[i] != '\0') {
        if (string[i] == '-') {
            sign = 0;
            i++;
        } else if (string[i] == '+') {
            i++;
        }
        converted_character = (int)string[i] - 48;
        result += converted_character;
        result *= 10;
        i++;
    }
    result /= 10;
    if (sign == 0) {
        result *= -1;
    }
    return result;

}

int main() {
    printf("\natoi: %d\n", myatoi("-2056"));
}