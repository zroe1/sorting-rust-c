#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ARRAY_LENGTH = 10;

/* checks if a given array is sorted */
int check_sorted(uint16_t *nums, unsigned int nums_len) {
  for (unsigned int i = 0; i < nums_len - 1; i++) {
    if (nums[i] > nums[i + 1]) {
      return 0;
    }
  }
  return 1;
}

/* prints an array in human-readable output to standard output */
void print_arr(uint16_t *nums, unsigned int nums_len) {
  printf("[\n");
  for (unsigned int i = 0; i < nums_len; i++) {
    printf("  %d", nums[i]);
    if (i != nums_len - 1) {
      putchar(',');
    }
    putchar('\n');
  }
  printf("]\n");
}

/* insertion sort on an array of unsigned ints */
void insertion_sort(uint16_t *nums, unsigned int len_nums) {
  for (unsigned int i = 1; i < len_nums; i++) {
    unsigned int current_idx = i;
    uint16_t temp = nums[i];
    while (current_idx > 0 && temp < nums[current_idx - 1]) {
      nums[current_idx] = nums[current_idx - 1];
      current_idx--;
    }
    nums[current_idx] = temp;
  }
}

int main() {
  uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
  srand(time(NULL));

  for (unsigned int i = 0; i < ARRAY_LENGTH; i++) {
    arr[i] = rand() % (65536);
  }

  print_arr(arr,ARRAY_LENGTH);
  insertion_sort(arr, ARRAY_LENGTH);
  print_arr(arr, ARRAY_LENGTH);

  if (check_sorted(arr, ARRAY_LENGTH))
    printf("Result of sorting check: True (insertion sort worked)\n");
  else
    printf("Result of sorting check: False (insertion sort failed)\n");
}
