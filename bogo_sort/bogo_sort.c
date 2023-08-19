#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

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

void shuffle(uint16_t *arr, unsigned int arr_len) {
  unsigned int idx1, idx2;
  for (unsigned int i = 0; i < arr_len; i++) {
    idx1 = rand() % (arr_len);
    idx2 = rand() % (arr_len);
    swap(arr, idx1, idx2);
  }
}

void bogo_sort(uint16_t *arr, unsigned int arr_len) {
  while (check_sorted(arr, arr_len) == 0) {
    shuffle(arr, arr_len);
  }
}

int main() {
  printf("n,t\n");
  for (unsigned int i = 0; i < 12; i++) {
    unsigned int ARRAY_LENGTH = i;
    uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
    srand(time(NULL));

    for (unsigned int j = 0; j < ARRAY_LENGTH; j ++) {
      arr[j] = rand() % (65536);
    }

    clock_t start = clock();
    bogo_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", i, time);
  }
}

