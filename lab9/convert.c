#include<stdio.h>
#include<ctype.h>

int main(int argc,char *argv[]){
  FILE *fp;
  int ch;
  if(argc!=2){
    fprintf(stderr,"cusage:cntchar file.\n");
    return 1;
  }
  if((fp=fopen(argv[1],"r"))==NULL){
    fprintf(stderr,"Can't open %s\n",argv[1]);
    return 1;
  }
  while((ch=getc(fp))!=EOF){
    putchar(toupper(ch));
  }
  fclose(fp);
  return 0;




}
