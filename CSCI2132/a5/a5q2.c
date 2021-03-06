/*This will sort the array of x cordinates
and find out the maximal point
Author:Yangfan Chen Date:Mar.7th.2018
**/

#include <stdio.h>

int main(void){
  //for storing the x,y coordinates
  int xcord[10];
  int ycord[10];
  //for entering x,y coordinates
  int x,y;
  int count=0;
  //give data to two arrays accordingly.
  while(scanf("%d %d",&x,&y)==2){
    xcord[count]=x;
    ycord[count]=y;
    count++;
  }

  int i1,k1,j1;
  int k2=0;

  //insertion sort here
  for(i1=1;i1<10;i1++){
    k1=xcord[i1];
    k2=ycord[i1];
    j1=i1-1;

    while(j1>=0&&xcord[j1]>k1){
      xcord[j1+1]=xcord[j1];
      ycord[j1+1]=ycord[j1];
      j1=j1-1;
      
    }
    xcord[j1+1]=k1;
    ycord[j1+1]=k2;
  }
  
  //rightmost is always the maximal
  int indexOfy=9;
  int largestY=ycord[9];
  printf("%d %d\n",xcord[9],ycord[9]);

  //if there is another maximal,print
  for(int i=8;i>=0;i--){
    if(ycord[i]>largestY){
      indexOfy=i;
      largestY=ycord[i];
      printf("%d %d\n",xcord[i],ycord[i]);
    }
  }

  return 0;
}
