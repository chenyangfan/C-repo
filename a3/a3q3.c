/*This program will convert file permisson like rwx-wx-rwx
 *to octal using binary for every group.
 *ex: 1 1 1 1 1 1 1 1 1 converts to 7 7 7
 *Author:Yangfan Chen
 */
#include <stdio.h>

int main(void){
  //u represents user permisson with 1 being read
  //2 being write,3 being execute.g refers to group,o refers to others
  int u1,u2,u3,g1,g2,g3,o1,o2,o3;
  //3 octal numbers
  int user,group,other;
  scanf("%d %d %d %d %d %d %d %d %d",&u1,&u2,&u3,&g1,&g2,&g3,&o1,&o2,&o3);
  //first digit*4+second digit*2+third digit*1
  user=u1*4+u2*2+u3*1;
  group=g1*4+g2*2+g3*1;
  other=o1*4+o2*2+o3*1;
  printf("%d %d %d\n",user,group,other);
  return 0;
}
