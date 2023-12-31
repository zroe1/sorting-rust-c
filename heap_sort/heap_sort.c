#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

unsigned int heap_limit = 10;

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

/* "maxheapify": assumes both children are max heaps and swaps top
node down if necessary to turn that node also into a max heap */
void maxheapify(uint16_t *arr, unsigned int idx) {
  // handles if there are both left and right children
  if ((idx + 1) * 2 < heap_limit) {
    unsigned int left_idx = (idx + 1) * 2 - 1;
    unsigned int right_idx = (idx + 1) * 2;

    if (arr[left_idx] > arr[right_idx]) {
      if (arr[left_idx] > arr[idx]) {
        swap(arr, left_idx, idx);
        maxheapify(arr, left_idx);
      }
    } else {
      if (arr[right_idx] > arr[idx]) {
        swap(arr, right_idx, idx);
        maxheapify(arr, right_idx);
      }
    }
  // handles if there are only left children
  } else if ((idx + 1) * 2 - 1 < heap_limit) {
    unsigned int left_idx = (idx + 1) * 2 - 1;

    if (arr[left_idx] > arr[idx]) {
      swap(arr, left_idx, idx);
      maxheapify(arr, left_idx);
    }
  // handles if there are no children
  } else {
    return;
  }
}

/* turns an array into a maxheap */
void build_heap(uint16_t *arr, unsigned int arr_len) {
  for (int i = arr_len / 2; i >= 0; i--) {
    maxheapify(arr, i);
  }
}

/* sorts an array using the "heap sort" method */
void heap_sort(uint16_t *arr, unsigned int arr_len) {
  if (heap_limit < 2)
    return;

  build_heap(arr, arr_len);
  while (heap_limit >= 2) {
    swap(arr, 0, heap_limit - 1);
    heap_limit--;
    maxheapify(arr, 0);
  }
}

int main() {
  printf("n,t\n");
  for (unsigned int i = 0; i < 300; i++) {
    unsigned int ARRAY_LENGTH = i * 100;
    heap_limit = ARRAY_LENGTH;
    uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
    srand(time(NULL));

    for (unsigned int j = 0; j < ARRAY_LENGTH; j ++) {
      arr[j] = rand() % (65536);
    }

    clock_t start = clock();
    heap_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", ARRAY_LENGTH, time);

    // frees the current array after sorted and time to sort was recoreded
    free(arr);
  }
}

