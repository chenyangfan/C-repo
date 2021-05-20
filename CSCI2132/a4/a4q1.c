/**This program will do calculators on 
 *addition,multiplication,and subtraction
 *and will also do some error handling
 *Author: Yangfan Chen csci2132
 */
#include <stdio.h>

int main(void){
  int option,left1,left2,right1,right2;
  int result1,result2,result3;
  //first rows of integer corresponds to input format
  //second column refers to output format
  scanf("%d %d %d %d %d",&option,&left1,&left2,&right1,&right2);
  //option1 refers to addtion
  // option 2 refers to subtraction
  //option 3 refers to multiplication
  //last "else" statements handles invalid opreations
  if(option==1){
    result1=0;
    result2=left1+right1;
    result3=left2+right2;
  }else if(option==2){
    result1=0;
    result2=left1-right1;
    result3=left2-right2;
  }else if(option==3){
    result1=left1*right1;
    result2=left1*right2+left2*right1;
    result3=left2*right2;
  }else{
    printf("Invalid operation.\n");
  }
  //print function if everthing is valid.
  if(option==1 || option ==2 || option==3){
    printf("%d %d %d\n",result1,result2,result3);
  }
  
  return 0;
}
