#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

unsigned int ARRAY_LENGTH = 10;

/* checks if a given array is sorted */
int check_sorted(uint16_t *nums, unsigned int nums_len) {
  // check to prevent unsigned int overflow
  if (nums_len == 0)
    return 1;

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

/* swaps two elements in an array */
void swap(uint16_t *nums, unsigned int idx1, unsigned int idx2) {
  uint16_t temp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = temp;
}

void selection_sort(uint16_t *nums, unsigned int nums_len) {
  for (unsigned int i = 0; i < nums_len; i++) {
    uint16_t current_min = nums[i];
    unsigned int idx_current_min = i;
    for (unsigned int j = i; j < nums_len; j++) {
      if (nums[j] < current_min) {
        current_min = nums[j];
        idx_current_min = j;
      }
    }
    swap(nums, i, idx_current_min);
  }
}

int main () {
  uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
  srand(time(NULL));

  for (unsigned int i = 0; i < ARRAY_LENGTH; i++) {
    arr[i] = rand() % (65536);
  }

  print_arr(arr,ARRAY_LENGTH);
  selection_sort(arr, ARRAY_LENGTH);
  print_arr(arr, ARRAY_LENGTH);

  if (check_sorted(arr, ARRAY_LENGTH))
    printf("Result of sorting check: True (selection sort worked)\n");
  else
    printf("Result of sorting check: False (selection sort failed)\n");
}
