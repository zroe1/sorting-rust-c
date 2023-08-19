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

/* preforms bubble-sort in place on an array */
void bubble_sort(uint16_t *nums, unsigned int nums_len) {
  for (unsigned int i = 0; i < nums_len; i++) {
    for (unsigned int j = 0; j < nums_len - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums, j, j+1);
      }
    }
  }
}

int main() {
  printf("n,t\n");
  for (unsigned int i = 0; i < 300; i++) {
    unsigned int ARRAY_LENGTH = i * 100;
    uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
    srand(time(NULL));

    for (unsigned int j = 0; j < ARRAY_LENGTH; j ++) {
      arr[j] = rand() % (65536);
    }

    clock_t start = clock();
    bubble_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", ARRAY_LENGTH, time);
  }
}
