#include <stdio.h>

int main(void){
  int district,digit3,digit4;
  printf("Enter a telephone number[(xxx)xxx-xxxx]\n");
  scanf("(%d)%d-%d",&district,&digit3,&digit4);
  printf("The number is%d.%d.%d",district,digit3,digit4);
  return 0;

}
