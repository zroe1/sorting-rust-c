#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* checks if a given array is sorted */
int check_sorted(unsigned int *nums, unsigned int nums_len) {
  for (unsigned int i = 0; i < nums_len - 1; i++) {
    if (nums[i] > nums[i + 1]) {
      return 0;
    }
  }
  return 1;
}

/* prints an array in human-readable output to standard output */
void print_arr(unsigned int *nums, unsigned int nums_len) {
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
void swap(unsigned int *nums, unsigned int idx1, unsigned int idx2) {
  unsigned int temp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = temp;
}

void selection_sort(unsigned int *nums, unsigned int nums_len) {
  for (unsigned int i = 0; i < nums_len; i++) {
    unsigned int current_min = nums[i];
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
  unsigned int *arr = (unsigned int *)malloc(10 * sizeof(int));
  srand(time(NULL));

  for (unsigned int i = 0; i < 10; i++) {
    arr[i] = rand();
  }

  print_arr(arr, 10);
  selection_sort(arr, 10);
  print_arr(arr, 10);

  if (check_sorted(arr, 10))
    printf("Result of sorting check: True (selection sort worked)\n");
  else
    printf("Result of sorting check: False (selection sort failed)\n");
}
