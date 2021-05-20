
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lines.h"
#include "match.h"

/*Maximum length of a line*/
#define LINE_SIZE 80

int read_line(char line[],int len);

struct line* insert(struct line* text, char* line,int field);

/*Read the lines of input and insert distinct lines into a linked list
 *Parameters: text: head of the list storing the distinct lines of text
 *           field: the number of fields to be skipped when comparing two lines
 *Return value: the head of the linked list created
 */

struct line* read_lines(struct line* text, int field){
  char line[LINE_SIZE];//string storing a line of text
  int line_len;//number of characters read in one line

  while((line_len=read_line(line,LINE_SIZE))>0)
    text=insert(text,line,field);

  if(line_len == -1){
    printf("unable to handle lines longer than 80 characters.\n");
    delete_list(text);
    exit(EXIT_FAILURE);
  }

  return text;
}



/*Insert a line of text into the list of distinct lines of text
 *Parameter: text: head of the sorted list storing the lines of text
 *           line: the line of text to be inserted
 *           field: the number of fields to be skipped when comparing two lines
 *Return value: the head of the linked list
 */

struct line* insert(struct line* text,char * line, int field){
  /*curr, prev are used as current and previous node when search the list
   *new_node points to the new node that stores the new line of text
   */
  struct line *cur,*prev,*new_node;

  /*Iterating through the list to check if the new line of text matches a line stored in the linked list*/

  for(cur=text,prev=NULL;cur!=NULL;prev=cur,cur=cur->next){
    if(match_line(line,cur->start,field)){
      return text;
    }
  }

  /*allcating space for new_node and store the data in it*/

  new_node=malloc(sizeof(struct line));
  if(new_node==NULL){
    printf("Out of memeory.\n");
    delete_list(text);
    exit(EXIT_FAILURE);
  }

  new_node->str=malloc(strlen(line) + 1); // use the actual length of line when allocating
  if(new_node->str == NULL){
    printf("Out of memeory.\n");
    free(new_node);
    delete_list(text);
    exit(EXIT_FAILURE);
  }

  strcpy(new_node->str,line);

  /*Insert the new node into the end of the list*/
  new_node->next=NULL;
  if(prev == NULL)
    return new_node;
  else{
    prev->next=new_node;
    return text;
  }
}

/*Read a line of text from stdin
 *Parameter: line: the string to store the line to be read
 *Return value: the number of characters read
 *              -1 if a line longer than 80 characters is encountered
 */
int read_line(char line[],int len){
  int ch, i = 0;

  /*Read a character until end of line or end of file is reached */
  while((ch=getchar()) != '\n' && ch != EOF){
    /*make sure not to read more than 80 characters per line */
    if(i < len) {
      line[i++] = ch;
    }
    else {
      return -1;
    }
  }
  line[i]='\0';

  return i;
}

/*Output the distinct lines
 *Parameter: text: head of the list storing the lines of input
 *Return value: none
 */
void write_lines(struct line* text) {
  while(text != NULL){
    printf("%s\n", text->str);
    text=text->next;
  }
}


/*free the space occupied by the linked list of lines
 */
void delete_list(struct line* text) {
  struct line* temp; // storing the node to be deallocated;

  /*iterate through the list to be deallocate the nodes*/
  while(text != NULL){
    temp=text;
    text=tex->next;
    free(temp->str);
    free(temp);
  }
}

