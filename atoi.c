#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

int atoiButByHunter(char string[MAX_LENGTH]) {
  // get each character
  char character;
  int result = 0;
  int sign = 1;
  int i=0;
  while (string[i] != '\0') {
    if (string[i] == '-') {
      sign = 0;
      i++;
    }

    // cast as integer
    int intchar;
    character = string[i];
    intchar = (int)character;
    result += intchar-48;

    //  multiply by 10 and add to result
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

  int atoi = atoiButByHunter("123456");
  printf("\n%d\n", atoi);

}
