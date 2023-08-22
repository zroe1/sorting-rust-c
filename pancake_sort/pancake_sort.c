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

/* reverses the numbers between left and right inclusive */
void reverse_arr_section(uint16_t *arr, unsigned int left, unsigned int right) {
  for (unsigned int i = 0; i <= (right - left) / 2; i++) {
    swap(arr, left + i, right - i);
  }
}

/* finds the index of the max number between left and right inclusive */
unsigned int find_idx_of_max_in_section(uint16_t *arr, unsigned int left, 
                                        unsigned int right) {
  unsigned int current_max = 0;
  unsigned int current_max_idx = 0;
  for (unsigned int i = left; i < right + 1; i++) {
    if (arr[i] >= current_max) {
      current_max = arr[i];
      current_max_idx = i;
    }
  }
  return current_max_idx;
}


void pancake_sort(uint16_t *arr, unsigned int arr_len) {
  int last_unsorted = arr_len - 1;

  while (last_unsorted >= 0) {
    unsigned int current_max = find_idx_of_max_in_section(arr, 0, last_unsorted);

    reverse_arr_section(arr, current_max, last_unsorted);
    last_unsorted--;
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
    pancake_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", ARRAY_LENGTH, time);

    // frees the current array after sorted and time to sort was recoreded
    free(arr);
  }
}
