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

/* implements count sort on the digit extracted at the "divisor" place */
uint16_t *count_sort(uint16_t * arr, unsigned int arr_len, unsigned int divisor) {
  uint16_t *count_arr = calloc(10, sizeof(uint16_t));

  for (unsigned int i = 0; i < arr_len; i++) {
    unsigned int count_arr_idx = (arr[i] / divisor) % 10;
    count_arr[count_arr_idx]++;
  }

  for (unsigned int i = 1; i < 10; i++) {
    count_arr[i] += count_arr[i - 1];
  }
   
  uint16_t *output = (uint16_t *)malloc(sizeof(uint16_t) * arr_len); 
  for (int i = arr_len - 1; i >= 0; i--) {
    unsigned int count_idx = (arr[i] / divisor) % 10;
    unsigned int output_idx = count_arr[count_idx] - 1;
    count_arr[count_idx]--;
    output[output_idx] = arr[i];
  }

  return output;
}

/* implements radix sort on an array of integers */
uint16_t *radix_sort(uint16_t *arr, unsigned int arr_len) {
  unsigned int divisor = 1;
  while (divisor <= 10000) {
    arr = count_sort(arr, arr_len, divisor);
    divisor *= 10;
  }
  return arr;
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
    arr = radix_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", ARRAY_LENGTH, time);
    free(arr);
  }
  
}
