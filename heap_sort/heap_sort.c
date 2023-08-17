#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

unsigned int ARRAY_LENGTH = 10;
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

/* returns the left element at a given index */
unsigned int find_left_child(unsigned int idx) {
  return (idx + 1) * 2 - 1;
}

/* returns the right element at a given index */
unsigned int find_right_child(unsigned int idx) {
  return (idx + 1) * 2;
}

/* "maxheapify": assumes both children are max heaps and swaps top
node down if necessary to turn that node also into a max heap */
void swap_down(uint16_t *arr, unsigned int idx) {
  unsigned int left = find_left_child(idx);
  unsigned int right = find_right_child(idx);

  if (left < heap_limit && right < heap_limit) {
    if (arr[left] > arr[right]) {
      if (arr[left] > arr[idx]) {    
        swap(arr, left, idx);
        swap_down(arr, left);
      }
    } else {
      if (arr[right] > arr[idx]) {    
        swap(arr, right, idx);
        swap_down(arr, right);
      }
    }
    return;
  }

  // if here, either left = heap limit - 1 or left and right < heap_limit
  if (left < heap_limit) {
    if (arr[left] > arr[idx]) {    
      swap(arr, left, idx);
      swap_down(arr, left);
    }
  }
}

/* turns an array into a maxheap */
void build_heap(uint16_t *arr, unsigned int arr_len) {
  for (int i = arr_len / 2; i >= 0; i--) {
    swap_down(arr, i);
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
    swap_down(arr, 0);
  }
}

int main() {
  uint16_t *arr = (uint16_t *)malloc(ARRAY_LENGTH * sizeof(uint16_t));
  srand(time(NULL));

  for (unsigned int i = 0; i < ARRAY_LENGTH; i++) {
    arr[i] = rand() % (65536);
  }

  print_arr(arr,ARRAY_LENGTH);
  heap_sort(arr, ARRAY_LENGTH);
  print_arr(arr, ARRAY_LENGTH);

  
  if (check_sorted(arr, ARRAY_LENGTH))
    printf("Result of sorting check: True (heap sort worked)\n");
  else
    printf("Result of sorting check: False (heap sort failed)\n");
}

