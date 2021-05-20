/*This program will compute grade based on input
1-compute the lowest
2-compute the highest
3-compute the average final
**Author: Yangfan Chen Date:March 6th 2018*/
#include <stdio.h>

int main(void){
  int operator;
  int num;//number of students
  
  //displays a message when operator invalid
  scanf("%d",&operator);
  if(operator>3 || operator<1){
    printf("Invalid Operator!\n");
  }

  scanf("%d",&num);
  if(num<0){
    printf("Must be a positive number!\n");
  }

  //use 2-d array to store grade
  int m[num][4];
  float average,lowest,highest;
  //set float variables for low,high,average
  //if all grade is valid, else invalid
  int test=1;
  if(num>0&&operator<=3&&operator>=1){
  for(int i=0;i<num;i++){
    scanf("%d %d %d %d",&m[i][0],&m[i][1],&m[i][2],&m[i][3]);
    if(m[i][0]>100 || m[i][0]<0 || m[i][1]>100
       ||m[i][1]<0 || m[i][2]>100 || m[i][2]<0 ||m[i][3]>100
       ||m[i][3]<0)
      test=0;    
  }
  }


  //int gradeCounter=4*num;
  float total=0;
  if(test==0){
    printf("Invalid grade!\n");
  }

  //compute all if test is true
  if(test){
    lowest=(float)(m[0][1]+m[0][2]+m[0][3]+m[0][0])/4;
    total+=lowest;
    highest=(float)(m[0][0]+m[0][1]+m[0][2]+m[0][3])/4;
    for(int j=1;j<num;j++){
      float stu=(float)(m[j][0]+m[j][1]+m[j][2]+m[j][3])/4;
      if(stu>highest){
	highest=stu;
      }
      else if(lowest>stu){
	lowest=stu;
      }
      total+=stu;
    }
  }
  
  //print based on the operator .
  average=total/num;
  if(operator==1){
    printf("%.2f\n",lowest);
  }
  else if(operator==2){
    printf("%.2f\n",highest);
  }
  else if(operator==3){
    printf("%.2f\n",average);
  }
  return 0; 
}
