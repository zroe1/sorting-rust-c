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

void count_sort(uint16_t *arr, unsigned int arr_len) {
  uint16_t *count_arr = (uint16_t *)calloc(65536, sizeof(uint16_t));
  for (unsigned int i = 0; i < arr_len; i++) {
    count_arr[arr[i]]++;
  }

  unsigned int output_idx = 0;
  for (unsigned int i = 0; i < 65537; i++) {
    while (count_arr[i] > 0) {
      arr[output_idx++] = i;
      count_arr[i]--;
    }
  }
  free(count_arr);
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
    count_sort(arr, ARRAY_LENGTH);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d,%f\n", ARRAY_LENGTH, time);

    // frees the current array after sorted and time to sort was recoreded
    free(arr);
  }
}
