#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ARRAY_LENGTH = 10;

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

/* Merges two sorted arrays; assumes final arr was malloced with > l1 + l2 
int pointers */
void merge(unsigned int *arr1, int l1, unsigned int *arr2, int l2,  
           unsigned int *final_arr) {
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

void merge_sort(unsigned int *arr, unsigned int arr_len) {
  if (arr_len <= 1)
    return;

  unsigned int left_len = arr_len / 2;
  unsigned int right_len = arr_len - left_len;
  unsigned int *left = (unsigned int *)malloc(sizeof(unsigned int) * left_len);
  unsigned int *right = (unsigned int *)malloc(sizeof(unsigned int) * right_len);

  unsigned int left_idx = 0;
  unsigned int right_idx = 0;
  for (unsigned int i = 0; i < arr_len; i++) {
    if (i < left_len) {
      left[left_idx++] = arr[i];
    } else {
      right[right_idx++] = arr[i];
    }
  }
  // printf("len_len: %d\n", left_len);
  // printf("left 0: %d, right 0: %d\n", left[0], right[0]);

  merge_sort(left, left_len);
  merge_sort(right, right_len);
  merge(left, left_len, right, right_len, arr);
  free(left);
  free(right);
}

int main() {
  unsigned int *arr = (unsigned int *)malloc(ARRAY_LENGTH * sizeof(int));
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
