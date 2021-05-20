#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "match.h"

char*skip_fields(char *line, int field);
/*Compares two lines of text
 *Parameter: line1: first line to be compared
 *           line2: second line to be compared
 *           field: number of fields to be skipped when comparing
 *Return value: 0 if line1 != line2
                1 if line1 == line2
 */

int match_line(char* line1, char* line2, int field){
  /*if no field is specified*/
  if(field == 0)
    return !strcmp(line1,line2);

  line1=skip_fields(line1,field);
  line2=skip_fields(line2,field);
 
  return !strcmp(line1,line2);
}

/*skip a given number of fields
 *Parameter: line: the line of text
 *           field: number of fields to be skipped when comparing
 *Return value: a pointer that points to the starting position of the first
 *field after the skipped field
 */

char* skip_fields(char* line,int field){
  int field_skipped=1; // indicates how many fields we have skipped

  /*skip fields*/
  while(field_skipped < field){
    if(*line == '\0'){
      break;
    }

    if(*line == ' '){
      while(*(line+1) == ' ')
	line++;
      field_skipped++;
    }
    line++;
  }
  return line;


}
