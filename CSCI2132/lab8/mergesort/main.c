#include <stdio.h>
#include "mergesort.h"
int main(void) {
  int len;
  
  printf("Enter the length of the array: ");
  scanf("%d", &len);

  int array[len];

  printf("Enter %d integers:\n",len);

  for(int i=0; i < len; i++)
    scanf("%d",&array[i]);

  mergesort(array, 0 , len -1);

  printf("The sorted array is : \n");
  for(int i = 0; i < len; i++) {
    printf("%d",array[i]);
    if(i < len -  1)
      printf(" ");

  }
 
  printf("\n");

  return 0;
}
