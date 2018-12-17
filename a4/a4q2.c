/**This program will compute the numeric root
 *of a given nonnegative integer
 *Author:Yangfan Chen csci2132
 */
#include <stdio.h>

int main(void){
  int x;
  //x is the input value;
  //y is the sum of its digit.
  int y;
  y=0;
  scanf("%d",&x);
  //back to this statement if y>10
   back:y=x%10;
  int mod;
   mod=10;
  if(x<0){
    printf("The input number must be nonnegative.\n");
  }else{
    //the loop continues if the number is bigger
    while(x>=mod){
	x=x-y;
        y+=x/mod;
        mod*=10;
    }
    //goto back if the sum is bigger than 10
 
  }
  if(y>10){
    x=y;
    y=0;
    goto back;
  }
   printf("%d\n",y);
 
  return 0;
}
