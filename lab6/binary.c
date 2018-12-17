#include <stdio.h>

#define LEN 10
#define NOT_FOUND -1

int binary_search(int array[], int len, int key);

int main(void) {
  int array[LEN] = {3, 12, 21, 23, 34, 37, 52, 88, 89, 99};
  int key, position;

  printf("Enter a positive number to be searched for: ");
  if (!(scanf("%d", &key) > 0)) {
    printf("Please enter a positive integer.\n");
    return 1;
  }

  position = binary_search(array, LEN, key);

  if (position != NOT_FOUND) 
    printf("%d is at location %d.\n", key, position+1);
  else
    printf("Not found.\n");

  return 0;
}


int binary_search(int array[], int len, int key) {
  int lower, upper, middle;

  lower = 0;
  upper = LEN - 1;
  middle = (lower + upper) / 2;

  while (array[middle] != key && lower <= upper) {
    if (key < array[middle])
      upper = middle - 1;
    else
      lower = middle + 1;

    middle = (lower + upper) / 2;
  }

  if (array[middle] == key)
    return middle ;
  else
    return NOT_FOUND;
}
