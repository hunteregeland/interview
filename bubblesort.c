#include <stdio.h>

// To execute C, please define "int main()"
int temporary;
int sorted = 0;

void bubbleSort(int array[5], int array_size) {

  // loop through size-1 times
  for (int i = 0; i < array_size-1; i++) {
    // loop through every element that's not sorted
    for (int j = 0; j < array_size-i-1; j++) {
      if (array[j] > array[j+1]) {
        temporary = array[j+1];
        array[j+1] = array[j];
        array[j] = temporary;
      }
    }
  }

}

int main() {
  
  int nums[5] = {3, 5, 4, 1, 2};
  int array_size = sizeof(nums) / sizeof(nums[0]);

  printf("array size: %d\n", array_size);

  printf("unsorted: ");
  printf("[ ");
  for (int i = 0; i < array_size; i++) {
    printf("%d ", nums[i]);
  }
  printf("]\n");

  bubbleSort(nums, array_size);

  printf("sorted:   ");
  printf("[ ");
  for (int i = 0; i < array_size; i++) {
    printf("%d ", nums[i]);
  }
  printf("]\n");

  return 0;

}
