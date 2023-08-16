#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

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

/* Merges two sorted arrays; assumes final arr was malloced with > l1 + l2 
int pointers */
void merge(uint16_t *arr1, unsigned int l1, uint16_t *arr2, unsigned int l2,  
           uint16_t *final_arr) {
  int pointer1 = 0;
  int pointer2 = 0;
  unsigned int rv_pointer = 0;

  while (pointer1 < l1 && pointer2 < l2) {
    if (arr1[pointer1] < arr2[pointer2]) {
      final_arr[rv_pointer++] = arr1[pointer1++];
    } else {
      final_arr[rv_pointer++] = arr2[pointer2++];
    }
  }

  while (pointer1 < l1)
    final_arr[rv_pointer++] = arr1[pointer1++];
  while (pointer2 < l2)
    final_arr[rv_pointer++] = arr2[pointer2++];
}

void merge_sort(uint16_t *arr, unsigned int arr_len) {
  if (arr_len <= 1)
    return;

  unsigned int left_len = arr_len / 2;
  unsigned int right_len = arr_len - left_len;
  uint16_t *left = (uint16_t *)malloc(sizeof(uint16_t) * left_len);
  uint16_t *right = (uint16_t *)malloc(sizeof(uint16_t) * right_len);

  unsigned int left_idx = 0;
  unsigned int right_idx = 0;
  for (unsigned int i = 0; i < arr_len; i++) {
    if (i < left_len) {
      left[left_idx++] = arr[i];
    } else {
      right[right_idx++] = arr[i];
    }
  }

  merge_sort(left, left_len);
  merge_sort(right, right_len);
  merge(left, left_len, right, right_len, arr);
  free(left);
  free(right);
}

int main() {
  uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
  srand(time(NULL));

  for (unsigned int i = 0; i < ARRAY_LENGTH; i++) {
    arr[i] = rand() % (65536);
  }

  print_arr(arr,ARRAY_LENGTH);
  merge_sort(arr, ARRAY_LENGTH);
  print_arr(arr, ARRAY_LENGTH);

  if (check_sorted(arr, ARRAY_LENGTH))
    printf("Result of sorting check: True (merge sort worked)\n");
  else
    printf("Result of sorting check: False (merge sort failed)\n");
}
