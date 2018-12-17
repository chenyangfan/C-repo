#include <stdio.h>

int main(void){
  int i,j,days,start;
  printf("Enter number of days in month\n");
  scanf("%d",&days);
  printf("Enter starting day of the week(1=Sun,7=Sat\n");
  scanf("%d",&start);
  printf("Sun Mon Tue Wed Thu Fri Sat \n");
  for(j=1;j<=start;j++){
    printf(" ");
  }
  for(i=1;i<=days;i++){
    printf("%3d",i);
    if((i==7) ||( i==14) || (i==21) || (i=28)){
      printf("\n");
    }
    else if (i<=days){
      printf(" ");
  }
  }
  printf("\n");
  return 0;

}
